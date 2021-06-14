#include "krgkargolistesi.h"
#include "ui_krgkargolistesi.h"

#include <Veri/VeriListesi/krgkargobilgileri.h>
#include <Veri/krggenelveriyoneticisi.h>

#include<QStringList>
#include <QTableWidgetItem>
#include <QDebug>


KRGKargoListesi::KRGKargoListesi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KRGKargoListesi)
{
    ui->setupUi(this);
    ara();
}

KRGKargoListesi::~KRGKargoListesi()
{
    delete ui;
}

void KRGKargoListesi::listeGuncelle()
{
    ui->tableWidgetKargoListesi->clear();
    ui->tableWidgetKargoListesi->setRowCount(listeKargo.length());
    ui->tableWidgetKargoListesi->setColumnCount(12);

    QStringList basliklar;
    basliklar <<tr("ID") << tr("Tarih") << tr("Ödeme Türü") << tr("En") << tr("Boy") << tr("Yükseklik") << tr("Desi") << tr("Gönderen Şube") << tr("Alıcı Şube") << tr("Gönderen Müşteri Id") << tr("Alan Müşteri Id")<< tr("Tutar");
    ui->tableWidgetKargoListesi->setHorizontalHeaderLabels(basliklar);


    for (int i = 0; i < listeKargo.length(); i++) {


        QTableWidgetItem *hucre = new QTableWidgetItem();
        hucre->setText(tr("%1").arg(listeKargo[i]->getId()));
        ui->tableWidgetKargoListesi->setItem(i,0,hucre);


        hucre = new QTableWidgetItem();
        hucre->setText(listeKargo[i]->getKargoTarihi().toString("yyyy.MM.dd"));
        ui->tableWidgetKargoListesi->setItem(i,1,hucre);


        hucre = new QTableWidgetItem();
        switch (listeKargo[i]->getOdemeTuru()) {
        case OTGondericiOdemeli:
            hucre->setText("Gönderici Ödemeli");
            break;
        default:
            hucre->setText("Alıcı Ödemeli");
        }
        ui->tableWidgetKargoListesi->setItem(i, 2, hucre);



        hucre = new QTableWidgetItem();
        hucre->setText(tr("%1").arg(listeKargo[i]->getKargoEn()));
        ui->tableWidgetKargoListesi->setItem(i,3,hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(tr("%1").arg(listeKargo[i]->getKargoBoy()));
        ui->tableWidgetKargoListesi->setItem(i,4,hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(tr("%1").arg(listeKargo[i]->getKargoYukseklik()));
        ui->tableWidgetKargoListesi->setItem(i,5,hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(tr("%1").arg(listeKargo[i]->getKargoDesi()));
        ui->tableWidgetKargoListesi->setItem(i,6,hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(listeKargo[i]->getGonderenSube());
        ui->tableWidgetKargoListesi->setItem(i,7,hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(listeKargo[i]->getAliciSube());
        ui->tableWidgetKargoListesi->setItem(i,8,hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(tr("%1").arg(listeKargo[i]->getGondericiId()));
        ui->tableWidgetKargoListesi->setItem(i,9,hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(tr("%1").arg(listeKargo[i]->getAliciId()));
        ui->tableWidgetKargoListesi->setItem(i,10,hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(tr("%1").arg(listeKargo[i]->getKargoUcreti()));
        ui->tableWidgetKargoListesi->setItem(i,11,hucre);

    }

}



/*
 * Lineer Arama Algoritması yazıldı.
 * Vakit az diye diğer algoritmalardan vazgeçildi.
 *
 */



void KRGKargoListesi::ara()
{

    auto ekran = this->ui;
    listeKargo = KRGGenelVeriYoneticisi::db().getKargoBilgileri().tumunuBul(
        [ekran](KRGKargoBilgileriYoneticisi::Ptr veri)->bool {
            if(ekran->lineEditKargoIdGiriniz->text()==""){
                return true;
            }
            auto iter = QString::number(veri->getId());
            if (ekran->lineEditKargoIdGiriniz->text()!=""){
                if(iter != ekran->lineEditKargoIdGiriniz->text()){
                    return false;
                }
            }
            return true;
        });
    listeGuncelle();
}

void KRGKargoListesi::on_pushButtonAra_clicked()
{
    ara();
}

