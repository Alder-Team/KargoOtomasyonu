#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <UI/VeriFormlari/krgyenikargoekle.h>
#include <UI/VeriFormlari/krgsubebilgileriekle.h>
#include <UI/ListeFormlari/krgsubelistesi.h>
#include <UI/ListeFormlari/krgkargolistesi.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnKargoEkle_clicked()
{
    KRGYeniKargoEkle form;
    form.exec();
}


void MainWindow::on_btnKargoAra_clicked()
{
    KRGKargoListesi form;
    form.exec();
}


void MainWindow::on_btnSubeEkle_clicked()
{
    KRGSubeBilgileriEkle form;
    form.exec();
}


void MainWindow::on_btnSubeAra_clicked()
{
    KRGSubeListesi form;
    form.exec();
}

