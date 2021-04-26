#ifndef KRGGONDERICIBILGILERI_H
#define KRGGONDERICIBILGILERI_H

#include <QObject>
#include <Veri/tanimlar.h>
#include <QDataStream>

class KRGGondericiBilgileri : public QObject
{
    Q_OBJECT
public:
    explicit KRGGondericiBilgileri(QObject *parent = nullptr);

    Q_PROPERTY(Metin gonderenAdi READ getGonderenAdi WRITE setGonderenAdi NOTIFY gonderenAdiDegisti)
    Q_PROPERTY(Metin gonderenSoyadi READ getGonderenSoyadi WRITE setGonderenSoyadi NOTIFY gonderenSoyadiDegisti)
    Q_PROPERTY(Metin gonderenAdresi READ getGonderenAdresi WRITE setGonderenAdresi NOTIFY gonderenAdresiDegisti)
    Q_PROPERTY(Metin gonderenTelNo READ getGonderenTelNo WRITE setGonderenTelNo NOTIFY gonderenTelNoDegisti)
    Q_PROPERTY(Metin gonderenEmail READ getGonderenEmail WRITE setGonderenEmail NOTIFY gonderenEmailDegisti)
    Q_PROPERTY(IdTuru id READ getId WRITE setId NOTIFY idDegisti)

    Metin getGonderenAdi() const;
    Metin getGonderenSoyadi() const;
    Metin getGonderenAdresi() const;
    Metin getGonderenTelNo() const;
    Metin getGonderenEmail() const;
    IdTuru getId() const;

signals:
    void gonderenAdiDegisti(const Metin &value);
    void gonderenSoyadiDegisti(const Metin &value);
    void gonderenAdresiDegisti(const Metin &value);
    void gonderenTelNoDegisti(const Metin &value);
    void gonderenEmailDegisti(const Metin &value);
    void idDegisti(const IdTuru &value);

public slots:
    void setGonderenAdi(const Metin &value);
    void setGonderenSoyadi(const Metin &value);
    void setGonderenAdresi(const Metin &value);
    void setGonderenTelNo(const Metin &value);
    void setGonderenEmail(const Metin &value);
    void setId(const IdTuru &value);


private:
    Metin gonderenAdi;
    Metin gonderenSoyadi;
    Metin gonderenAdresi;
    Metin gonderenTelNo;
    Metin gonderenEmail;
    IdTuru id;

};
QDataStream &yaz(QDataStream &a, KRGGondericiBilgileriPtr &b);

#endif // KRGGONDERICIBILGILERI_H
