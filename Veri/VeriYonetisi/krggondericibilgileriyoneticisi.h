#ifndef KRGGONDERICIBILGILERIYONETICISI_H
#define KRGGONDERICIBILGILERIYONETICISI_H

#include <Veri/VeriYonetisi/temel_veri_yoneticisi.h>
#include <QObject>

class KRGGondericiBilgileriYoneticisi : public QObject, public TemelVeriYonetici <KRGGondericiBilgileri, KRGGondericiBilgileriPtr>
{
    Q_OBJECT
public:
    explicit KRGGondericiBilgileriYoneticisi(QObject *parent = nullptr);

    // Kopya Oluşturma

    Ptr kopyaOlustur(Ptr kaynak);

signals:

};

#endif // KRGGONDERICIBILGILERIYONETICISI_H
