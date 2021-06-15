#ifndef KRGKAYITLIMUSTERILER_H
#define KRGKAYITLIMUSTERILER_H

#include <QDialog>
#include <Veri/VeriYonetisi/krgalicibilgileriyoneticisi.h>
#include <Veri/VeriYonetisi/krggondericibilgileriyoneticisi.h>


namespace Ui {
class KRGKayitliMusteriler;
}

class KRGKayitliMusteriler : public QDialog
{
    Q_OBJECT

public:
    explicit KRGKayitliMusteriler(QWidget *parent = nullptr);
    ~KRGKayitliMusteriler();



private slots:
    void on_pushButtonAra_clicked();
    void ara();

private:
    void listeGuncelle();
    void arama_yap();

    Ui::KRGKayitliMusteriler *ui;
    KRGAliciBilgileriYoneticisi::VeriListesi listeAlici;
    KRGGondericiBilgileriYoneticisi::VeriListesi listeGonderici;

};

#endif // KRGKAYITLIMUSTERILER_H
