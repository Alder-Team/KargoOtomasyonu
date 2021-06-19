#include "krgyenikargoekle.h"
#include "ui_krgyenikargoekle.h"

#include <Veri/VeriListesi/krgkargobilgileri.h>
#include <Veri/VeriListesi/krgalicibilgileri.h>
#include <Veri/VeriListesi/krggondericibilgileri.h>

#include <Veri/krggenelveriyoneticisi.h>
#include <Veri/Csv/krgcsvreadclass.h>

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
        ui->comboboxAliciSube->addItem(tr("%1 -%2").arg(sube->getSubeAdi(), sube->getSubeIli()));
    }

    for (const auto &sube: qAsConst(tumSubeler)) {
        ui->comboboxGondericiSube->addItem(tr("%1 -%2").arg(sube->getSubeAdi(), sube->getSubeIli()));
    }

    connect(ui->dspinboxDesiEn, static_cast<void(QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged), this, &KRGYeniKargoEkle::desiHesapla);
    connect(ui->dspinboxDesiBoy, static_cast<void(QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged), this, &KRGYeniKargoEkle::desiHesapla);
    connect(ui->dspinboxDesiYukseklik, static_cast<void(QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged), this, &KRGYeniKargoEkle::desiHesapla);

    connect(ui->comboboxAliciSube, &QComboBox::currentTextChanged,this, &KRGYeniKargoEkle::tutarHesapla);
    connect(ui->comboboxGondericiSube, &QComboBox::currentTextChanged,this, &KRGYeniKargoEkle::tutarHesapla);
    connect(this, &KRGYeniKargoEkle::desiDegisti, this, &KRGYeniKargoEkle::tutarHesapla);
    this->desiHesapla();
    this->tutarHesapla();

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
    veriKargo->setAliciSube(ui->comboboxAliciSube->currentText());
    // veriKargo->setAliciSube(ui->comboboxAliciSube->currentData());
    // veriKargo->setGonderenSube(ui->comboboxGondericiSube->currentData());

    veriKargo->setKargoTarihi(ui->dateEditTarih->date());
    veriKargo->setKargoUcreti(ui->lblTutarSonuc->text().toDouble());

    // Bu satırlar çok önemli
    /*
    KRGAliciBilgileriYoneticisi::VeriListesi listeAlici;
    listeAlici = KRGGenelVeriYoneticisi::db().getAliciBilgileri().tumunuBul(
                [this](KRGAliciBilgileriYoneticisi::Ptr veri)->bool{

                    return true;
                }
            );

    */


    try {
        auto sonAliciId = KRGGenelVeriYoneticisi::db().getAliciBilgileri().sonuncuyuBul(
                    [](KRGAliciBilgileriYoneticisi::Ptr veri){return true;});

        auto sonGondericiId = KRGGenelVeriYoneticisi::db().getGondericiBilgileri().sonuncuyuBul(
                    [](KRGGondericiBilgileriYoneticisi::Ptr veri){return true;});

        veriKargo->setAliciId(sonAliciId->getId() + 1);

        veriKargo->setGondericiId(sonGondericiId->getId() + 1 );
    } catch (...) {
        qDebug() << "~libc++abi: terminating with uncaught exception of type QString~ hatası yakalıyorduk düzelmektemedik.";
    }


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

    // Arama
    // ui->comboboxAliciSube->currentIndex();
    // ui->comboboxGondericiSube->currentIndex();
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
    qDebug() << 129 << "veriAlici->getId" << veriAlici->getId();
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
    emit desiDegisti(QString::number(desi));
}

void KRGYeniKargoEkle::tutarHesapla()
{

    QStringList ilListesi;
    ilListesi <<""<< "Adana" << "Adıyaman" << "Afyon" << "Ağrı" << "Amasya" << "Ankara"<< "Antalya"<< "Artvin"<< "Aydın"<< "Balıkesir"<< "Bilecik"<< "Bingöl"<< "Bitlis"<< "Bolu"<< "Burdur"<< "Bursa"<< "Çanakkale"<< "Çankırı"<< "Çorum"<< "Denizli"<< "Diyarbakır"<< "Edirne"<< "Elazığ"<< "Erzincan"<< "Erzurum"<< "Eskişehir"<< "Gaziantep"<< "Giresun"<< "Gümüşhane"<< "Hakkari"<< "Hatay"<< "Isparta"<< "Mersin"<< "İstanbul"<< "İzmir"<< "Kars"<< "Kastamonu"<< "Kayseri"<< "Kırklareli"<< "Kırşehir"<< "Kocaeli"<< "Konya"<< "Kütahya"<< "Malatya"<< "Manisa"<< "Kahramanmaraş"<< "Mardin"<< "Muğla"<< "Muş"<< "Nevşehir"<< "Niğde"<< "Ordu"<< "Rize"<< "Sakarya"<< "Samsun"<< "Siirt"<< "Sinop" << "Sivas"<< "Tekirdağ"<< "Tokat"<< "Trabzon"<< "Tunceli"<< "Şanlıurfa"<< "Uşak"<< "Van"<< "Yozgat"<< "Zonguldak"<< "Aksaray"<< "Bayburt"<< "Karaman" << "Kırıkkale" << "Batman"<< "Şırnak"<< "Bartın"<< "Ardahan"<< "Iğdır"<< "Yalova" << "Karabük" << "Kilis" << "Osmaniye" << "Düzce";
    QRegExp tagExp("-");
    KRGCsvReadClass r;

    auto aliciSubeDetay = ui->comboboxAliciSube->currentText();
    auto gondericiSubeDetay = ui->comboboxGondericiSube->currentText();

    if(!aliciSubeDetay.isEmpty() && !gondericiSubeDetay.isEmpty()){
        QStringList aliciSubeIl = aliciSubeDetay.split(tagExp);
        QStringList gondericiSubeIl = gondericiSubeDetay.split(tagExp);



        QList<int> plakalar;
        for (int i = 0; i < ilListesi.length() ; i++ ) {
            if (ilListesi[i] == aliciSubeIl[1]){
                plakalar.append(i);
            }
            if (ilListesi[i] == gondericiSubeIl[1]){
                plakalar.append(i);
            }
        }
        auto mesafe = r.mesafe(plakalar[0], plakalar[1]);

        if (mesafe <= 0){
            ui->lblTutarSonuc->setText(tr("%1").arg(0));
        }else if (mesafe < 300) {
            ui->lblTutarSonuc->setText(tr("%1").arg(ui->lblDesiSonucSayi->text().toDouble() * 5));
        }else if (mesafe >= 300 & mesafe < 600) {
            ui->lblTutarSonuc->setText(tr("%1").arg(ui->lblDesiSonucSayi->text().toDouble() * 7));
        }else{
            ui->lblTutarSonuc->setText(tr("%1").arg(ui->lblDesiSonucSayi->text().toDouble() * 10));
        }

    }
}
