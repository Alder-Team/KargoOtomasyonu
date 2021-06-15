#ifndef KRGKARGOLISTESI_H
#define KRGKARGOLISTESI_H

#include <QDialog>
#include <Veri/VeriYonetisi/krgkargobilgileriyoneticisi.h>
#include <Veri/VeriYonetisi/krgalicibilgileriyoneticisi.h>
#include <Veri/VeriYonetisi/krggondericibilgileriyoneticisi.h>

namespace Ui {
class KRGKargoListesi;
}

class KRGKargoListesi : public QDialog
{
    Q_OBJECT

public:
    explicit KRGKargoListesi(QWidget *parent = nullptr);
    ~KRGKargoListesi();


    quint64 getAramaAliciId() const;
    quint64 getAramaGondericiId() const;

signals:
    void aramaAliciIdDegisti(quint64 newAramaAliciId);
    void aramaGondericiIdDegisti(quint64 newAramaGondericiId);

public slots:
    void setAramaAliciId(quint64 newAramaAliciId);
    void setAramaGondericiId(quint64 newAramaGondericiId);








private slots:
    void on_pushButtonAra_clicked();

private:
    void listeGuncelle();
    void ara();

    quint64 aramaAliciId;
    quint64 aramaGondericiId;


    Ui::KRGKargoListesi *ui;

    KRGKargoBilgileriYoneticisi::VeriListesi listeKargo;
    KRGAliciBilgileriYoneticisi::VeriListesi listeAlici;
    KRGGondericiBilgileriYoneticisi::VeriListesi listeGonderici;
};

#endif // KRGKARGOLISTESI_H
