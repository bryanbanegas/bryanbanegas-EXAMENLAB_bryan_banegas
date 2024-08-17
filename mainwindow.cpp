#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QString n="1";
    int a=2;
    mesa* nuevaMesa1=new mesa(n,a);
    mesas.append(nuevaMesa1);
    n="2";
    a=4;
    nuevaMesa1=new mesa(n,a);
    mesas.append(nuevaMesa1);
    n="3";
    a=5;
    nuevaMesa1=new mesa(n,a);
    mesas.append(nuevaMesa1);
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int tipo=0, codigo=0;
void MainWindow::on_pushButton_clicked()
{
    tipo=1;
    ui->reservacionesList->setVisible(false);
    ui->textEdit_2->setVisible(false);
}


void MainWindow::on_pushButton_2_clicked()
{
    tipo=0;
    ui->reservacionesList->setVisible(true);
    ui->textEdit_2->setVisible(true);
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
}


void MainWindow::on_tabWidget_currentChanged(int index)
{
    if(index==1){
        if(tipo==0){
            ui->tabWidget->setCurrentIndex(0);
            mensaje.setWindowTitle("Mensaje");
            mensaje.setText("Solo un cliente puede hacer una reservacion.");
            mensaje.exec();
        }
    }else if(index==3){
        if(tipo==1){
            ui->tabWidget->setCurrentIndex(0);
            mensaje.setWindowTitle("Mensaje");
            mensaje.setText("Solo un administrador puede crear o eliminar mesas.");
            mensaje.exec();
        }
    }
}


void MainWindow::on_disponibilidad_clicked()
{
    QString info="";
    for(int i=0;i<mesas.size();i++){
        if(!mesas.at(i)->ifReservada()){
            info+=mesas.at(i)->getInfo();
        }
    }
    ui->textEdit->setText(info);
}


void MainWindow::on_disponibilidad_2_clicked()
{
    QString nombre=ui->nombreLine->text();
    QString numeroDeContacto=ui->contactoLine->text();
    int numeroDeComensales=ui->comensalesLine->text().toInt();
    QString fecha=ui->fechaLine->text();
    int hora=ui->horaLine->text().toInt();
    QString mesaActual=ui->mesaLine->text();
    mesa* nuevaMesa;
    bool existe=false;
    for(int i=0;i<mesas.size();i++){
        if(!mesas.at(i)->ifReservada()){
            if(mesaActual==mesas.at(i)->getNumeroDeMesa()){
                if(numeroDeComensales<=mesas.at(i)->getNumeroDeSillas()){
                    nuevaMesa=mesas.at(i);
                    mesas.at(i)->reservar();
                    existe=true;
                    break;
                }
            }
        }
    }

    if(existe){
        codigo++;
        reserva* nuevaReserva=new reserva(codigo, nombre, numeroDeContacto, numeroDeComensales, fecha, hora, nuevaMesa);
        reservaciones.append(nuevaReserva);
        mensaje.setWindowTitle("Mensaje");
        mensaje.setText("Creo su reservacion con exito. Su codigo es: "+QString::number(codigo));
        mensaje.exec();
    }else{
        mensaje.setWindowTitle("Mensaje");
        mensaje.setText("La mesa no existe o ya a sido reservada.");
        mensaje.exec();
    }
}


void MainWindow::on_cancelar_clicked()
{
    bool cancelar=false;
    QString reservacionCancelar=ui->reservacionLine->text();
    for(int i=0;i<reservaciones.size();i++){
        if(reservacionCancelar==QString::number(reservaciones.at(i)->getCodigo())){
            reserva* eliminar=reservaciones.at(i);
            delete eliminar;
            reservaciones.removeAt(i);
            cancelar=true;
            break;
        }
    }

    if(cancelar){
        mensaje.setWindowTitle("Mensaje");
        mensaje.setText("Se cancelo la reservacion con exito.");
        mensaje.exec();
    }else{
        mensaje.setWindowTitle("Mensaje");
        mensaje.setText("No se pudo cancelar la reservacion.");
        mensaje.exec();
    }
}


void MainWindow::on_modificar_clicked()
{
    QString reservacionModificar=ui->reservacionLine->text();
    QString nombre=ui->nombreLine_2->text();
    QString numeroDeContacto=ui->contactoLine_2->text();
    int numeroDeComensales=ui->comensalesLine_2->text().toInt();
    QString fecha=ui->fechaLine_2->text();
    int hora=ui->horaLine_2->text().toInt();
    bool existe=false;
    for(int i=0;i<reservaciones.size();i++){
        if(reservacionModificar==QString::number(reservaciones.at(i)->getCodigo())){
            if(numeroDeComensales<=reservaciones.at(i)->getMesa()->getNumeroDeSillas()){
                reservaciones.at(i)->modificar(nombre, numeroDeContacto, numeroDeComensales, fecha, hora);
                existe=true;
            }
        }
    }

    if(existe){
        mensaje.setWindowTitle("Mensaje");
        mensaje.setText("Se modifico su reservacion con exito.");
        mensaje.exec();
    }else{
        mensaje.setWindowTitle("Mensaje");
        mensaje.setText("No se pudo modificar la reservacion.");
        mensaje.exec();
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    ui->tabWidget->setCurrentIndex(2);
}


void MainWindow::on_pushButton_5_clicked()
{
    ui->tabWidget->setCurrentIndex(3);
}


void MainWindow::on_reservacionesList_clicked()
{
    QString info="";
    for(int i=0;i<reservaciones.size();i++){
        info+=reservaciones.at(i)->getInfo();
    }
    ui->textEdit_2->setText(info);
}


void MainWindow::on_pushButton_6_clicked()
{
    QString numero=ui->numeroMesaLine->text();
    int sillas=ui->sillasLine->text().toInt();
    bool existe=false;

    for(int i=0;i<mesas.size();i++){
        if(mesas.at(i)->getNumeroDeMesa()==numero){
            existe=true;
        }
    }

    if(existe){
        mensaje.setWindowTitle("Mensaje");
        mensaje.setText("La mesa que trato de crear ya existe.");
        mensaje.exec();
    }else{
        mesa* nuevaMesa1=new mesa(numero,sillas);
        mesas.append(nuevaMesa1);
        mensaje.setWindowTitle("Mensaje");
        mensaje.setText("Se creo la mesa con exito.");
        mensaje.exec();
    }
}


void MainWindow::on_mesas_clicked()
{
    QString info="";
    for(int i=0;i<mesas.size();i++){
        if(!mesas.at(i)->ifReservada()){
            info+=mesas.at(i)->getInfo();
        }
    }
    ui->textEdit_3->setText(info);
}


void MainWindow::on_pushButton_7_clicked()
{
    QString numero=ui->numeroMesaLine->text();
    bool eliminar=false;

    for(int i=0;i<mesas.size();i++){
        if(mesas.at(i)->getNumeroDeMesa()==numero){
            if(!mesas.at(i)->ifReservada()){
                mesa* mesaEliminar=mesas.at(i);
                delete mesaEliminar;
                mesas.removeAt(i);
                eliminar=true;
                break;
            }
        }
    }

    if(eliminar){
        mensaje.setWindowTitle("Mensaje");
        mensaje.setText("La mesa se elimino con exito.");
        mensaje.exec();
    }else{
        mensaje.setWindowTitle("Mensaje");
        mensaje.setText("La mesa que trato de eliminar ya existe o esta reservada.");
        mensaje.exec();
    }
}

