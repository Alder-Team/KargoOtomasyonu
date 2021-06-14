#ifndef KRGSUBELISTESI_H
#define KRGSUBELISTESI_H


#include <QDialog>
#include <Veri/VeriYonetisi/krgsubebilgileriyoneticisi.h>

namespace Ui {
class KRGSubeListesi;
}

class KRGSubeListesi : public QDialog
{
    Q_OBJECT

public:
    explicit KRGSubeListesi(QWidget *parent = nullptr);
    ~KRGSubeListesi();


private slots:
    void on_pushButtonAra_clicked();
    void ara();

private:
    void arama_yap();
    void listeGuncelle();


    Ui::KRGSubeListesi *ui;

    KRGSubeBilgileriYoneticisi::VeriListesi listeSube;
};

#endif // KRGSUBELISTESI_H
