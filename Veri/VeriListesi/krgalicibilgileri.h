#ifndef KRGALICIBILGILERI_H
#define KRGALICIBILGILERI_H

#include <QObject>
#include <Veri/tanimlar.h>

class KRGAliciBilgileri : public QObject
{
    Q_OBJECT
public:
    explicit KRGAliciBilgileri(QObject *parent = nullptr);

    Q_PROPERTY(Metin aliciAdi READ getAliciAdi WRITE setAliciAdi NOTIFY aliciAdiDegisti)
    Q_PROPERTY(Metin aliciSoyadi READ getAliciSoyadi WRITE setAliciSoyadi NOTIFY aliciSoyadiDegisti)
    Q_PROPERTY(Metin aliciAdresi READ getAliciAdresi WRITE setAliciAdresi NOTIFY aliciAdresiDegisti)
    Q_PROPERTY(Metin aliciTelNo READ getAliciTelNo WRITE setAliciTelNo NOTIFY aliciTelNoDegisti)
    Q_PROPERTY(Metin aliciEmail READ getAliciEmail WRITE setAliciEmail NOTIFY aliciEmailDegisti)
    Q_PROPERTY(IdTuru aliciFaturaId READ getAliciFaturaId WRITE setAliciFaturaId NOTIFY aliciFaturaIdDegisti)

    Metin getAliciAdi() const;
    Metin getAliciSoyadi() const;
    Metin getAliciAdresi() const;
    Metin getAliciTelNo() const;
    Metin getAliciEmail() const;
    IdTuru getAliciFaturaId() const;

signals:
    void aliciAdiDegisti(const Metin &value);
    void aliciSoyadiDegisti(const Metin &value);
    void aliciAdresiDegisti(const Metin &value);
    void aliciTelNoDegisti(const Metin &value);
    void aliciEmailDegisti(const Metin &value);
    void aliciFaturaIdDegisti(const IdTuru &value);

public slots:
    void setAliciAdi(const Metin &value);
    void setAliciSoyadi(const Metin &value);
    void setAliciAdresi(const Metin &value);
    void setAliciTelNo(const Metin &value);
    void setAliciEmail(const Metin &value);
    void setAliciFaturaId(const IdTuru &value);


private:
    Metin aliciAdi;
    Metin aliciSoyadi;
    Metin aliciAdresi;
    Metin aliciTelNo;
    Metin aliciEmail;
    IdTuru aliciFaturaId;

};

#endif // KRGALICIBILGILERI_H
