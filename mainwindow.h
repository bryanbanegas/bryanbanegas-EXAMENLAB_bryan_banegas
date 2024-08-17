#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "reserva.h"
#include "mesa.h"
#include "QVector"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_disponibilidad_clicked();

    void on_disponibilidad_2_clicked();

    void on_cancelar_clicked();

    void on_modificar_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_reservacionesList_clicked();

    void on_pushButton_6_clicked();

    void on_mesas_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::MainWindow *ui;
    QMessageBox mensaje;
    QVector<reserva*> reservaciones;
    QVector<mesa*> mesas;
};
#endif // MAINWINDOW_H
