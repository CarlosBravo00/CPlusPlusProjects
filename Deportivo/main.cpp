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

            Canchas[ContServicios].setClave(cveServicio);cout<<"\n----------------------------------------------\n";
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

    //Establecer reservas como salida y cargar todos las Reservas del arreglo
    Reloj temporal;
    ofstream oReservas ("Reserva.txt");
    for(int q=0;q<ContReservaciones;q++){
    oReservas<<Reservaciones[q].getClaveServicio();
    oReservas<<" ";

    temporal=Reservaciones[q].getHoraInicio();
      if (temporal.getHora()<10){
        oReservas << "0";
  }
    oReservas<<temporal.getHora();

        oReservas<<" ";

    if (temporal.getMin()<10){
        oReservas << "0";
  }
    oReservas<<temporal.getMin();

    oReservas<<" ";
    oReservas<<Reservaciones[q].getDuracion();
    oReservas<<" ";
    oReservas<<Reservaciones[q].getIdCliente();
    oReservas<<endl;
    }

    //Menu
    char op;
    bool terminar=true;
    do{

    cin>>op;
        if(op=='A'||op=='a'){///Muestra servicios
        for(int i=0;i<ContServicios;i++){
            Servicios[i]->muestra();
            cout<<"\n----------------------------------------------\n";
        }
        }
        else if(op=='B'||op=='b'){///Muestra reservaciones
        for(int i=0;i<ContReservaciones;i++){
            cout<<"Clave servicio: "<<Reservaciones[i].getClaveServicio()<<endl;
            cout<<"ID Cliente: "<<Reservaciones[i].getIdCliente()<<endl;
            cout<<"Hora inicio: "<<Reservaciones[i].getHoraInicio()<<endl;
            cout<<"Hora final: "<<Reservaciones[i].calculaHoraFinReservacion();
            cout<<"\n----------------------------------------------\n";
        }

        }
       else if(op=='C'||op=='c'){ ///Busca reservaciones por clave
            cout<<"Clave de Servicio: ";
            string idString;
            cin>>idString;
            for(int i=0;i<ContServicios;i++){
                if(idString==Servicios[i]->getClave()){
                    Servicios[i]->muestra();
                    cout<<"\n----------------------------------------------\n";
                }
            }
            bool check=true;
            cout<<"Reservas: "<<endl;
            for(int i=0;i<ContReservaciones;i++){
                if(idString==Reservaciones[i].getClaveServicio()){
                   cout<<"ID Cliente: "<<Reservaciones[i].getIdCliente()<<endl;
                cout<<"Hora inicio: "<<Reservaciones[i].getHoraInicio()<<endl;
                cout<<"Hora final: "<<Reservaciones[i].calculaHoraFinReservacion();
                cout<<"\n----------------------------------------------\n";
                check=false;
                }
            }
            if(check){
                cout<<"No tiene reservaciones";
                cout<<"\n----------------------------------------------\n";

            }



        }

       else if(op=='D'||op=='d'){ ///Busca reservaciones por hora
            Reloj Relojtem;
            cout<<"Hora(hh/mm): ";
            cin>>Relojtem;
            cout<<"----------------------------------------------\n";
            for(int i=0;i<ContReservaciones;i++){
                if(Relojtem>=Reservaciones[i].getHoraInicio()){
                if(Relojtem<=Reservaciones[i].calculaHoraFinReservacion()){
                cout<<"Reservado de: "<<Reservaciones[i].getHoraInicio()<<" a "<<Reservaciones[i].calculaHoraFinReservacion()<<endl;
                for(int j=0;j<ContServicios;j++){
                    if(Reservaciones[i].getClaveServicio()==Servicios[j]->getClave()){
                        Servicios[j]->muestra();
                        cout<<"\n----------------------------------------------\n";
                    }

                }

                }
            }


        }
       }

       else if(op=='E'||op=='e'){


        }
       else if(op=='F'||op=='f'){
            terminar=false;
        }






    }while(terminar);








    return 0;
}
