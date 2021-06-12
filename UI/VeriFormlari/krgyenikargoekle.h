#ifndef KRGYENIKARGOEKLE_H
#define KRGYENIKARGOEKLE_H

#include <QDialog>
#include <Veri/tanimlar.h>

namespace Ui {
class KRGYeniKargoEkle;
}

class KRGYeniKargoEkle : public QDialog
{
    Q_OBJECT

public:
    explicit KRGYeniKargoEkle(QWidget *parent = nullptr);
    ~KRGYeniKargoEkle();

//    KRGKargoBilgileriPtr getVeri() const;
//    void setVeri(const KRGKargoBilgileriPtr &value);

    KRGKargoBilgileriPtr getVeriKargo() const;
    void setVeriKargo(const KRGKargoBilgileriPtr &value);

    KRGGondericiBilgileriPtr getVeriGonderici() const;
    void setVeriGonderici(const KRGGondericiBilgileriPtr &value);

    KRGAliciBilgileriPtr getVeriAlici() const;
    void setVeriAlici(const KRGAliciBilgileriPtr &value);

private:
    Ui::KRGYeniKargoEkle *ui;

    KRGKargoBilgileriPtr veriKargo;
    KRGGondericiBilgileriPtr veriGonderici;
    KRGAliciBilgileriPtr veriAlici;
};

#endif // KRGYENIKARGOEKLE_H
