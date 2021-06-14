#ifndef KRGALICIDUZENLEME_H
#define KRGALICIDUZENLEME_H

#include <QDialog>
#include <Veri/tanimlar.h>

namespace Ui {
class KRGAliciDuzenleme;
}

class KRGAliciDuzenleme : public QDialog
{
    Q_OBJECT

public:
    explicit KRGAliciDuzenleme(QWidget *parent = nullptr);
    ~KRGAliciDuzenleme();

    KRGAliciBilgileriPtr getVeri() const;
    void setVeri(const KRGAliciBilgileriPtr &value);

private:
    Ui::KRGAliciDuzenleme *ui;

    KRGAliciBilgileriPtr veri;
};

#endif // KRGALICIDUZENLEME_H
