#ifndef KRGKARGOLISTESI_H
#define KRGKARGOLISTESI_H

#include <QDialog>
#include <Veri/VeriYonetisi/krgkargobilgileriyoneticisi.h>

namespace Ui {
class KRGKargoListesi;
}

class KRGKargoListesi : public QDialog
{
    Q_OBJECT

public:
    explicit KRGKargoListesi(QWidget *parent = nullptr);
    ~KRGKargoListesi();


private:
    void listeGuncelle();
    void ara();

    Ui::KRGKargoListesi *ui;

    KRGKargoBilgileriYoneticisi::VeriListesi listeKargo;
};

#endif // KRGKARGOLISTESI_H
