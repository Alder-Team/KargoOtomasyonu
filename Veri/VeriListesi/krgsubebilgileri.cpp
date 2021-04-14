#include "krgsubebilgileri.h"

KRGSubeBilgileri::KRGSubeBilgileri(QObject *parent) : QObject(parent)
{

}

IdTuru KRGSubeBilgileri::getSubeId() const
{
    return subeId;
}

void KRGSubeBilgileri::setSubeId(const IdTuru &value)
{
    if (value == subeId){
        return;
    }
    subeId = value;
    emit subeIdDegisti(subeId);
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
