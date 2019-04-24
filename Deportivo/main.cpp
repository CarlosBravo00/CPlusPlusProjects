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

       cout<<"--------------------MENU----------------------\n";
        cout<<"( A ) Consulta lista de servicios\n";
        cout<<"( B ) Consulta lista de reservaciones\n";
        cout<<"( C ) Consulta las reservaciones de una servicio dado\n";
        cout<<"( D ) Consulta las reservaciones de una hora especifica\n";
        cout<<"( E ) Hacer una reservación\n";
        cout<<"( F ) Terminar";
        cout<<"\n---------------------------------------------> ";

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
        bool condi=true;

       //id cliente
        cout<<"ID Cliente: ";
        cin>>idCliente;

        //clave
        bool condiClave=true;
        do{
        cout<<"Clave de servicio: ";
        cin>>claveServicio;
        for(int i=0;i<ContServicios&&condiClave;i++){
            if(claveServicio==Servicios[i]->getClave()){
                condiClave=false;
            }
        }
        }
        while (condiClave);

        //Hora
        cout<<"Hora a la que se desea reservar(hh/mm): ";
        cin>>HoraInicio;

        //Minutos reservar
        bool condiDuracion=true;
        do{
        cout<<"Minutos que se desea reservar: ";
        cin>>duracion;
        for(int i=0;i<ContServicios;i++){
        if(claveServicio==Servicios[i]->getClave()){
            if(duracion>Servicios[i]->getTiempoMax()){
                cout<<"----------------------------------------------\n";
                cout<<"EL tiempo maximo de este servicio es: "<<Servicios[i]->getTiempoMax();
                cout<<"\nCancelar reservacion[C] o Modificar duracion[M]----> ";
                char opp;
                cin>>opp;
                if(opp=='C'||opp=='c'){
                 condi=false;
                 condiDuracion=false;
                cout<<"----------------------------------------------\n";
                }
            }else condiDuracion=false;
        }
        }

        }while(condiDuracion);

        //Checar que se pueda la hora
        Reloj HoraFinal=HoraInicio+duracion;
        if(condi){
        for(int i=0;i<ContReservaciones;i++){
            if(claveServicio==Reservaciones[i].getClaveServicio()){
                if(HoraInicio<=Reservaciones[i].getHoraInicio()){
                    if(HoraFinal>=Reservaciones[i].getHoraInicio()){
                        condi=false;
                        cout<<"----------------------------------------------\n";
                        cout<<"No es posible crear una reservacion a esta hora";
                        cout<<"\nTu reservacion: "<<HoraInicio<<" a "<<HoraFinal;
                        cout<<"\nReservacion existente: "<<Reservaciones[i].getHoraInicio()<<" a "<<Reservaciones[i].calculaHoraFinReservacion();
                        cout<<endl;
                        }
                }
                if(condi){
                 if(HoraInicio>=Reservaciones[i].getHoraInicio()){
                    if(HoraFinal<=Reservaciones[i].calculaHoraFinReservacion()){
                        condi=false;
                           cout<<"----------------------------------------------\n";
                        cout<<"No es posible crear una reservacion a esta hora";
                        cout<<"\nTu reservacion: "<<HoraInicio<<" a "<<HoraFinal;
                        cout<<"\nReservacion existente: "<<Reservaciones[i].getHoraInicio()<<" a "<<Reservaciones[i].calculaHoraFinReservacion();
                        cout<<endl;
                    }
                }
                }
                if(condi){
                 if(HoraInicio<=Reservaciones[i].calculaHoraFinReservacion()){
                    if(HoraFinal>=Reservaciones[i].calculaHoraFinReservacion()){
                        condi=false;
                        cout<<"----------------------------------------------\n";
                        cout<<"No es posible crear una reservacion a esta hora";
                        cout<<"\nTu reservacion: "<<HoraInicio<<" a "<<HoraFinal;
                        cout<<"\nReservacion existente: "<<Reservaciones[i].getHoraInicio()<<" a "<<Reservaciones[i].calculaHoraFinReservacion();
                        cout<<endl;
                    }
                }
                }

        }
        }
        }
        //Agregar reservacion si condi
        if(condi){
            for(int i=0;i<ContServicios;i++){
                if(claveServicio==Servicios[i]->getClave()){
                cout<<"----------------------------------------------\n";
                cout<<"Reservacion exitosa\nCosto: "<<Servicios[i]->calculaCosto(duracion)<<"$";
                cout<<"\n----------------------------------------------\n";

            }
            }
            Reservaciones[ContReservaciones].setIdCliente(idCliente);
            Reservaciones[ContReservaciones].setClaveServicio(claveServicio);
            Reservaciones[ContReservaciones].setHoraInicio(HoraInicio);
            Reservaciones[ContReservaciones].setDuracion(duracion);
            oReservas<<Reservaciones[ContReservaciones].getClaveServicio();
            oReservas<<" ";

            temporal=Reservaciones[ContReservaciones].getHoraInicio();
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
            oReservas<<Reservaciones[ContReservaciones].getDuracion();
            oReservas<<" ";
            oReservas<<Reservaciones[ContReservaciones].getIdCliente();
            oReservas<<endl;
            ContReservaciones++;
            }
        }

       else if(op=='F'||op=='f'){
            terminar=false;
        }






    }while(terminar);








    return 0;
}
