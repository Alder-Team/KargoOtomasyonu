#ifndef KRGKARGOBILGILERIYONETICISI_H
#define KRGKARGOBILGILERIYONETICISI_H

#include <QObject>
#include <Veri/tanimlar.h>
#include <Veri/VeriYonetisi/temel_veri_yoneticisi.h>

class KRGKargoBilgileriYoneticisi : public QObject, public TemelVeriYonetici<KRGKargoBilgileri, KRGKargoBilgileriPtr>
{
    Q_OBJECT
public:

    explicit KRGKargoBilgileriYoneticisi(QObject *parent = nullptr);

    // 4-kargonun kopyasını oluşturur
    Ptr kopyaOlustur(Ptr kaynak);

signals:

private:

};

#endif // KRGKARGOBILGILERIYONETICISI_H
