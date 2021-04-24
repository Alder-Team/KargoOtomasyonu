#ifndef KRGSUBEBILGILERIYONETICISI_H
#define KRGSUBEBILGILERIYONETICISI_H

#include <QObject>
#include <Veri/VeriYonetisi/temel_veri_yoneticisi.h>

class KRGSubeBilgileriYoneticisi : public QObject, public TemelVeriYonetici <KRGSubeBilgileri, KRGSubeBilgileriPtr>
{
    Q_OBJECT
public:
    explicit KRGSubeBilgileriYoneticisi(QObject *parent = nullptr);
    Ptr kopyaOlustur(Ptr kaynak);

signals:

};

#endif // KRGSUBEBILGILERIYONETICISI_H
