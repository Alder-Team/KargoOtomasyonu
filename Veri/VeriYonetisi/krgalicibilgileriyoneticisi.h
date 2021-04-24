#ifndef KRGALICIBILGILERIYONETICISI_H
#define KRGALICIBILGILERIYONETICISI_H

#include <QObject>
#include <Veri/VeriYonetisi/temel_veri_yoneticisi.h>

class KRGAliciBilgileriYoneticisi : public QObject,
                                    public TemelVeriYonetici <KRGAliciBilgileri, KRGAliciBilgileriPtr>
{
    Q_OBJECT
public:
    explicit KRGAliciBilgileriYoneticisi(QObject *parent = nullptr);

    // Kopya oluşturur.
    Ptr kopyaOlustur(Ptr kaynak);

signals:

};

#endif // KRGALICIBILGILERIYONETICISI_H
