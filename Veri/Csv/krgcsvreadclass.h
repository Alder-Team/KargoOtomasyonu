#ifndef KRGCSVREADCLASS_H
#define KRGCSVREADCLASS_H

#include <QObject>
#include <QString>
#include <QFile>
#include <QDebug>

class KRGCsvReadClass : public QObject
{
    Q_OBJECT
public:
    explicit KRGCsvReadClass(QObject *parent = nullptr);

    int mesafe(int ilkIl, int digerIlk);


signals:

};

#endif // KRGCSVREADCLASS_H
