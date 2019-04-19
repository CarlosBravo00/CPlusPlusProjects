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

    //Declaraciones
    Servicio *Servicios[20];
    Cancha Canchas[20];
    Maquina Maquinas[20];
    Reserva Reservaciones[50];
    ifstream aServicios ("Servicios.txt");
    ifstream aReservas ("Reserva.txt");

    int ContServicios=0;
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

    //Cargar servicios
    while(!aServicios.eof()){
        aServicios>>cveServicio;
         aServicios>>tiempoMax;
         aServicios>>tipoServ;
         ///Cargar maquinas
         if(tipoServ=='C'||tipoServ=='E'||tipoServ=='B'){

            aServicios>>costoX15min;
            aServicios>>ClaveInstructor;
            if(ClaveInstructor=='T'){
                conInstructor=true;
            } else conInstructor=false;
            getline(aServicios,descripcion);

            Maquinas[ContServicios].setClave(cveServicio);
            Maquinas[ContServicios].setTiempoMax(tiempoMax);
            Maquinas[ContServicios].setTipo(tipoServ);
            Maquinas[ContServicios].setCostoX15min(costoX15min);
            Maquinas[ContServicios].setConInstructor(conInstructor);
            Maquinas[ContServicios].setDescripcion(descripcion);
            Servicios[ContServicios]=&Maquinas[ContServicios];
            ContServicios++;
         }
         ///Cargar canchas
         else if(tipoServ=='T'||tipoServ=='F'||tipoServ=='V'){
            aServicios>>costoXhr;
            aServicios>>cantidadMaxPersonas;
            getline(aServicios,deporte);

            Canchas[ContServicios].setClave(cveServicio);
            Canchas[ContServicios].setTiempoMax(tiempoMax);
            Canchas[ContServicios].setTipo(tipoServ);
            Canchas[ContServicios].setCostoXHr(costoXhr);
            Canchas[ContServicios].setCantMaxPers(cantidadMaxPersonas);
            Canchas[ContServicios].setDeporte(deporte);
            Servicios[ContServicios]=&Canchas[ContServicios];
            ContServicios++;



         }

         }

        aServicios.close();



//Cargar Reservaciones
    int ContReservaciones=0;
     string claveServicio;
    int idCliente;
    Reloj HoraInicio;
    int duracion;

    while (!aReservas.eof())
    {
     aReservas>>claveServicio;
     aReservas>>HoraInicio;
     aReservas>>duracion;
     aReservas>>idCliente;
     Reservaciones[ContReservaciones].setClaveServicio(claveServicio);
     Reservaciones[ContReservaciones].setHoraInicio(HoraInicio);
     Reservaciones[ContReservaciones].setDuracion(duracion);
     Reservaciones[ContReservaciones].setIdCliente(idCliente);
     ContReservaciones++;
    }
    ContReservaciones--;
    aReservas.close();

    //Establecer reservas como salida y cargar todos las Reservas
    ofstream oReservas ("Reserva.txt");
    for(int q=0;q<ContReservaciones;q++){
    oReservas<<Reservaciones[q].getClaveServicio();
    oReservas<<" ";
    oReservas<<Reservaciones[q].getHoraInicio();
    oReservas<<" ";
    oReservas<<Reservaciones[q].getDuracion();
    oReservas<<" ";
    oReservas<<Reservaciones[q].getIdCliente();
    oReservas<<endl;
    }

    //Menu







    return 0;
}
