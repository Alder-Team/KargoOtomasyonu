#include "krgcsvreadclass.h"

KRGCsvReadClass::KRGCsvReadClass(QObject *parent) : QObject(parent)
{

}

int KRGCsvReadClass::mesafe(int ilkIl, int digerIlk)
{
    QFile file(":/new/csv/out.csv");
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << file.errorString();
        return 1;
    }

    QStringList ilk;
    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        ilk.append(line.split(',')[ilkIl + 1]);
    }

    return ilk[digerIlk].toInt();
}
