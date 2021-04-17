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

KRGKargoBilgileriYoneticisi::Ptr KRGKargoBilgileriYoneticisi::sil(IdTuru kargoId)
{
    for (int i=0; i<veriler.size(); i++) {
        if (veriler[i]->getKargoId() == kargoId) {
            Ptr sonuc = veriler.takeAt(i);
            return sonuc;
        }
    }
    throw tr("Aranılan kargo bulunamadı! Silme işlemi iptal edildi");
}

/* void KRGKargoBilgileriYoneticisi::sil(IdTuru kargoId)
{
    for (int i=0; i<veriler.size(); i++) {
        if (veriler[i]->getKargoId() == kargoId) {
            Ptr sonuc = veriler.takeAt(i);
            return sonuc;
        }
    }
    throw tr("Aranılan kargo bulunamadı! Silme işlemi iptal edildi");
}
*/
