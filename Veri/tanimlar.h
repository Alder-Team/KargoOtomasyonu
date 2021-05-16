#ifndef TANIMLAR_H
#define TANIMLAR_H

#include <QByteArray>
#include <QDate>
#include <QDateTime>
#include <QTime>
#include <QtCore>

typedef quint64 IdTuru;
typedef quint32 Tamsayi;

typedef double ReelSayi;

typedef float ParaBirimi;

typedef QString Metin;

typedef QDate Tarih;
typedef QTime Saat;
typedef QDateTime TarihSaat;

typedef enum {
    KTAgirlik = 1,
    KTHacim = 2
} KargoTuru;

typedef enum {
    OTGondericiOdemeli = 1,
    OTAliciOdemeli = 2
} OdemeTuru;

// Pointer tanımları

class KRGKargoBilgileri;
class KRGGondericiBilgileri;
class KRGAliciBilgileri;
class KRGSubeBilgileri;

#include <memory>

typedef std::shared_ptr<KRGKargoBilgileri> KRGKargoBilgileriPtr;
typedef std::shared_ptr<KRGGondericiBilgileri> KRGGondericiBilgileriPtr;
typedef std::shared_ptr<KRGAliciBilgileri> KRGAliciBilgileriPtr;
typedef std::shared_ptr<KRGSubeBilgileri> KRGSubeBilgileriPtr;


QDataStream &operator<<(QDataStream &a, const KRGAliciBilgileriPtr &b);
QDataStream &operator>>(QDataStream &a, KRGAliciBilgileriPtr &b);


QDataStream &operator<<(QDataStream &a, const KRGGondericiBilgileriPtr &b);
QDataStream &operator>>(QDataStream &a, KRGGondericiBilgileriPtr &b);


QDataStream &operator<<(QDataStream &a, const KRGKargoBilgileriPtr &b);
QDataStream &operator>>(QDataStream &a, KRGKargoBilgileriPtr &b);


QDataStream &operator<<(QDataStream &a, const KRGSubeBilgileriPtr &b);
QDataStream &operator>>(QDataStream &a, KRGSubeBilgileriPtr &b);

#endif // TANIMLAR_H
