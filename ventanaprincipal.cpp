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

            const int ultima_fila2 = ui->tableWidget_2->rowCount();
            ui->tableWidget_2->insertRow((ultima_fila2));
            const int ultima_columna2 = ui->tableWidget_2->columnCount();
            ui->tableWidget_2->insertColumn((ultima_columna2));

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

}

void VentanaPrincipal::on_pushButton_3_clicked()
{
    int tam= ui->lineEdit->text().toInt();
    int matriz[tam][tam];
    int a=99;
    QString temp="";
    QTableWidgetItem *p;

    for(int i=0; i < tam ;i++){
        for(int j=0; j < tam ;j++){
            p = ui->tableWidget->(i,j);
            //matriz[i][j]= p->text().toInt();
            temp+=p->text();
        }
        temp+="\n";
    }
    QMessageBox::information(this,"Matriz capturada",temp);
}
