#ifndef KRGYENIKARGOEKLE_H
#define KRGYENIKARGOEKLE_H

#include <QDialog>

namespace Ui {
class KRGYeniKargoEkle;
}

class KRGYeniKargoEkle : public QDialog
{
    Q_OBJECT

public:
    explicit KRGYeniKargoEkle(QWidget *parent = nullptr);
    ~KRGYeniKargoEkle();

private:
    Ui::KRGYeniKargoEkle *ui;
};

#endif // KRGYENIKARGOEKLE_H
