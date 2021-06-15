#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <UI/VeriFormlari/krgyenikargoekle.h>
#include <UI/VeriFormlari/krgsubebilgileriekle.h>
#include <UI/ListeFormlari/krgsubelistesi.h>
#include <UI/ListeFormlari/krgkargolistesi.h>
#include <UI/ListeFormlari/krgkayitlimusteriler.h>
#include <Veri/krggenelveriyoneticisi.h>
#include <Veri/VeriListesi/krgkargobilgileri.h>

#include <QDir>
#include <QFile>
#include <QDataStream>
#include <QStandardPaths>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString dosya_yolu = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    QDir dosya_klasoru(dosya_yolu);

    if (dosya_klasoru.exists("KargoOtomasyonu.krg")) {
        QFile dosya(dosya_yolu + "/KargoOtomasyonu.krg");

        if (dosya.open(QIODevice::ReadOnly)) {
            QDataStream oku(&dosya);

            oku >> KRGGenelVeriYoneticisi::db();

            dosya.close();
        }
    }
    ara();
}

MainWindow::~MainWindow()
{
    delete ui;

    QString dosya_yolu = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);

    QFile dosya(dosya_yolu + "/KargoOtomasyonu.krg");
    if (dosya.open(QIODevice::WriteOnly)) {
        QDataStream yaz(&dosya);

        yaz << KRGGenelVeriYoneticisi::db();

        dosya.close();
    }
}


void MainWindow::on_btnKargoEkle_clicked()
{
    KRGYeniKargoEkle form;

    auto veriAlici = KRGGenelVeriYoneticisi::db().getAliciBilgileri().yeni();
    auto veriGonderici = KRGGenelVeriYoneticisi::db().getGondericiBilgileri().yeni();
    auto veriKargo = KRGGenelVeriYoneticisi::db().getKargoBilgileri().yeni();

    qDebug() << veriAlici->getId();

    form.setVeriAlici(veriAlici);
    form.setVeriGonderici(veriGonderici);
    form.setVeriKargo(veriKargo);

    if (form.exec() == QDialog::Accepted) {
        form.getVeriAlici();
        form.getVeriGonderici();
        form.getVeriKargo();
        KRGGenelVeriYoneticisi::db().getAliciBilgileri().ekle(veriAlici);
        KRGGenelVeriYoneticisi::db().getGondericiBilgileri().ekle(veriGonderici);
        KRGGenelVeriYoneticisi::db().getKargoBilgileri().ekle(veriKargo);   
    }
    listeGuncelle();

}


void MainWindow::on_btnKargoAra_clicked()
{
    KRGKargoListesi form;
    form.exec();
}


void MainWindow::on_btnSubeEkle_clicked()
{
    KRGSubeBilgileriEkle form;
    auto veri = KRGGenelVeriYoneticisi::db().getSubeBilgileri().yeni();

    form.setVeri(veri);

    if (form.exec() == QDialog::Accepted) {
        form.getVeri();
        KRGGenelVeriYoneticisi::db().getSubeBilgileri().ekle(veri);
    }
    listeGuncelle();
}


void MainWindow::on_btnSubeAra_clicked()
{
    KRGSubeListesi form;
    form.exec();
}


void MainWindow::on_btnKayitliMusteriler_clicked()
{
    KRGKayitliMusteriler form;
    form.exec();
}

void MainWindow::listeGuncelle()
{
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(liste.length());
    ui->tableWidget->setColumnCount(7);

    QStringList basliklar;
    basliklar <<tr("ID") << tr("Tarih") << tr("Ödeme Türü") << tr("Desi") << tr("Tutar")<< tr("Gönderen Şube") << tr("Alıcı Şube")  ;
    ui->tableWidget->setHorizontalHeaderLabels(basliklar);


    for (int i = 0; i < liste.length(); i++) {


        QTableWidgetItem *hucre = new QTableWidgetItem();
        hucre->setText(tr("%1").arg(liste[i]->getId()));
        ui->tableWidget->setItem(i,0,hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(liste[i]->getKargoTarihi().toString("yyyy.MM.dd"));
        ui->tableWidget->setItem(i,1,hucre);

        hucre = new QTableWidgetItem();
        switch (liste[i]->getOdemeTuru()) {
        case OTGondericiOdemeli:
            hucre->setText("Gönderici Ödemeli");
            break;
        default:
            hucre->setText("Alıcı Ödemeli");
        }
        ui->tableWidget->setItem(i, 2, hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(tr("%1").arg(liste[i]->getKargoDesi()));
        ui->tableWidget->setItem(i,3,hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(tr("%1").arg(liste[i]->getKargoUcreti()));
        ui->tableWidget->setItem(i,4,hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(liste[i]->getGonderenSube());
        ui->tableWidget->setItem(i,5,hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(liste[i]->getAliciSube());
        ui->tableWidget->setItem(i,6,hucre);

    }
}

void MainWindow::ara()
{
    liste = KRGGenelVeriYoneticisi::db().getKargoBilgileri().tumunuBul([](KRGKargoBilgileriYoneticisi::Ptr p)->bool {return true;});
    listeGuncelle();
}
