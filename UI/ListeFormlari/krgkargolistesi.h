#ifndef KRGKARGOLISTESI_H
#define KRGKARGOLISTESI_H

#include <QDialog>

namespace Ui {
class KRGKargoListesi;
}

class KRGKargoListesi : public QDialog
{
    Q_OBJECT

public:
    explicit KRGKargoListesi(QWidget *parent = nullptr);
    ~KRGKargoListesi();

private:
    Ui::KRGKargoListesi *ui;
};

#endif // KRGKARGOLISTESI_H
