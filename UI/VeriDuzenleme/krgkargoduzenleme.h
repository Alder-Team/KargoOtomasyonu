#ifndef KRGKARGODUZENLEME_H
#define KRGKARGODUZENLEME_H

#include <QDialog>

namespace Ui {
class KRGKargoDuzenleme;
}

class KRGKargoDuzenleme : public QDialog
{
    Q_OBJECT

public:
    explicit KRGKargoDuzenleme(QWidget *parent = nullptr);
    ~KRGKargoDuzenleme();

private:
    Ui::KRGKargoDuzenleme *ui;
};

#endif // KRGKARGODUZENLEME_H
