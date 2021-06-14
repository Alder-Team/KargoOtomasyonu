#include "mainwindow.h"

#include <QApplication>

#include <Veri/Csv/krgcsvreadclass.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    KRGCsvReadClass r;
    qDebug() << r.mesafe(2,68);
    w.show();
    return a.exec();



}
