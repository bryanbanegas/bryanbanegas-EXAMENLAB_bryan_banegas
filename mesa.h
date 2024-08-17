#ifndef MESA_H
#define MESA_H
#include "QString"

class mesa
{
protected:
    QString numeroDeMesa;
    int numeroDeSillas;
    bool reservada;
public:
    mesa(QString& numeroDeMesa, int numeroDeSillas)
        :numeroDeMesa(numeroDeMesa), numeroDeSillas(numeroDeSillas), reservada(false){}

    QString getNumeroDeMesa(){
        return numeroDeMesa;
    }

    int getNumeroDeSillas(){
        return numeroDeSillas;
    }

    bool ifReservada(){
        return reservada;
    }

    void modificar(QString& numeroMesa, int numeroSillas){
        numeroDeMesa=numeroMesa;
        numeroDeSillas=numeroSillas;
    }

    void reservar(){
        reservada=true;
    }

    QString getInfo(){
        QString info="Numero de la Mesa: "+numeroDeMesa+" Sillas disponibles: "+QString::number(numeroDeSillas)+"\n";
        return info;
    }
};

#endif // MESA_H
