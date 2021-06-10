#include "krgsubebilgileriekle.h"
#include "ui_krgsubebilgileriekle.h"

KRGSubeBilgileriEkle::KRGSubeBilgileriEkle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KRGSubeBilgileriEkle)
{
    ui->setupUi(this);
}

KRGSubeBilgileriEkle::~KRGSubeBilgileriEkle()
{
    delete ui;
}
