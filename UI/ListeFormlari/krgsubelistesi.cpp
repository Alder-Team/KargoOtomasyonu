#include "krgsubelistesi.h"
#include "ui_krgsubelistesi.h"

#include <Veri/VeriListesi/krgkargobilgileri.h>
#include <Veri/krggenelveriyoneticisi.h>

#include<QStringList>
#include <QTableWidgetItem>
#include <QDebug>


KRGSubeListesi::KRGSubeListesi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KRGSubeListesi)
{
    ui->setupUi(this);
    ara();
}

KRGSubeListesi::~KRGSubeListesi()
{
    delete ui;
}

void KRGSubeListesi::listeGuncelle()
{
    ui->tableWidgetSubeListesi->clear();
    ui->tableWidgetSubeListesi->setRowCount(listeSube.length());
    ui->tableWidgetSubeListesi->setColumnCount(5);

    QStringList basliklar;
    basliklar << tr("Şube ID") << tr("Şube Adı") << tr("Şube Yetkilisi") << tr("Şube Telefon Numarası") << tr("Şube Adresi"); //Her birisi arasındaki uzaklık olayını anlamadım o yüzden eklemiyorum. Saygılar -Gülnur
    ui->tableWidgetSubeListesi->setHorizontalHeaderLabels(basliklar);


    for (int i = 0; i < listeSube.length(); i++){

        QTableWidgetItem *hucre = new QTableWidgetItem();
        hucre->setText(tr("%1").arg(listeSube[i]->getId()));
        ui->tableWidgetSubeListesi->setItem(i,0,hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(tr("%1").arg(listeSube[i]->getSubeAdi()));
        ui->tableWidgetSubeListesi->setItem(i,1,hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(tr("%1").arg(listeSube[i]->getSubeYetkilisi()));
        ui->tableWidgetSubeListesi->setItem(i,2,hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(tr("%1").arg(listeSube[i]->getSubeTelNo()));
        ui->tableWidgetSubeListesi->setItem(i,3,hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(tr("%1").arg(listeSube[i]->getSubeAdresi()));
        ui->tableWidgetSubeListesi->setItem(i,4,hucre);

    }
}


void KRGSubeListesi::ara()
{
    auto ekran = this->ui;
    listeSube = KRGGenelVeriYoneticisi::db().getSubeBilgileri().tumunuBul(
        [ekran](KRGSubeBilgileriYoneticisi::Ptr veri)->bool {
            if(ekran->lineEditSubeAdiGiriniz->text()==""){
                return true;
            }

            if (ekran->lineEditSubeAdiGiriniz->text()!=""){
                if(!veri->getSubeAdi().toLower().contains(ekran->lineEditSubeAdiGiriniz->text().toLower())){
                    return false;
                }
            }
            return true;
        });
    listeGuncelle();
}


void KRGSubeListesi::on_pushButtonAra_clicked()
{
    ara();
}
