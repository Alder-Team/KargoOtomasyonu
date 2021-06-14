#include "krgkargoduzenleme.h"
#include "ui_krgkargoduzenleme.h"

KRGKargoDuzenleme::KRGKargoDuzenleme(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KRGKargoDuzenleme)
{
    ui->setupUi(this);
}

KRGKargoDuzenleme::~KRGKargoDuzenleme()
{
    delete ui;
}
