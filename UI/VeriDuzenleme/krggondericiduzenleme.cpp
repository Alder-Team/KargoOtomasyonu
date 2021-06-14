#include "krggondericiduzenleme.h"
#include "ui_krggondericiduzenleme.h"

KRGGondericiDuzenleme::KRGGondericiDuzenleme(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KRGGondericiDuzenleme)
{
    ui->setupUi(this);
}

KRGGondericiDuzenleme::~KRGGondericiDuzenleme()
{
    delete ui;
}
