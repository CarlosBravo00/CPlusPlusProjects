#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Reloj.h" //Mismo que hora
#include "Reserva.h"
#include "Servicio.h"
#include "Maquina.h" //Mismo qeu aparato
#include "Cancha.h"

int main()
{
    /*Reloj r1(12,30);
    Reserva r2("Hola",12,r1,34);
    Servicio *r3[50];
    Cancha r4(12,12,"Futboal","HOLA",12,'d');
    Maquina r5(21,false,"hola","pepe",12,'c');
    r3[0]=&r4;
    r3[1]=&r5;
    r3[1]->muestra();
    cout<<"\n--------------------\n";
    r3[0]->muestra();
    cout<<endl<<r2.calculaHoraFinReservacion();
     cout<<"\n--------------------\n";
     r4.setCantMaxPers(200);
     r3[2]=&r4;
     r3[2]->muestra();

     r3[0]->muestra();
     */


    Servicio *Servicios[20];
    Cancha Canchas[20];
    Maquina Maquinas[20];
    Reserva Reservaciones[50];
    ifstream aServicios ("Servicios.txt");
    ifstream aReservas ("Reserva.txt");

    int i=0;
    string cveServicio;
    int tiempoMax;
    char tipoServ;
    double costoX15min;
    double costoXhr;
    bool conInstructor;
    char ClaveInstructor;
    int cantidadMaxPersonas;
    string descripcion;
    string deporte;

    while(!aServicios.eof()){
        aServicios>>cveServicio;
         aServicios>>tiempoMax;
         aServicios>>tipoServ;
         if(tipoServ=='C'||tipoServ=='E'||tipoServ=='B'){

            aServicios>>costoX15min;
            aServicios>>ClaveInstructor;
            if(ClaveInstructor=='T'){
                conInstructor=true;
            } else conInstructor=false;
            getline(aServicios,descripcion);

            Maquinas[i].setClave(cveServicio);
            Maquinas[i].setTiempoMax(tiempoMax);
            Maquinas[i].setTipo(tipoServ);
            Maquinas[i].setCostoX15min(costoX15min);
            Maquinas[i].setConInstructor(conInstructor);
            Maquinas[i].setDescripcion(descripcion);
            Servicios[i]=&Maquinas[i];
            i++;
         }
         else if(tipoServ=='T'||tipoServ=='F'||tipoServ=='V'){
            aServicios>>costoXhr;
            aServicios>>cantidadMaxPersonas;
            getline(aServicios,deporte);

            Canchas[i].setClave(cveServicio);
            Canchas[i].setTiempoMax(tiempoMax);
            Canchas[i].setTipo(tipoServ);
            Canchas[i].setCostoXHr(costoXhr);
            Canchas[i].setCantMaxPers(cantidadMaxPersonas);
            Canchas[i].setDeporte(deporte);
            Servicios[i]=&Canchas[i];
            i++;



         }

         }

        aServicios.close();


        if (aReservas.is_open())
    {
    while (!aReservas.eof())
    {
        int x;
        cout<<x;
        x++;
        cout<<endl;





    }
    }



    return 0;
}
