#ifndef KRGGONDERICIDUZENLEME_H
#define KRGGONDERICIDUZENLEME_H

#include <QDialog>
#include <Veri/tanimlar.h>

namespace Ui {
class KRGGondericiDuzenleme;
}

class KRGGondericiDuzenleme : public QDialog
{
    Q_OBJECT

public:
    explicit KRGGondericiDuzenleme(QWidget *parent = nullptr);
    ~KRGGondericiDuzenleme();

    KRGGondericiBilgileriPtr getVeri() const;
    void setVeri(const KRGGondericiBilgileriPtr &value);

private:
    Ui::KRGGondericiDuzenleme *ui;

    KRGGondericiBilgileriPtr veri;


};

#endif // KRGGONDERICIDUZENLEME_H
