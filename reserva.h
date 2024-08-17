#ifndef RESERVA_H
#define RESERVA_H
#include "QMessageBox"
#include "mesa.h"

class reserva
{
protected:
    // nombre, número de contacto, número de comensales, fecha y hora de la reserva.
    int codigo;
    QString nombre;
    QString numeroDeContacto;
    int numeroDeComensales;
    QString fecha;
    int hora;
    mesa* Mesa;

public:
    reserva(int codigo, QString& nombre, QString& numeroDeContacto, int numeroDeComensales, QString& fecha, int hora, mesa* Mesa)
        :codigo(codigo), nombre(nombre), numeroDeContacto(numeroDeContacto), numeroDeComensales(numeroDeComensales),
        fecha(fecha), hora(hora), Mesa(Mesa){}

    int getCodigo(){
        return codigo;
    }

    mesa* getMesa(){
        return Mesa;
    }

    bool modificar(QString& nuevoNombre, QString& numeroContacto, int numeroComensales, QString& nuevaFecha, int nuevaHora){
        if(Mesa->getNumeroDeSillas()>=numeroComensales){
            nombre=nuevoNombre;
            numeroDeContacto=numeroContacto;
            numeroDeComensales=numeroComensales;
            fecha=nuevaFecha;
            hora=nuevaHora;
            return true;
        }else{
            return false;
        }
    }

    QString getInfo(){
        QString info="Codigo de la reserva: "+QString::number(codigo)+"\n";
        info+="Nombre del reservante: "+nombre+" Numero de contacto: "+numeroDeContacto+" Numero de comensales: "+QString::number(numeroDeComensales)+"\n";
        info+="Fecha: "+fecha+" Hora: "+QString::number(hora)+" Numero de mesa: "+Mesa->getNumeroDeMesa()+"\n";
        return info;
    }
};

#endif // RESERVA_H
