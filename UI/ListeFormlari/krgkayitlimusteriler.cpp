#include "krgkayitlimusteriler.h"
#include "ui_krgkayitlimusteriler.h"
#include <UI/VeriDuzenleme/krgaliciduzenleme.h>
#include <UI/VeriDuzenleme/krggondericiduzenleme.h>
#include <Veri/VeriListesi/krgalicibilgileri.h>
#include <Veri/VeriListesi/krggondericibilgileri.h>
#include <Veri/krggenelveriyoneticisi.h>

#include<QStringList>
#include <QTableWidgetItem>
#include <QPushButton>
#include <QMessageBox>


KRGKayitliMusteriler::KRGKayitliMusteriler(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KRGKayitliMusteriler)
{
    ui->setupUi(this);
    arama_yap();

}

KRGKayitliMusteriler::~KRGKayitliMusteriler()
{
    delete ui;
}

void KRGKayitliMusteriler::listeGuncelle()
{
    ui->tableWidgetAliciListesi->clear();
    ui->tableWidgetAliciListesi->setRowCount(listeAlici.length());
    ui->tableWidgetAliciListesi->setColumnCount(7);


    QStringList basliklarAlici;
    basliklarAlici << tr("id") << tr("Alıcı Adı") << tr("Telefon Numarası") << tr("Mail") << tr("Adresi") << tr("Alıcı Silme") << tr("Alıcı Düzenleme");
    ui->tableWidgetAliciListesi->setHorizontalHeaderLabels(basliklarAlici);

    for (int i = 0; i < listeAlici.length(); i++) {

        QTableWidgetItem *hucre = new QTableWidgetItem();
        hucre->setText(tr("%1").arg(listeAlici[i]->getId()));
        ui->tableWidgetAliciListesi->setItem(i,0,hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(listeAlici[i]->getAliciAdi());
        ui->tableWidgetAliciListesi->setItem(i,1,hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(listeAlici[i]->getAliciTelNo());
        ui->tableWidgetAliciListesi->setItem(i,2,hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(tr("%1").arg(listeAlici[i]->getAliciEmail()));
        ui->tableWidgetAliciListesi->setItem(i,3,hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(tr("%1").arg(listeAlici[i]->getAliciAdresi()));
        ui->tableWidgetAliciListesi->setItem(i,4,hucre);

        QPushButton *silmeButonu = new QPushButton();
        silmeButonu->setText(tr("Alıcı Sil"));
        ui->tableWidgetAliciListesi->setCellWidget(i,5,silmeButonu);

        QPushButton *duzenlemeButonu = new QPushButton();
        duzenlemeButonu->setText(tr("Alıcı Düzenleme"));
        ui->tableWidgetAliciListesi->setCellWidget(i,6,duzenlemeButonu);


        auto veri_i = listeAlici[i];

        connect(silmeButonu, &QPushButton::clicked, [veri_i,this]() {
            auto cevap = QMessageBox::question(nullptr, tr("Silme Onayı"), tr("%1 isimli alıcıyı silmek istediğinize emin misiniz?").arg(veri_i->getAliciAdi()));
            if (cevap == QMessageBox::Yes) {
                KRGGenelVeriYoneticisi::db().getAliciBilgileri().sil(veri_i->getId());
                QMessageBox::information(nullptr, tr("Kayıt Silindi"), tr("Kayıt silme işlemi tamamlandı!"));
                this->arama_yap();
            }
        });

        connect(duzenlemeButonu, &QPushButton::clicked, [veri_i,this]() {
            KRGAliciDuzenleme form;
            form.setVeri(veri_i);
            form.setWindowTitle(tr("%1 isimli Alıcıyı Düzenle").arg(veri_i->getAliciAdi()));

            if (form.exec() == QDialog::Accepted) {
                form.getVeri();
                this->listeGuncelle();
            }
        });

    }

    ui->tableWidgetGondericiListesi->clear();
    ui->tableWidgetGondericiListesi->setRowCount(listeGonderici.length());
    ui->tableWidgetGondericiListesi->setColumnCount(7);

    QStringList basliklarGonderici;
    basliklarGonderici << tr("id") << tr("Gonderici Adı") << tr("Telefon Numarası") << tr("Mail") << tr("Adresi") <<tr("Gönderici silme") << tr("Gönderici düzenleme");
    ui->tableWidgetGondericiListesi->setHorizontalHeaderLabels(basliklarGonderici);

    for (int i = 0; i < listeGonderici.length(); i++) {

        QTableWidgetItem *hucre = new QTableWidgetItem();
        hucre->setText(tr("%1").arg(listeGonderici[i]->getId()));
        ui->tableWidgetGondericiListesi->setItem(i,0,hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(listeGonderici[i]->getGonderenAdi());
        ui->tableWidgetGondericiListesi->setItem(i,1,hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(listeGonderici[i]->getGonderenTelNo());
        ui->tableWidgetGondericiListesi->setItem(i,2,hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(tr("%1").arg(listeGonderici[i]->getGonderenEmail()));
        ui->tableWidgetGondericiListesi->setItem(i,3,hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(tr("%1").arg(listeGonderici[i]->getGonderenAdresi()));
        ui->tableWidgetGondericiListesi->setItem(i,4,hucre);

        QPushButton *silmeButonu = new QPushButton();
        silmeButonu->setText(tr("Gönderici Sil"));
        ui->tableWidgetGondericiListesi->setCellWidget(i,5,silmeButonu);

        QPushButton *duzenlemeButonu = new QPushButton();
        duzenlemeButonu->setText(tr("Gönderici Düzenleme"));
        ui->tableWidgetGondericiListesi->setCellWidget(i,6,duzenlemeButonu);


        auto veri_i = listeGonderici[i];

        connect(silmeButonu, &QPushButton::clicked, [veri_i,this]() {
            auto cevap = QMessageBox::question(nullptr, tr("Silme Onayı"), tr("%1 isimli göndericiyi silmek istediğinize emin misiniz?").arg(veri_i->getGonderenAdi()));
            if (cevap == QMessageBox::Yes) {
                KRGGenelVeriYoneticisi::db().getGondericiBilgileri().sil(veri_i->getId());
                QMessageBox::information(nullptr, tr("Kayıt Silindi"), tr("Kayıt silme işlemi tamamlandı!"));
                this->arama_yap();
            }
        });

        connect(duzenlemeButonu, &QPushButton::clicked, [veri_i,this]() {
            KRGGondericiDuzenleme form;
            form.setVeri(veri_i);
            form.setWindowTitle(tr("%1 isimli Göndericiyi Düzenle").arg(veri_i->getGonderenAdi()));

            if (form.exec() == QDialog::Accepted) {
                form.getVeri();
                this->listeGuncelle();
            }
        });

    }


}

void KRGKayitliMusteriler::arama_yap()
{
    auto ekran = this->ui;
    listeAlici = KRGGenelVeriYoneticisi::db().getAliciBilgileri().tumunuBul(
                [ekran](KRGAliciBilgileriYoneticisi::Ptr veri)->bool{
            if (ekran->lineEditAdiSoyadi->text() == ""){
                return true;
            }
            if(ekran->lineEditAdiSoyadi->text() !=""){
                if(ekran->radioButtonAliciMusteriler->isChecked()){
                    if(!veri->getAliciAdi().toLower().contains(ekran->lineEditAdiSoyadi->text().toLower())){
                        return false;
                    }
                }else{
                    return false;
                }
            }
            return true;
        });

    listeGonderici = KRGGenelVeriYoneticisi::db().getGondericiBilgileri().tumunuBul(
                [ekran](KRGGondericiBilgileriYoneticisi::Ptr veri)->bool{
            if (ekran->lineEditAdiSoyadi->text() == ""){
                return true;
            }
            if(ekran->lineEditAdiSoyadi->text() !=""){
                if(ekran->radioButtonGondericiMusteriler->isChecked()){
                    if(!veri->getGonderenAdi().toLower().contains(ekran->lineEditAdiSoyadi->text().toLower())){
                        return false;
                    }
                }else{
                    return false;
                }
            }
            return true;
        });
    listeGuncelle();
}


void KRGKayitliMusteriler::ara()
{
    if(ui->checkBoxYazarkenAra->isChecked()){
        arama_yap();
    }

}

void KRGKayitliMusteriler::on_pushButtonAra_clicked()
{
    arama_yap();
}

