#ifndef KRGKARGOBILGILERIYONETICISI_H
#define KRGKARGOBILGILERIYONETICISI_H

#include <QObject>
#include <Veri/tanimlar.h>
#include <QList>
#include <functional>

class KRGKargoBilgileriYoneticisi : public QObject
{
    Q_OBJECT
public:
    typedef KRGKargoBilgileri Veri;
    typedef KRGKargoBilgileriPtr Ptr;
    typedef QList<Ptr> VeriListesi;
    typedef std::function<bool(Ptr)> Sart;

    explicit KRGKargoBilgileriYoneticisi(QObject *parent = nullptr);

    // 1-yeni kargo oluşturur

    Ptr yeni() const;

    // 2-yeni kargoyu listeye ekler

    void ekle(Ptr kargo);

    // 3-kargoyu listeden siler

    void sil(IdTuru kargoId);
    void sil(Ptr kargo);

    // 4-kargonun kopyasını oluşturur

    Ptr kopyaOlustur(Ptr kaynak);

    // 5-kargo arama

    Ptr ilkiniBul(Sart f);
    Ptr sonuncuyuBul(Sart f);
    VeriListesi tumunuBul(Sart f);

signals:

private:
    VeriListesi veriler;
    IdTuru enSonId;

};

#endif // KRGKARGOBILGILERIYONETICISI_H
