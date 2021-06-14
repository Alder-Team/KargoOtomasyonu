#include "krgaliciduzenleme.h"
#include "ui_krgaliciduzenleme.h"
#include <Veri/VeriListesi/krgalicibilgileri.h>

KRGAliciDuzenleme::KRGAliciDuzenleme(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KRGAliciDuzenleme)
{
    ui->setupUi(this);
}

KRGAliciDuzenleme::~KRGAliciDuzenleme()
{
    delete ui;
}

KRGAliciBilgileriPtr KRGAliciDuzenleme::getVeri() const
{
    veri->setAliciAdi(ui->lineEditAliciAdi_2->text());
    veri->setAliciAdresi(ui->plainTextEditAliciAdresi_2->toPlainText());
    veri->setAliciTelNo(ui->lineEditAliciTelefonNumarasi_2->text());
    veri->setAliciEmail(ui->lineEditAliciEmail_2->text());

    return veri;
}

void KRGAliciDuzenleme::setVeri(const KRGAliciBilgileriPtr &value)
{
    veri = value;
    ui->lineEditAliciAdi_2->setText(veri->getAliciAdi());
    ui->plainTextEditAliciAdresi_2->setPlainText(veri->getAliciAdresi());
    ui->lineEditAliciTelefonNumarasi_2->setText(veri->getAliciTelNo());
    ui->lineEditAliciEmail_2->setText(veri->getAliciEmail());
}
