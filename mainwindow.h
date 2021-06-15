#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Veri/VeriYonetisi/krgkargobilgileriyoneticisi.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnKargoEkle_clicked();

    void on_btnKargoAra_clicked();

    void on_btnSubeEkle_clicked();

    void on_btnSubeAra_clicked();

    void on_btnKayitliMusteriler_clicked();

private:
    void listeGuncelle();
    void ara();

    Ui::MainWindow *ui;

    KRGKargoBilgileriYoneticisi::VeriListesi liste;
};
#endif // MAINWINDOW_H
