#include "krgkargobilgileriyoneticisi.h"
#include <Veri/VeriListesi/krgkargobilgileri.h>

KRGKargoBilgileriYoneticisi::KRGKargoBilgileriYoneticisi(QObject *parent) : QObject(parent)
{
    enSonId = 0;
}

KRGKargoBilgileriYoneticisi::Ptr KRGKargoBilgileriYoneticisi::yeni() const
{
    Ptr yeni = std::make_shared<KRGKargoBilgileri>();
    return yeni;
}

void KRGKargoBilgileriYoneticisi::ekle(KRGKargoBilgileriYoneticisi::Ptr kargo)
{
    kargo->setKargoId(enSonId++);
    veriler.append(kargo);
}
