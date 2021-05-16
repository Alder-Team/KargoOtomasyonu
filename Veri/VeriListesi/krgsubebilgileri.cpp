#include "krgsubebilgileri.h"

KRGSubeBilgileri::KRGSubeBilgileri(QObject *parent) : QObject(parent)
{

}

IdTuru KRGSubeBilgileri::getId() const
{
    return id;
}

void KRGSubeBilgileri::setId(const IdTuru &value)
{
    if (value == id){
        return;
    }
    id = value;
    emit idDegisti(id);
}

Metin KRGSubeBilgileri::getSubeAdi() const
{
    return subeAdi;
}

void KRGSubeBilgileri::setSubeAdi(const Metin &value)
{
    if (value == subeAdi){
        return;
    }
    subeAdi = value;
    emit subeAdiDegisti(subeAdi);
}

Metin KRGSubeBilgileri::getSubeAdresi() const
{
    return subeAdresi;
}

void KRGSubeBilgileri::setSubeAdresi(const Metin &value)
{
    if (value == subeAdresi){
        return;
    }
    subeAdresi = value;
    emit subeAdresiDegisti(subeAdresi);
}

Metin KRGSubeBilgileri::getSubeTelNo() const
{
    return subeTelNo;
}

void KRGSubeBilgileri::setSubeTelNo(const Metin &value)
{
    if (value == subeTelNo){
        return;
    }
    subeTelNo = value;
    emit subeTelNoDegisti(subeTelNo);
}

Metin KRGSubeBilgileri::getSubeYetkilisi() const
{
    return subeYetkilisi;
}

void KRGSubeBilgileri::setSubeYetkilisi(const Metin &value)
{
    if (value == subeYetkilisi){
        return;
    }
    subeYetkilisi = value;
    emit subeYetkilisiDegisti(subeYetkilisi);
}

QDataStream &operator<<(QDataStream &a, const KRGSubeBilgileriPtr &b)
{
    a << b->getId() << b->getSubeAdi() << b->getSubeAdresi() << b->getSubeTelNo() << b->getSubeYetkilisi();
    return a;
}

QDataStream &operator>>(QDataStream &a, KRGSubeBilgileriPtr &b)
{
    IdTuru id;
    Metin subeAdi, subeAdresi, subeTelNo, subeYetkilisi;

    a >> id >> subeAdi >> subeAdresi >> subeTelNo >> subeYetkilisi;

    b = std::make_shared<KRGSubeBilgileri>();

    b->setId(id);
    b->setSubeAdi(subeAdi);
    b->setSubeAdresi(subeAdresi);
    b->setSubeTelNo(subeTelNo);
    b->setSubeYetkilisi(subeYetkilisi);

    return a;
}
