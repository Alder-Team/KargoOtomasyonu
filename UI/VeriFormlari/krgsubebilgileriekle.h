#ifndef KRGSUBEBILGILERIEKLE_H
#define KRGSUBEBILGILERIEKLE_H

#include <QDialog>

namespace Ui {
class KRGSubeBilgileriEkle;
}

class KRGSubeBilgileriEkle : public QDialog
{
    Q_OBJECT

public:
    explicit KRGSubeBilgileriEkle(QWidget *parent = nullptr);
    ~KRGSubeBilgileriEkle();

private:
    Ui::KRGSubeBilgileriEkle *ui;
};

#endif // KRGSUBEBILGILERIEKLE_H
