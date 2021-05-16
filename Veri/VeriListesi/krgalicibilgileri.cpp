#include "krgalicibilgileri.h"

KRGAliciBilgileri::KRGAliciBilgileri(QObject *parent) : QObject(parent)
{

}

Metin KRGAliciBilgileri::getAliciAdi() const
{
    return aliciAdi;
}

void KRGAliciBilgileri::setAliciAdi(const Metin &value)
{
    if (value == aliciAdi){
        return;
    }
    aliciAdi = value;
    emit aliciAdiDegisti(aliciAdi);
}

Metin KRGAliciBilgileri::getAliciSoyadi() const
{
    return aliciSoyadi;
}

void KRGAliciBilgileri::setAliciSoyadi(const Metin &value)
{
    if (value == aliciSoyadi){
        return;
    }
    aliciSoyadi = value;
    emit aliciSoyadiDegisti(aliciSoyadi);
}

Metin KRGAliciBilgileri::getAliciAdresi() const
{
    return aliciAdresi;
}

void KRGAliciBilgileri::setAliciAdresi(const Metin &value)
{
    if (value == aliciAdresi){
        return;
    }
    aliciAdresi = value;
    emit aliciAdresiDegisti(aliciAdresi);
}

Metin KRGAliciBilgileri::getAliciTelNo() const
{
    return aliciTelNo;
}

void KRGAliciBilgileri::setAliciTelNo(const Metin &value)
{
    if (value == aliciTelNo){
        return;
    }
    aliciTelNo = value;
    emit aliciTelNoDegisti(aliciTelNo);
}

Metin KRGAliciBilgileri::getAliciEmail() const
{
    return aliciEmail;
}

void KRGAliciBilgileri::setAliciEmail(const Metin &value)
{
    if (value == aliciEmail){
        return;
    }
    aliciEmail = value;
    emit aliciEmailDegisti(aliciEmail);
}

IdTuru KRGAliciBilgileri::getId() const
{
    return id;
}

void KRGAliciBilgileri::setId(const IdTuru &value)
{
    if (value == id){
        return;
    }
    id = value;
    emit idDegisti(id);
}

QDataStream &operator<<(QDataStream &a, const KRGAliciBilgileriPtr &b)
{
    a << b->getAliciAdi() << b->getAliciSoyadi() << b->getAliciAdresi() << b->getAliciTelNo() << b->getAliciEmail() << b->getId();
    return a;
}

QDataStream &operator>>(QDataStream &a, KRGAliciBilgileriPtr &b)
{
    Metin aliciAdi, aliciSoyadi, aliciAdresi, aliciTelNo, aliciEmail;
    IdTuru id;

    a >> aliciAdi >> aliciSoyadi >> aliciAdresi >> aliciTelNo >> aliciEmail >> id;

    b = std::make_shared<KRGAliciBilgileri>();

    b->setAliciAdi(aliciAdi);
    b->setAliciSoyadi(aliciSoyadi);
    b->setAliciAdresi(aliciAdresi);
    b->setAliciTelNo(aliciTelNo);
    b->setAliciEmail(aliciEmail);
    b->setId(id);

    return a;
}
