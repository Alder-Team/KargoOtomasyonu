#ifndef KRGALICIDUZENLEME_H
#define KRGALICIDUZENLEME_H

#include <QDialog>

namespace Ui {
class KRGAliciDuzenleme;
}

class KRGAliciDuzenleme : public QDialog
{
    Q_OBJECT

public:
    explicit KRGAliciDuzenleme(QWidget *parent = nullptr);
    ~KRGAliciDuzenleme();

private:
    Ui::KRGAliciDuzenleme *ui;
};

#endif // KRGALICIDUZENLEME_H
