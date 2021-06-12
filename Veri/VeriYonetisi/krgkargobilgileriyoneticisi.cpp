#include "krgkargobilgileriyoneticisi.h"
#include <Veri/VeriListesi/krgkargobilgileri.h>

KRGKargoBilgileriYoneticisi::KRGKargoBilgileriYoneticisi(QObject *parent) : QObject(parent)
{

}

KRGKargoBilgileriYoneticisi::Ptr KRGKargoBilgileriYoneticisi::kopyaOlustur(KRGKargoBilgileriYoneticisi::Ptr kaynak)
{
    Ptr kopya = yeni();
    kopya->setId(kaynak->getId());
    kopya->setKargoTarihi(kaynak->getKargoTarihi());
    kopya->setKargoTuru(kaynak->getKargoTuru());
    kopya->setOdemeTuru(kaynak->getOdemeTuru());
    kopya->setGonderenSube(kaynak->getGonderenSube());
    kopya->setAliciSube(kaynak->getAliciSube());
    kopya->setKargoUcreti(kaynak->getKargoUcreti());
    kopya->setKargoEn(kaynak->getKargoEn());
    kopya->setKargoBoy(kaynak->getKargoBoy());
    kopya->setKargoYukseklik(kaynak->getKargoYukseklik());
    kopya->setKargoAgirlik(kaynak->getKargoAgirlik());
    kopya->setKargoDesi(kaynak->getKargoDesi());
    kopya->setAliciId(kaynak->getAliciId());
    kopya->setGondericiId(kaynak->getGondericiId());

    return kopya;
}
