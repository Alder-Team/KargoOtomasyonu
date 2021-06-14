#ifndef KRGGONDERICIDUZENLEME_H
#define KRGGONDERICIDUZENLEME_H

#include <QDialog>

namespace Ui {
class KRGGondericiDuzenleme;
}

class KRGGondericiDuzenleme : public QDialog
{
    Q_OBJECT

public:
    explicit KRGGondericiDuzenleme(QWidget *parent = nullptr);
    ~KRGGondericiDuzenleme();

private:
    Ui::KRGGondericiDuzenleme *ui;
};

#endif // KRGGONDERICIDUZENLEME_H
