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
    Q_PROPERTY(ReelSayi kargoEn READ getKargoEn WRITE setKargoEn NOTIFY kargoEnDegisti)
    Q_PROPERTY(ReelSayi kargoBoy READ getKargoBoy WRITE setKargoBoy NOTIFY kargoBoyDegisti)
    Q_PROPERTY(ReelSayi kargoYukseklik READ getKargoYukseklik WRITE setKargoYukseklik NOTIFY kargoYukseklikDegisti)
    Q_PROPERTY(ReelSayi kargoAgirlik READ getKargoAgirlik WRITE setKargoAgirlik NOTIFY kargoAgirlikDegisti)
    Q_PROPERTY(ReelSayi kargoDesi READ getKargoDesi WRITE setKargoDesi NOTIFY kargoDesiDegisti)
    Q_PROPERTY(IdTuru aliciId READ getAliciId WRITE setAliciId NOTIFY aliciIdDegisti)
    Q_PROPERTY(IdTuru gondericiId READ getGondericiId WRITE setGondericiId NOTIFY gondericiIdDegisti)

    IdTuru getId() const;
    Tarih getKargoTarihi() const;
    KargoTuru getKargoTuru() const;
    OdemeTuru getOdemeTuru() const;
    Metin getGonderenSube() const;
    Metin getAliciSube() const;
    ParaBirimi getKargoUcreti() const;
    ReelSayi getKargoEn() const;
    ReelSayi getKargoBoy() const;
    ReelSayi getKargoYukseklik() const;
    ReelSayi getKargoDesi() const;
    ReelSayi getKargoAgirlik() const;
    IdTuru getAliciId() const;
    IdTuru getGondericiId() const;

signals:

    void idDegisti(const IdTuru &value);
    void kargoTarihiDegisti(const Tarih &value);
    void kargoTuruDegisti(const KargoTuru &value);
    void odemeTuruDegisti(const OdemeTuru &value);
    void gonderenSubeDegisti(const Metin &value);
    void aliciSubeDegisti(const Metin &value);
    void kargoUcretiDegisti(const ParaBirimi &value);
    void kargoEnDegisti(const ReelSayi &value);
    void kargoBoyDegisti(const ReelSayi &value);
    void kargoYukseklikDegisti(const ReelSayi &value);
    void kargoDesiDegisti(const ReelSayi &value);
    void kargoAgirlikDegisti(const ReelSayi &value);
    void aliciIdDegisti(const IdTuru &value);
    void gondericiIdDegisti(const IdTuru &value);

public slots:

    void setId(const IdTuru &value);
    void setKargoTarihi(const Tarih &value);
    void setKargoTuru(const KargoTuru &value);
    void setOdemeTuru(const OdemeTuru &value);
    void setGonderenSube(const Metin &value);
    void setAliciSube(const Metin &value);
    void setKargoUcreti(const ParaBirimi &value);
    void setKargoEn(const ReelSayi &value);
    void setKargoBoy(const ReelSayi &value);
    void setKargoYukseklik(const ReelSayi &value);
    void setKargoDesi(const ReelSayi &value);
    void setKargoAgirlik(const ReelSayi &value);
    void setAliciId(const IdTuru &value);
    void setGondericiId(const IdTuru &value);

private:

    IdTuru id;
    IdTuru aliciId;
    IdTuru gondericiId;
    Tarih kargoTarihi;
    KargoTuru kargoTuru;
    OdemeTuru odemeTuru;
    Metin gonderenSube;
    Metin aliciSube;
    ParaBirimi kargoUcreti;

    ReelSayi kargoEn;
    ReelSayi kargoBoy;
    ReelSayi kargoYukseklik;
    ReelSayi kargoAgirlik;
    ReelSayi kargoDesi;


};

QDataStream &operator<<(QDataStream &a, const KRGKargoBilgileriPtr &b);
QDataStream &operator>>(QDataStream &a, KRGKargoBilgileriPtr &b);

#endif // KRGKARGOBILGILERI_H
