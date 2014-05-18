#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H

#include <QMainWindow>
#include <QPointer>
#include <QMessageBox>

namespace Ui {
class VentanaPrincipal;
}

class QComboBox;
class VentanaPrincipal : public QMainWindow
{
    Q_OBJECT
    QList<QPointer <QComboBox> > opciones;
    QList <qintptr <QComboBox> > iopn;

public:
    explicit VentanaPrincipal(QWidget *parent = 0);
    ~VentanaPrincipal();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::VentanaPrincipal *ui;
};

#endif // VENTANAPRINCIPAL_H
