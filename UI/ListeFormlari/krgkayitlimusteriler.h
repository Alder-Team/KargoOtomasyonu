#ifndef KRGKAYITLIMUSTERILER_H
#define KRGKAYITLIMUSTERILER_H

#include <QDialog>

namespace Ui {
class KRGKayitliMusteriler;
}

class KRGKayitliMusteriler : public QDialog
{
    Q_OBJECT

public:
    explicit KRGKayitliMusteriler(QWidget *parent = nullptr);
    ~KRGKayitliMusteriler();

private:
    Ui::KRGKayitliMusteriler *ui;
};

#endif // KRGKAYITLIMUSTERILER_H
