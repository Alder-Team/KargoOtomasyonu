#ifndef KRGKARGOBILGILERI_H
#define KRGKARGOBILGILERI_H

#include <QObject>
#include <Veri/tanimlar.h>
#include <QDataStream>

class KRGKargoBilgileri : public QObject
{
    Q_OBJECT
public:
    explicit KRGKargoBilgileri(QObject *parent = nullptr);

    Q_PROPERTY(IdTuru id READ getId WRITE setId NOTIFY idDegisti)
    Q_PROPERTY(Tarih kargoTarihi READ getKargoTarihi WRITE setKargoTarihi NOTIFY kargoTarihiDegisti)
    Q_PROPERTY(KargoTuru kargoTuru READ getKargoTuru WRITE setKargoTuru NOTIFY kargoTuruDegisti)
    Q_PROPERTY(OdemeTuru odemeTuru READ getOdemeTuru WRITE setOdemeTuru NOTIFY odemeTuruDegisti)
    Q_PROPERTY(Metin gonderenSube READ getGonderenSube WRITE setGonderenSube NOTIFY gonderenSubeDegisti)
    Q_PROPERTY(Metin aliciSube READ getAliciSube WRITE setAliciSube NOTIFY aliciSubeDegisti)
    Q_PROPERTY(ParaBirimi kargoUcreti READ getKargoUcreti WRITE setKargoUcreti NOTIFY kargoUcretiDegisti)

    IdTuru getId() const;
    Tarih getKargoTarihi() const;
    KargoTuru getKargoTuru() const;
    OdemeTuru getOdemeTuru() const;
    Metin getGonderenSube() const;
    Metin getAliciSube() const;
    ParaBirimi getKargoUcreti() const;

signals:
    void idDegisti(const IdTuru &value);
    void kargoTarihiDegisti(const Tarih &value);
    void kargoTuruDegisti(const KargoTuru &value);
    void odemeTuruDegisti(const OdemeTuru &value);
    void gonderenSubeDegisti(const Metin &value);
    void aliciSubeDegisti(const Metin &value);
    void kargoUcretiDegisti(const ParaBirimi &value);

public slots:
    void setId(const IdTuru &value);
    void setKargoTarihi(const Tarih &value);
    void setKargoTuru(const KargoTuru &value);
    void setOdemeTuru(const OdemeTuru &value);
    void setGonderenSube(const Metin &value);
    void setAliciSube(const Metin &value);
    void setKargoUcreti(const ParaBirimi &value);

private:

    IdTuru id;
    Tarih kargoTarihi;
    KargoTuru kargoTuru;
    OdemeTuru odemeTuru;
    Metin gonderenSube;
    Metin aliciSube;
    ParaBirimi kargoUcreti;


};

QDataStream &operator<<(QDataStream &a, const KRGKargoBilgileriPtr &b);
QDataStream &operator>>(QDataStream &a, KRGKargoBilgileriPtr &b);

#endif // KRGKARGOBILGILERI_H
