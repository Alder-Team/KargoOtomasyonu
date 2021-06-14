#ifndef KRGKARGOLISTESI_H
#define KRGKARGOLISTESI_H

#include <QDialog>
#include <Veri/VeriYonetisi/krgkargobilgileriyoneticisi.h>
#include <Veri/VeriYonetisi/krgalicibilgileriyoneticisi.h>
#include <Veri/VeriYonetisi/krggondericibilgileriyoneticisi.h>

namespace Ui {
class KRGKargoListesi;
}

class KRGKargoListesi : public QDialog
{
    Q_OBJECT

public:
    explicit KRGKargoListesi(QWidget *parent = nullptr);
    ~KRGKargoListesi();


private slots:
    void on_pushButtonAra_clicked();

private:
    void listeGuncelle();
    void ara();

    Ui::KRGKargoListesi *ui;

    KRGKargoBilgileriYoneticisi::VeriListesi listeKargo;
    KRGAliciBilgileriYoneticisi::VeriListesi listeAlici;
    KRGGondericiBilgileriYoneticisi::VeriListesi listeGonderici;
};

#endif // KRGKARGOLISTESI_H
