#include "krgsubebilgileriekle.h"
#include "ui_krgsubebilgileriekle.h"
#include <Veri/VeriListesi/krgsubebilgileri.h>

KRGSubeBilgileriEkle::KRGSubeBilgileriEkle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KRGSubeBilgileriEkle)
{
    ui->setupUi(this);
}

KRGSubeBilgileriEkle::~KRGSubeBilgileriEkle()
{
    delete ui;
}

KRGSubeBilgileriPtr KRGSubeBilgileriEkle::getVeri() const
{
    veri->setSubeAdi(ui->lineEditSubeAdi->text());
    veri->setSubeTelNo(ui->lineEditSubeTelefonNumarasi->text());
    veri->setSubeYetkilisi(ui->lineEditSubeYetkilisi->text());
    veri->setSubeIli(ui->comboBox->currentText());
    veri->setSubeAdresi(ui->plainTextEditSubeAdresi->toPlainText());
    return veri;

}

void KRGSubeBilgileriEkle::setVeri(const KRGSubeBilgileriPtr &value)
{
    veri = value;
    ui->lineEditSubeAdi->setText(veri->getSubeAdi());
    ui->lineEditSubeTelefonNumarasi->setText(veri->getSubeTelNo());
    ui->lineEditSubeYetkilisi->setText(veri->getSubeYetkilisi());
    ui->plainTextEditSubeAdresi->setPlainText(veri->getSubeAdresi());
    ui->comboBox->setCurrentText(veri->getSubeIli());
}
