#include "krgaliciduzenleme.h"
#include "ui_krgaliciduzenleme.h"

KRGAliciDuzenleme::KRGAliciDuzenleme(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KRGAliciDuzenleme)
{
    ui->setupUi(this);
}

KRGAliciDuzenleme::~KRGAliciDuzenleme()
{
    delete ui;
}
