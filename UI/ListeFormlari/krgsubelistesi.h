#ifndef KRGSUBELISTESI_H
#define KRGSUBELISTESI_H

#include <QDialog>

namespace Ui {
class KRGSubeListesi;
}

class KRGSubeListesi : public QDialog
{
    Q_OBJECT

public:
    explicit KRGSubeListesi(QWidget *parent = nullptr);
    ~KRGSubeListesi();

private:
    Ui::KRGSubeListesi *ui;
};

#endif // KRGSUBELISTESI_H
