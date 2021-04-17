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
    return kopya;
}
