#include "krgkargolistesi.h"
#include "ui_krgkargolistesi.h"

KRGKargoListesi::KRGKargoListesi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KRGKargoListesi)
{
    ui->setupUi(this);
}

KRGKargoListesi::~KRGKargoListesi()
{
    delete ui;
}
