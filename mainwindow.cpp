#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <UI/VeriFormlari/krgyenikargoekle.h>
#include <UI/VeriFormlari/krgsubebilgileriekle.h>
#include <UI/ListeFormlari/krgsubelistesi.h>
#include <UI/ListeFormlari/krgkargolistesi.h>
#include <UI/ListeFormlari/krgkayitlimusteriler.h>
#include <Veri/krggenelveriyoneticisi.h>

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
    auto veriKargo = KRGGenelVeriYoneticisi::db().getKargoBilgileri().yeni();
    auto veriAlici = KRGGenelVeriYoneticisi::db().getAliciBilgileri().yeni();
    auto veriGonderici = KRGGenelVeriYoneticisi::db().getGondericiBilgileri().yeni();

    form.setVeriKargo(veriKargo);
    form.setVeriAlici(veriAlici);
    form.setVeriGonderici(veriGonderici);

    if (form.exec() == QDialog::Accepted) {
        form.getVeriKargo();
        form.getVeriAlici();
        form.getVeriGonderici();
        KRGGenelVeriYoneticisi::db().getKargoBilgileri().ekle(veriKargo);
        KRGGenelVeriYoneticisi::db().getAliciBilgileri().ekle(veriAlici);
        KRGGenelVeriYoneticisi::db().getGondericiBilgileri().ekle(veriGonderici);
    }

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
