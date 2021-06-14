#include "krggondericiduzenleme.h"
#include "ui_krggondericiduzenleme.h"
#include <Veri/VeriListesi/krggondericibilgileri.h>

KRGGondericiDuzenleme::KRGGondericiDuzenleme(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KRGGondericiDuzenleme)
{
    ui->setupUi(this);
}

KRGGondericiDuzenleme::~KRGGondericiDuzenleme()
{
    delete ui;
}

KRGGondericiBilgileriPtr KRGGondericiDuzenleme::getVeri() const
{
    veri->setGonderenAdi(ui->lineEditGondericiAdi->text());
    veri->setGonderenAdresi(ui->plainTextEditGondericiAdresi->toPlainText());
    veri->setGonderenTelNo(ui->lineEditGondericiTelefonNumarasi->text());
    veri->setGonderenEmail(ui->lineEditGondericiEmail->text());
    return veri;
}

void KRGGondericiDuzenleme::setVeri(const KRGGondericiBilgileriPtr &value)
{
    veri = value;
    ui->lineEditGondericiAdi->setText(veri->getGonderenAdi());
    ui->plainTextEditGondericiAdresi->setPlainText(veri->getGonderenAdresi());
    ui->lineEditGondericiTelefonNumarasi->setText(veri->getGonderenTelNo());
    ui->lineEditGondericiEmail->setText(veri->getGonderenEmail());

}
