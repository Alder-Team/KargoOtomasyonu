#include "krggenelveriyoneticisi.h"

KRGGenelVeriYoneticisi::KRGGenelVeriYoneticisi(QObject *parent) : QObject(parent)
{

}

KRGGenelVeriYoneticisi &KRGGenelVeriYoneticisi::db()
{
    static KRGGenelVeriYoneticisi nesne;
    return nesne;
}

KRGAliciBilgileriYoneticisi &KRGGenelVeriYoneticisi::getAliciBilgileri()
{
    return aliciBilgileri;
}

KRGGondericiBilgileriYoneticisi &KRGGenelVeriYoneticisi::getGondericiBilgileri()
{
    return gondericiBilgileri;
}

KRGKargoBilgileriYoneticisi &KRGGenelVeriYoneticisi::getKargoBilgileri()
{
    return kargoBilgileri;
}

KRGSubeBilgileriYoneticisi &KRGGenelVeriYoneticisi::getSubeBilgileri()
{
    return subeBilgileri;
}

QDataStream &operator<<(QDataStream &a, KRGGenelVeriYoneticisi &b)
{
    a << b.subeBilgileri << b.aliciBilgileri << b.gondericiBilgileri << b.kargoBilgileri;
    return a;

}

QDataStream &operator>>(QDataStream &a, KRGGenelVeriYoneticisi &b)
{
    a >> b.subeBilgileri >> b.aliciBilgileri >> b.gondericiBilgileri >> b.kargoBilgileri;
    return a;
}
