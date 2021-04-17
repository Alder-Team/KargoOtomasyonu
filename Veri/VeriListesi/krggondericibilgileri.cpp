#include "krggondericibilgileri.h"

KRGGondericiBilgileri::KRGGondericiBilgileri(QObject *parent) : QObject(parent)
{

}

Metin KRGGondericiBilgileri::getGonderenAdi() const
{
    return gonderenAdi;
}

void KRGGondericiBilgileri::setGonderenAdi(const Metin &value)
{
    if (value == gonderenAdi){
        return;
    }
    gonderenAdi = value;
    emit gonderenAdiDegisti(gonderenAdi);
}

Metin KRGGondericiBilgileri::getGonderenSoyadi() const
{
    return gonderenSoyadi;
}

void KRGGondericiBilgileri::setGonderenSoyadi(const Metin &value)
{
    if (value == gonderenSoyadi){
        return;
    }
    gonderenSoyadi = value;
    emit gonderenSoyadiDegisti(gonderenSoyadi);
}

Metin KRGGondericiBilgileri::getGonderenAdresi() const
{
    return gonderenAdresi;
}

void KRGGondericiBilgileri::setGonderenAdresi(const Metin &value)
{
    if (value == gonderenAdresi){
        return;
    }
    gonderenAdresi = value;
    emit gonderenAdresiDegisti(gonderenAdresi);
}

Metin KRGGondericiBilgileri::getGonderenTelNo() const
{
    return gonderenTelNo;
}

void KRGGondericiBilgileri::setGonderenTelNo(const Metin &value)
{
    if (value == gonderenTelNo){
        return;
    }
    gonderenTelNo = value;
    emit gonderenTelNoDegisti(gonderenTelNo);
}

Metin KRGGondericiBilgileri::getGonderenEmail() const
{
    return gonderenEmail;
}

void KRGGondericiBilgileri::setGonderenEmail(const Metin &value)
{
    if (value == gonderenEmail){
        return;
    }
    gonderenEmail = value;
    emit gonderenEmailDegisti(gonderenEmail);
}

IdTuru KRGGondericiBilgileri::getId() const
{
    return id;
}

void KRGGondericiBilgileri::setId(const IdTuru &value)
{
    if (value == id){
        return;
    }
    id = value;
    emit idDegisti(id);
}
