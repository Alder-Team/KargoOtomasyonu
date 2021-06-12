#ifndef KRGSUBEBILGILERIEKLE_H
#define KRGSUBEBILGILERIEKLE_H

#include <QDialog>
#include <Veri/tanimlar.h>

namespace Ui {
class KRGSubeBilgileriEkle;
}

class KRGSubeBilgileriEkle : public QDialog
{
    Q_OBJECT

public:
    explicit KRGSubeBilgileriEkle(QWidget *parent = nullptr);
    ~KRGSubeBilgileriEkle();


    KRGSubeBilgileriPtr getVeri() const;
    void setVeri(const KRGSubeBilgileriPtr &value);

private:
    Ui::KRGSubeBilgileriEkle *ui;

    KRGSubeBilgileriPtr veri;

};

#endif // KRGSUBEBILGILERIEKLE_H
