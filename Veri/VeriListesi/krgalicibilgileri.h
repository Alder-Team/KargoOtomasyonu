#ifndef KRGALICIBILGILERI_H
#define KRGALICIBILGILERI_H

#include <QObject>
#include <Veri/tanimlar.h>
#include <QDataStream>

class KRGAliciBilgileri : public QObject
{
    Q_OBJECT
public:
    explicit KRGAliciBilgileri(QObject *parent = nullptr);

    Q_PROPERTY(Metin aliciAdi READ getAliciAdi WRITE setAliciAdi NOTIFY aliciAdiDegisti)
    Q_PROPERTY(Metin aliciAdresi READ getAliciAdresi WRITE setAliciAdresi NOTIFY aliciAdresiDegisti)
    Q_PROPERTY(Metin aliciTelNo READ getAliciTelNo WRITE setAliciTelNo NOTIFY aliciTelNoDegisti)
    Q_PROPERTY(Metin aliciEmail READ getAliciEmail WRITE setAliciEmail NOTIFY aliciEmailDegisti)
    Q_PROPERTY(IdTuru id READ getId WRITE setId NOTIFY idDegisti)

    Metin getAliciAdi() const;
    Metin getAliciAdresi() const;
    Metin getAliciTelNo() const;
    Metin getAliciEmail() const;
    IdTuru getId() const;

signals:
    void aliciAdiDegisti(const Metin &value);
    void aliciAdresiDegisti(const Metin &value);
    void aliciTelNoDegisti(const Metin &value);
    void aliciEmailDegisti(const Metin &value);
    void idDegisti(const IdTuru &value);

public slots:
    void setAliciAdi(const Metin &value);
    void setAliciAdresi(const Metin &value);
    void setAliciTelNo(const Metin &value);
    void setAliciEmail(const Metin &value);
    void setId(const IdTuru &value);


private:
    Metin aliciAdi;
    Metin aliciAdresi;
    Metin aliciTelNo;
    Metin aliciEmail;
    IdTuru id;

};

QDataStream &operator<<(QDataStream &a, const KRGAliciBilgileriPtr &b);
QDataStream &operator>>(QDataStream &a, KRGAliciBilgileriPtr &b);

#endif // KRGALICIBILGILERI_H
