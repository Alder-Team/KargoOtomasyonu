#include "krgsubebilgileriyoneticisi.h"
#include <Veri/VeriListesi/krgsubebilgileri.h>

KRGSubeBilgileriYoneticisi::KRGSubeBilgileriYoneticisi(QObject *parent) : QObject(parent)
{

}

KRGSubeBilgileriYoneticisi::Ptr KRGSubeBilgileriYoneticisi::kopyaOlustur(TemelVeriYonetici::Ptr kaynak)
{
    Ptr kopya = yeni();
    kopya->setId(kaynak->getId());
    kopya->setSubeAdi(kaynak->getSubeAdi());
    kopya->setSubeAdresi(kaynak->getSubeAdresi());
    kopya->setSubeTelNo(kaynak->getSubeTelNo());
    kopya->setSubeYetkilisi(kaynak->getSubeYetkilisi());
    kopya->setSubeIli(kaynak->getSubeIli());


    return kopya;
}
