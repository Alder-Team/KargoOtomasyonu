#include "krgalicibilgileriyoneticisi.h"
#include <Veri/VeriListesi/krgalicibilgileri.h>

KRGAliciBilgileriYoneticisi::KRGAliciBilgileriYoneticisi(QObject *parent) : QObject(parent)
{

}

KRGAliciBilgileriYoneticisi::Ptr KRGAliciBilgileriYoneticisi::kopyaOlustur(TemelVeriYonetici::Ptr kaynak)
{
    Ptr kopya = yeni();

    kopya->setId(kaynak->getId());
    kopya->setAliciAdi(kaynak->getAliciAdi());
    kopya->setAliciSoyadi(kaynak->getAliciSoyadi());
    kopya->setAliciAdresi(kaynak->getAliciAdresi());
    kopya->setAliciTelNo(kaynak->getAliciTelNo());
    kopya->setAliciEmail(kaynak->getAliciEmail());

    return kopya;
}
