#include "krggondericibilgileriyoneticisi.h"
#include <Veri/VeriListesi/krggondericibilgileri.h>

KRGGondericiBilgileriYoneticisi::KRGGondericiBilgileriYoneticisi(QObject *parent) : QObject(parent)
{

}

KRGGondericiBilgileriYoneticisi::Ptr KRGGondericiBilgileriYoneticisi::kopyaOlustur(KRGGondericiBilgileriYoneticisi::Ptr kaynak)
{
    Ptr kopya = yeni();
    kopya->setId(kaynak->getId());
    kopya->setGonderenAdi(kaynak->getGonderenAdi());
    kopya->setGonderenSoyadi(kaynak->getGonderenSoyadi());
    kopya->setGonderenAdresi(kaynak->getGonderenAdresi());
    kopya->setGonderenTelNo(kaynak->getGonderenTelNo());
    kopya->setGonderenEmail(kaynak->getGonderenEmail());
}
