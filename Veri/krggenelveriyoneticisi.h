#ifndef KRGGENELVERIYONETICISI_H
#define KRGGENELVERIYONETICISI_H

#include <QObject>
#include <Veri/VeriYonetisi/krgalicibilgileriyoneticisi.h>
#include <Veri/VeriYonetisi/krggondericibilgileriyoneticisi.h>
#include <Veri/VeriYonetisi/krgkargobilgileriyoneticisi.h>
#include <Veri/VeriYonetisi/krgsubebilgileriyoneticisi.h>

class KRGGenelVeriYoneticisi : public QObject
{
    Q_OBJECT
private:
    explicit KRGGenelVeriYoneticisi(QObject *parent = nullptr);


public:

    static KRGGenelVeriYoneticisi &db();

    KRGAliciBilgileriYoneticisi &getAliciBilgileri();
    KRGGondericiBilgileriYoneticisi &getGondericiBilgileri();
    KRGKargoBilgileriYoneticisi &getKargoBilgileri();
    KRGSubeBilgileriYoneticisi &getSubeBilgileri();

signals:

private:
    KRGAliciBilgileriYoneticisi aliciBilgileri;
    KRGGondericiBilgileriYoneticisi gondericiBilgileri;
    KRGKargoBilgileriYoneticisi kargoBilgileri;
    KRGSubeBilgileriYoneticisi subeBilgileri;

    friend QDataStream &operator<<(QDataStream &a, KRGGenelVeriYoneticisi &b);
    friend QDataStream &operator>>(QDataStream &a, KRGGenelVeriYoneticisi &b);


};

QDataStream &operator<<(QDataStream a, KRGGenelVeriYoneticisi &b);
QDataStream &operator>>(QDataStream &a, KRGGenelVeriYoneticisi &b);

#endif // KRGGENELVERIYONETICISI_H
