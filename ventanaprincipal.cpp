#include "ventanaprincipal.h"
#include "ui_ventanaprincipal.h"
#include <QComboBox>

VentanaPrincipal::VentanaPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VentanaPrincipal)
{
    ui->setupUi(this);
}

VentanaPrincipal::~VentanaPrincipal()
{
    delete ui;
}

void VentanaPrincipal::on_pushButton_clicked()
{

    int tam=0;
    tam = (ui->lineEdit->text()).toInt();
    ui->lineEdit->setDisabled(true);
    ui->pushButton->setDisabled(true);


    if(tam>=2 && tam<= 10)
    {
        ui->tableWidget->setEnabled(true);
        ui->pushButton_2->setEnabled(true);

        for(int i=0; i < tam ;i++){

            const int ultima_fila = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow((ultima_fila));
            const int ultima_columna = ui->tableWidget->columnCount();
            ui->tableWidget->insertColumn((ultima_columna));

        }

        for(int i=0; i < tam ;i++){

            for(int j=0; j < tam ;j++){
                QPointer<QComboBox> mi_lista= new QComboBox(this);
                QStringList valores;
                valores<<"-Elejir opción-"
                       <<"0"
                       <<"1";
                opciones.append(mi_lista);
                mi_lista->addItems(valores);
                ui->tableWidget->setCellWidget(i,j,mi_lista);
            }
           // break;
        }

    }else{
        QMessageBox::information(this,"ERROR","Tamaño no valido.");
    }
}

void VentanaPrincipal::on_pushButton_2_clicked()
{
    int tam= ui->lineEdit->text().toInt();
    int matriz[tam][tam];
    int a=99;
    QTableWidgetItem *p;

    for(int i=0; i < tam ;i++){
        for(int j=0; j < tam ;j++){
            p= ui->tableWidget->item(i,j);
            matriz[i][j]= ;
        }
    }
    //a=matriz[1][0];
    //QString s=(QString)a;

    //QMessageBox::information(this,"Matriz capturada",s);
}
