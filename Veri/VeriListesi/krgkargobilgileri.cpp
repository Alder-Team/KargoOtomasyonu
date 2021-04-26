#include "krgkargobilgileri.h"

KRGKargoBilgileri::KRGKargoBilgileri(QObject *parent) : QObject(parent)
{

}

IdTuru KRGKargoBilgileri::getId() const
{
    return id;
}

void KRGKargoBilgileri::setId(const IdTuru &value)
{
    if (value == id){
        return;
    }
    id = value;
    emit idDegisti(id);
}

Tarih KRGKargoBilgileri::getKargoTarihi() const
{
    return kargoTarihi;
}

void KRGKargoBilgileri::setKargoTarihi(const Tarih &value)
{
    if (value == kargoTarihi){
        return;
    }
    kargoTarihi = value;
    emit kargoTarihiDegisti(kargoTarihi);
}

KargoTuru KRGKargoBilgileri::getKargoTuru() const
{
    return kargoTuru;
}

void KRGKargoBilgileri::setKargoTuru(const KargoTuru &value)
{
    if (value == kargoTuru){
        return;
    }
    kargoTuru = value;
    emit kargoTuruDegisti(kargoTuru);
}

OdemeTuru KRGKargoBilgileri::getOdemeTuru() const
{
    return odemeTuru;
}

void KRGKargoBilgileri::setOdemeTuru(const OdemeTuru &value)
{
    if (value == odemeTuru){
        return;
    }
    odemeTuru = value;
    emit odemeTuruDegisti(odemeTuru);
}

Metin KRGKargoBilgileri::getGonderenSube() const
{
    return gonderenSube;
}

void KRGKargoBilgileri::setGonderenSube(const Metin &value)
{
    if (value == gonderenSube){
        return;
    }
    gonderenSube = value;
    emit gonderenSubeDegisti(gonderenSube);
}

Metin KRGKargoBilgileri::getAliciSube() const
{
    return aliciSube;
}

void KRGKargoBilgileri::setAliciSube(const Metin &value)
{
    if (value == aliciSube){
        return;
    }
    aliciSube = value;
    emit aliciSubeDegisti(aliciSube);
}

ParaBirimi KRGKargoBilgileri::getKargoUcreti() const
{
    return kargoUcreti;
}

void KRGKargoBilgileri::setKargoUcreti(const ParaBirimi &value)
{
    if (value == kargoUcreti){
        return;
    }
    kargoUcreti = value;
    emit kargoUcretiDegisti(kargoUcreti);
}

QDataStream &yaz(QDataStream &a, KRGKargoBilgileriPtr &b)
{
    a << b->getId() << b->getKargoTarihi() << b->getKargoTuru() << b->getOdemeTuru() << b->getGonderenSube() << b->getAliciSube() << b->getKargoUcreti();
    return a;
}
