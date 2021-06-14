#include "krgkargoduzenleme.h"
#include "ui_krgkargoduzenleme.h"
#include <Veri/VeriListesi/krgkargobilgileri.h>

KRGKargoDuzenleme::KRGKargoDuzenleme(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KRGKargoDuzenleme)
{
    ui->setupUi(this);
}

KRGKargoDuzenleme::~KRGKargoDuzenleme()
{
    delete ui;
}

KRGKargoBilgileriPtr KRGKargoDuzenleme::getVeri() const
{
    if (ui->radiobtnAliciOdemeli_2->isChecked()){
        veri->setOdemeTuru(OTAliciOdemeli);

    }else{
        veri->setOdemeTuru(OTGondericiOdemeli);
    }

   veri->setKargoEn(ui->dspinboxDesiEn_2->value());
   veri->setKargoBoy(ui->dspinboxDesiBoy_2->value());
   veri->setKargoYukseklik(ui->dspinboxDesiYukseklik_2->value());
   veri->setKargoDesi(ui->lblDesiSonucSayi_2->text().toDouble());
   veri->setAliciSube(ui->comboboxAliciSube_2->currentText());
   veri->setGonderenSube(ui->comboboxGondericiSube_2->currentText());
   veri->setKargoTarihi(ui->dateEditTarih_2->date());
    return veri;
}

void KRGKargoDuzenleme::setVeri(const KRGKargoBilgileriPtr &value)
{
    veri = value;
    switch (veri->getOdemeTuru()) {
    case OTGondericiOdemeli:
        ui->radiobtnGonderiOdemeli_2->setChecked(true);
        break;
    default:
        ui->radiobtnAliciOdemeli_2->setChecked(true);
        break;

    }

    ui->dspinboxDesiEn_2->setValue(veri->getKargoEn());
    ui->dspinboxDesiBoy_2->setValue(veri->getKargoBoy());
    ui->dspinboxDesiYukseklik_2->setValue(veri->getKargoYukseklik());
    ui->lblDesiSonucSayi_2->setText(tr("%1").arg(veri->getKargoDesi()));
    ui->comboboxAliciSube_2->setCurrentText(veri->getAliciSube());
    ui->comboboxGondericiSube_2->setCurrentText(veri->getGonderenSube());
    ui->dateEditTarih_2->setDate(veri->getKargoTarihi());

}
