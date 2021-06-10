#include "krgsubelistesi.h"
#include "ui_krgsubelistesi.h"

KRGSubeListesi::KRGSubeListesi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KRGSubeListesi)
{
    ui->setupUi(this);
}

KRGSubeListesi::~KRGSubeListesi()
{
    delete ui;
}
