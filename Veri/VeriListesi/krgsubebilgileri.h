#ifndef KRGSUBEBILGILERI_H
#define KRGSUBEBILGILERI_H

#include <QObject>
#include <Veri/tanimlar.h>
#include <QDataStream>

class KRGSubeBilgileri : public QObject
{
    Q_OBJECT
public:
    explicit KRGSubeBilgileri(QObject *parent = nullptr);

    Q_PROPERTY(IdTuru id READ getId WRITE setId NOTIFY idDegisti)
    Q_PROPERTY(Metin subeAdi READ getSubeAdi WRITE setSubeAdi NOTIFY subeAdiDegisti)
    Q_PROPERTY(Metin subeAdresi READ getSubeAdresi WRITE setSubeAdresi NOTIFY subeAdresiDegisti)
    Q_PROPERTY(Metin subeTelNo READ getSubeTelNo WRITE setSubeTelNo NOTIFY subeTelNoDegisti)
    Q_PROPERTY(Metin subeYetkilisi READ getSubeYetkilisi WRITE setSubeYetkilisi NOTIFY subeYetkilisiDegisti)

    IdTuru getId() const;
    Metin getSubeAdi() const;
    Metin getSubeAdresi() const;
    Metin getSubeTelNo() const;
    Metin getSubeYetkilisi() const;

signals:
    void idDegisti(const IdTuru &value);
    void subeAdiDegisti(const Metin &value);
    void subeAdresiDegisti(const Metin &value);
    void subeTelNoDegisti(const Metin &value);
    void subeYetkilisiDegisti(const Metin &value);

public slots:
    void setId(const IdTuru &value);
    void setSubeAdi(const Metin &value);
    void setSubeAdresi(const Metin &value);
    void setSubeTelNo(const Metin &value);
    void setSubeYetkilisi(const Metin &value);


private:
    IdTuru id;
    Metin subeAdi;
    Metin subeAdresi;
    Metin subeTelNo;
    Metin subeYetkilisi;
    // Her biri arasındaki uzaklık (eklenecek)

};

QDataStream &operator<<(QDataStream &a, const KRGSubeBilgileriPtr &b);
QDataStream &operator>>(QDataStream &a, KRGSubeBilgileriPtr &b);

#endif // KRGSUBEBILGILERI_H
