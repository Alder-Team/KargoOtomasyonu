#include "krgkargolistesi.h"
#include "ui_krgkargolistesi.h"

#include <Veri/VeriListesi/krgkargobilgileri.h>
#include <Veri/VeriListesi/krgalicibilgileri.h>
#include <Veri/VeriListesi/krggondericibilgileri.h>
#include <UI/VeriFormlari/krgyenikargoekle.h>
#include <Veri/krggenelveriyoneticisi.h>
#include <UI/VeriDuzenleme/krgaliciduzenleme.h>
#include <UI/VeriDuzenleme/krggondericiduzenleme.h>
#include <UI/VeriDuzenleme/krgkargoduzenleme.h>
#include<QStringList>
#include <QTableWidgetItem>
#include <QDebug>
#include <QPushButton>
#include <QMessageBox>


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
    ui->tableWidgetKargoListesi->setColumnCount(14);

    QStringList basliklar;
    basliklar <<tr("ID") << tr("Alıcı İd") << tr("Gönderici Id") << tr("Tarih") << tr("Ödeme Türü") << tr("En") << tr("Boy") << tr("Yükseklik") << tr("Desi") << tr("Gönderen Şube") << tr("Alıcı Şube") << tr("Tutar") <<tr("Gönderi Silme") << tr("Gönderi Düzenleme");
    ui->tableWidgetKargoListesi->setHorizontalHeaderLabels(basliklar);


    for (int i = 0; i < listeKargo.length(); i++) {


        QTableWidgetItem *hucre = new QTableWidgetItem();
        hucre->setText(tr("%1").arg(listeKargo[i]->getId()));
        ui->tableWidgetKargoListesi->setItem(i,0,hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(tr("%1").arg(listeKargo[i]->getKargoUcreti()));
        ui->tableWidgetKargoListesi->setItem(i,1,hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(tr("%1").arg(listeKargo[i]->getKargoUcreti()));
        ui->tableWidgetKargoListesi->setItem(i,2,hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(listeKargo[i]->getKargoTarihi().toString("yyyy.MM.dd"));
        ui->tableWidgetKargoListesi->setItem(i,3,hucre);



        hucre = new QTableWidgetItem();
        switch (listeKargo[i]->getOdemeTuru()) {
        case OTGondericiOdemeli:
            hucre->setText("Gönderici Ödemeli");
            break;
        default:
            hucre->setText("Alıcı Ödemeli");
        }
        ui->tableWidgetKargoListesi->setItem(i, 4, hucre);



        hucre = new QTableWidgetItem();
        hucre->setText(tr("%1").arg(listeKargo[i]->getKargoEn()));
        ui->tableWidgetKargoListesi->setItem(i,5,hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(tr("%1").arg(listeKargo[i]->getKargoBoy()));
        ui->tableWidgetKargoListesi->setItem(i,6,hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(tr("%1").arg(listeKargo[i]->getKargoYukseklik()));
        ui->tableWidgetKargoListesi->setItem(i,7,hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(tr("%1").arg(listeKargo[i]->getKargoDesi()));
        ui->tableWidgetKargoListesi->setItem(i,8,hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(listeKargo[i]->getGonderenSube());
        ui->tableWidgetKargoListesi->setItem(i,9,hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(listeKargo[i]->getAliciSube());
        ui->tableWidgetKargoListesi->setItem(i,10,hucre);


        hucre = new QTableWidgetItem();
        hucre->setText(tr("%1").arg(listeKargo[i]->getKargoUcreti()));
        ui->tableWidgetKargoListesi->setItem(i,11,hucre);

        QPushButton *silmeButonu = new QPushButton();
        silmeButonu->setText(tr("Gönderi Sil"));
        ui->tableWidgetKargoListesi->setCellWidget(i,12,silmeButonu);

        QPushButton *duzenlemeButonu = new QPushButton();
        duzenlemeButonu->setText(tr("Gönderi Düzenleme"));
        ui->tableWidgetKargoListesi->setCellWidget(i,13,duzenlemeButonu);


        auto veri_i = listeKargo[i];

        connect(silmeButonu, &QPushButton::clicked, [veri_i,this]() {
            auto cevap = QMessageBox::question(nullptr, tr("Silme Onayı"), tr("%1 Id'li gönderiyi silmek istediğinize emin misiniz?").arg(veri_i->getId()));
            if (cevap == QMessageBox::Yes) {
                KRGGenelVeriYoneticisi::db().getKargoBilgileri().sil(veri_i->getId());
                QMessageBox::information(nullptr, tr("Kayıt Silindi"), tr("Kayıt silme işlemi tamamlandı!"));
                this->ara();
            }
        });

        connect(duzenlemeButonu, &QPushButton::clicked, [veri_i,this]() {
            KRGKargoDuzenleme form;
            form.setVeri(veri_i);
            form.setWindowTitle(tr("%1 Id'li Gönderiyi Düzenle").arg(veri_i->getId()));

            if (form.exec() == QDialog::Accepted) {
                form.getVeri();
                this->listeGuncelle();
            }
        });



    }

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
                this->ara();
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
                this->ara();
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



/*
 * Lineer Arama Algoritması yazıldı.
 * Vakit az diye diğer algoritmalardan vazgeçildi.
 *
 */



void KRGKargoListesi::ara()
{
    // quint64 aramaAliciId;
    auto ekran = this->ui;
    listeKargo = KRGGenelVeriYoneticisi::db().getKargoBilgileri().tumunuBul(
        [ekran](KRGKargoBilgileriYoneticisi::Ptr veri)->bool {
            if(ekran->lineEditKargoIdGiriniz->text()==""){
                return true;
            }
            auto iter = QString::number(veri->getId());
            if (ekran->lineEditKargoIdGiriniz->text()!=""){
                if(iter != ekran->lineEditKargoIdGiriniz->text()){
                    // aramaAliciId = veri->getAliciId();
                    return false;
                }
            }
            return true;
        });
    listeAlici = KRGGenelVeriYoneticisi::db().getAliciBilgileri().tumunuBul(
        [](KRGAliciBilgileriYoneticisi::Ptr veri)->bool{
            return true;
            }
        );

    listeGonderici = KRGGenelVeriYoneticisi::db().getGondericiBilgileri().tumunuBul(
        [](KRGGondericiBilgileriYoneticisi::Ptr veri)->bool {
            return true;
            }
        );
    listeGuncelle();
}



/*

void KRGKargoListesi::ara()
{

    auto ekran = this->ui;
    listeKargo = KRGGenelVeriYoneticisi::db().getKargoBilgileri().tumunuBul(
        [this,ekran](KRGKargoBilgileriYoneticisi::Ptr veri)->bool {
            if(ekran->lineEditKargoIdGiriniz->text()==""){
                return true;
            }
            auto iter = QString::number(veri->getId());
            if (ekran->lineEditKargoIdGiriniz->text()!=""){
                if(iter != ekran->lineEditKargoIdGiriniz->text()){
                    setAramaAliciId(veri->getAliciId());
                    return false;
                }
            }
            return true;
        });
    listeAlici = KRGGenelVeriYoneticisi::db().getAliciBilgileri().tumunuBul(
        [this](KRGAliciBilgileriYoneticisi::Ptr veri)->bool{
            qDebug() << "Alici" << veri->getId() << getAramaAliciId();
            if (veri->getId() != getAramaAliciId()){
                return false;
            }
            return true;
        });

    listeGonderici = KRGGenelVeriYoneticisi::db().getGondericiBilgileri().tumunuBul(
        [this](KRGGondericiBilgileriYoneticisi::Ptr veri)->bool {
            qDebug() << "Gönderici" << veri->getId() << getAramaGondericiId();
            if(veri->getId() != getAramaGondericiId()){
                return false;
            }
            return true;
            }
        );
    listeGuncelle();
}

quint64 KRGKargoListesi::getAramaGondericiId() const
{
    return aramaGondericiId;
}

void KRGKargoListesi::setAramaGondericiId(quint64 newAramaGondericiId)
{

    if(newAramaGondericiId == aramaGondericiId)
        return;
    aramaGondericiId = newAramaGondericiId;
    emit aramaGondericiIdDegisti(aramaGondericiId);
}

quint64 KRGKargoListesi::getAramaAliciId() const
{
    return aramaAliciId;
}

void KRGKargoListesi::setAramaAliciId(quint64 newAramaAliciId)
{
    if (newAramaAliciId == aramaAliciId)
        return;
    aramaAliciId = newAramaAliciId;
    emit aramaAliciIdDegisti(aramaAliciId);
}




*/

void KRGKargoListesi::on_pushButtonAra_clicked()
{
    ara();
}

