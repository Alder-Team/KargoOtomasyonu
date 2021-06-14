#include "krgkayitlimusteriler.h"
#include "ui_krgkayitlimusteriler.h"

KRGKayitliMusteriler::KRGKayitliMusteriler(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KRGKayitliMusteriler)
{
    ui->setupUi(this);

}

KRGKayitliMusteriler::~KRGKayitliMusteriler()
{
    delete ui;
}
