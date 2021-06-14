#ifndef KRGKARGODUZENLEME_H
#define KRGKARGODUZENLEME_H
#include <Veri/tanimlar.h>
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

    KRGKargoBilgileriPtr getVeri() const;
    void setVeri(const KRGKargoBilgileriPtr &value);

private:
    Ui::KRGKargoDuzenleme *ui;

    KRGKargoBilgileriPtr veri;
};

#endif // KRGKARGODUZENLEME_H
