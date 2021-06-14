#include "krgyenikargoekle.h"
#include "ui_krgyenikargoekle.h"

#include <Veri/VeriListesi/krgkargobilgileri.h>
#include <Veri/VeriListesi/krgalicibilgileri.h>
#include <Veri/VeriListesi/krggondericibilgileri.h>

#include <Veri/krggenelveriyoneticisi.h>

KRGYeniKargoEkle::KRGYeniKargoEkle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KRGYeniKargoEkle)
{

    ui->setupUi(this);

    // connect(ui->dspinboxDesiYukseklik, static_cast<void(QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged), this, &KRGYeniKargoEkle::calcDesi);
    // this->calcDesi();
    auto tumSubeler = KRGGenelVeriYoneticisi::db().getSubeBilgileri().tumunuBul(
                [](KRGSubeBilgileriPtr){ return true;
    });

    for (const auto &sube: qAsConst(tumSubeler)) {
        ui->comboboxAliciSube->addItem(sube->getSubeAdi());
    }

    for (const auto &sube: qAsConst(tumSubeler)) {
        ui->comboboxGondericiSube->addItem(sube->getSubeAdi());
    }
    connect(ui->dspinboxDesiEn, static_cast<void(QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged), this, &KRGYeniKargoEkle::desiHesapla);
    connect(ui->dspinboxDesiBoy, static_cast<void(QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged), this, &KRGYeniKargoEkle::desiHesapla);
    connect(ui->dspinboxDesiYukseklik, static_cast<void(QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged), this, &KRGYeniKargoEkle::desiHesapla);
    this->desiHesapla();

}

KRGYeniKargoEkle::~KRGYeniKargoEkle()
{
    delete ui;
}

KRGKargoBilgileriPtr KRGYeniKargoEkle::getVeriKargo() const
{
    if (ui->radiobtnAliciOdemeli->isChecked()) {
        veriKargo->setOdemeTuru(OTAliciOdemeli);
    } else {
        veriKargo->setOdemeTuru(OTGondericiOdemeli);
    }

    veriKargo->setKargoEn(ui->dspinboxDesiEn->value());
    veriKargo->setKargoBoy(ui->dspinboxDesiBoy->value());
    veriKargo->setKargoYukseklik(ui->dspinboxDesiYukseklik->value());

    veriKargo->setKargoDesi(ui->lblDesiSonucSayi->text().toDouble());

    veriKargo->setGonderenSube(ui->comboboxGondericiSube->currentText());
    // ID alabiliriz
    veriKargo->setAliciSube(ui->comboboxAliciSube->currentText());

    veriKargo->setKargoTarihi(ui->dateEditTarih->date());

    veriKargo->setKargoUcreti(ui->lblTutarSonuc->text().toDouble());

    return veriKargo;
}

void KRGYeniKargoEkle::setVeriKargo(const KRGKargoBilgileriPtr &value)
{
    veriKargo = value;

    switch (veriKargo->getOdemeTuru()) {
    case OTGondericiOdemeli:
        ui->radiobtnGonderiOdemeli->setChecked(true);
        break;
    default:
        ui->radiobtnAliciOdemeli->setChecked(true);
    }

    ui->dspinboxDesiEn->setValue(veriKargo->getKargoEn());
    ui->dspinboxDesiBoy->setValue(veriKargo->getKargoBoy());
    ui->dspinboxDesiYukseklik->setValue(veriKargo->getKargoYukseklik());
    ui->lblDesiSonucSayi->setText(tr("%1").arg(veriKargo->getKargoDesi()));

    ui->comboboxAliciSube->currentIndex();
    ui->comboboxGondericiSube->setCurrentText(veriKargo->getGonderenSube());
    ui->comboboxAliciSube->setCurrentText(veriKargo->getAliciSube());

    ui->dateEditTarih->setDate(veriKargo->getKargoTarihi());
    ui->lblTutarSonuc->setText(tr("%1").arg(veriKargo->getKargoUcreti()));
}

KRGGondericiBilgileriPtr KRGYeniKargoEkle::getVeriGonderici() const
{

    veriGonderici->setGonderenAdi(ui->lineEditGondericiAdi->text());
    veriGonderici->setGonderenAdresi(ui->plainTextEditGondericiAdresi->toPlainText());
    veriGonderici->setGonderenEmail(ui->lineEditGondericiEmail->text());
    veriGonderici->setGonderenTelNo(ui->lineEditGondericiTelefonNumarasi->text());
    return veriGonderici;
}

void KRGYeniKargoEkle::setVeriGonderici(const KRGGondericiBilgileriPtr &value)
{
    veriGonderici = value;
    ui->lineEditGondericiAdi->setText(veriGonderici->getGonderenAdi());
    ui->plainTextEditGondericiAdresi->setPlainText(veriGonderici->getGonderenAdresi());
    ui->lineEditGondericiEmail->setText(veriGonderici->getGonderenEmail());
    ui->lineEditGondericiTelefonNumarasi->setText(veriGonderici->getGonderenTelNo());

}


KRGAliciBilgileriPtr KRGYeniKargoEkle::getVeriAlici() const
{
    veriAlici->setAliciAdi(ui->lineEditAliciAdi->text());
    veriAlici->setAliciAdresi(ui->plainTextEditAliciAdresi->toPlainText());
    veriAlici->setAliciEmail(ui->lineEditAliciEmail->text());
    veriAlici->setAliciTelNo(ui->lineEditAliciTelefonNumarasi->text());
    return veriAlici;
}

void KRGYeniKargoEkle::setVeriAlici(const KRGAliciBilgileriPtr &value)
{
    veriAlici = value;
    ui->lineEditAliciAdi->setText(veriAlici->getAliciAdi());
    ui->plainTextEditAliciAdresi->setPlainText(veriAlici->getAliciAdresi());
    ui->lineEditAliciEmail->setText(veriAlici->getAliciEmail());
    ui->lineEditAliciTelefonNumarasi->setText(veriAlici->getAliciTelNo());
}

void KRGYeniKargoEkle::desiHesapla()
{
    auto desi = ui->dspinboxDesiBoy->value() * ui->dspinboxDesiEn->value() * ui->dspinboxDesiYukseklik->value() / 3000;
    ui->lblDesiSonucSayi->setText(QString::number(desi));

}
