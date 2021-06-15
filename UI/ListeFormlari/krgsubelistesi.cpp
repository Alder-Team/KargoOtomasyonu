#include "krgsubelistesi.h"
#include "ui_krgsubelistesi.h"

#include <Veri/VeriListesi/krgkargobilgileri.h>
#include <Veri/krggenelveriyoneticisi.h>
#include <UI/VeriFormlari/krgsubebilgileriekle.h>

#include<QStringList>
#include <QTableWidgetItem>
#include <QDebug>
#include <QPushButton>
#include <QMessageBox>


KRGSubeListesi::KRGSubeListesi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KRGSubeListesi)
{
    ui->setupUi(this);
    arama_yap();
}

KRGSubeListesi::~KRGSubeListesi()
{
    delete ui;
}

void KRGSubeListesi::listeGuncelle()
{
    ui->tableWidgetSubeListesi->clear();
    ui->tableWidgetSubeListesi->setRowCount(listeSube.length());
    ui->tableWidgetSubeListesi->setColumnCount(8);

    QStringList basliklar;
    basliklar << tr("Şube ID") << tr("Şube Adı") << tr("Şube Yetkilisi") << tr("Şube Telefon Numarası") << tr("Şube İli") << tr("Şube Adresi") << tr("Şube Silme") << tr("Şube Düzeltme");
    //Her birisi arasındaki uzaklık olayını anlamadım o yüzden eklemiyorum. Saygılar -Gülnur
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
        hucre->setText(listeSube[i]->getSubeIli());
        ui->tableWidgetSubeListesi->setItem(i,4,hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(tr("%1").arg(listeSube[i]->getSubeAdresi()));
        ui->tableWidgetSubeListesi->setItem(i,5,hucre);

        QPushButton *silmeButonu = new QPushButton();
        silmeButonu->setText(tr("Şubeyi Sil"));
        ui->tableWidgetSubeListesi->setCellWidget(i,6,silmeButonu);


        auto veri_i = listeSube[i];

        connect(silmeButonu, &QPushButton::clicked, [veri_i, this]() {
            auto cevap = QMessageBox::question(nullptr, tr("Silme Onayı"), tr("%1 isimli şubeyi silmek istediğinize emin misiniz?").arg(veri_i->getSubeAdi()));
            if (cevap == QMessageBox::Yes) {
                KRGGenelVeriYoneticisi::db().getSubeBilgileri().sil(veri_i->getId());
                QMessageBox::information(nullptr, tr("Kayıt Silindi"), tr("Kayıt silme işlemi tamamlandı!"));
                this->arama_yap();
            }
        });

        QPushButton *duzeltmeButonu = new QPushButton();
        duzeltmeButonu->setText(tr("Şubeyi Düzelt"));
        ui->tableWidgetSubeListesi->setCellWidget(i,7,duzeltmeButonu);

        connect(duzeltmeButonu, &QPushButton::clicked, [veri_i,this](){
            KRGSubeBilgileriEkle form;
            form.setVeri(veri_i);
            form.setWindowTitle(tr("%1 Şubesini Düzenle").arg(veri_i->getSubeAdi()));

            if (form.exec() == QDialog::Accepted) {
                form.getVeri();
                this->listeGuncelle();
            }
        });
    }
}


void KRGSubeListesi::ara()
{
    if(ui->checkBoxYazarkenAra->isChecked()){
        arama_yap();
    }
}

void KRGSubeListesi::arama_yap()
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
    arama_yap();
}
