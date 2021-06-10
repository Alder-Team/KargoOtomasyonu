#include "krgyenikargoekle.h"
#include "ui_krgyenikargoekle.h"

KRGYeniKargoEkle::KRGYeniKargoEkle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KRGYeniKargoEkle)
{
    ui->setupUi(this);
}

KRGYeniKargoEkle::~KRGYeniKargoEkle()
{
    delete ui;
}
