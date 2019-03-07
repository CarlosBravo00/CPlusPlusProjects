#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#include "Empleado.h"


int main()
{
    //Carga de archivo
    Empleado Em[20];
    ifstream entrada("Empleados.txt");

    int id;
    double sFijo;
    double sHora;
    int horas;

    int Empleados;

    for(int i=0;i<20&&!entrada.eof();i++){
        entrada >> id;
        Em[i].setIdEmpleado(id);
        entrada >> sFijo;
        Em[i].setSueldoFijo(sFijo);
        entrada >> sHora;
        Em[i].setSueldoHora(sHora);
        entrada >> horas;
        Em[i].setHorasTrabajo(horas);
        Empleados=i;
    }

    //Menu

    bool terminar=true;
    char op;


    do{
    cout<<"---------------Menu---------------"<<endl;
    cout<<" A) Modificar sueldo fijo \n B) Modificar sueldo por horas \n C) Registrar horas trabajadas \n D) Calcular pago del empleado \n E) Ver lista empleado \n F) Terminar \n --------------------------> ";
    cin>>op;
    cout<<"---------------------------------\n";

    if (op=='A'){
        cout<<"Id de empleado: ";
        cin>>id;
        bool validar=false;
        int numerocuenta;
        for(int i=0;i<20;i++){
            if(Em[i].getIdEmpleado()==id){
                validar=true;
                numerocuenta=i;
            }
        }
        if(!validar){
        cout<<"Id no existe \n";
        } else {
        cout<<"Nuevo sueldo fijo: ";
        cin>>sFijo;
        if(sFijo>0){
            Em[numerocuenta].setSueldoFijo(sFijo);
            cout<<"Operacion exitosa \n";

        }else cout<<"Sueldo negativo \n";
        }
    }

    else if(op=='B'){
    cout<<"Id de empleado: ";
        cin>>id;
        bool validar=false;
        int numerocuenta;
        for(int i=0;i<20;i++){
            if(Em[i].getIdEmpleado()==id){
                validar=true;
                numerocuenta=i;
            }
        }
        if(!validar){
        cout<<"Id no existe \n";
        } else {
        cout<<"Nuevo sueldo por horas: ";
        cin>>sHora;
        if(sHora>0){
            Em[numerocuenta].setSueldoHora(sHora);
            cout<<"Operacion exitosa \n";

        }else cout<<"Sueldo negativo \n";


    }
    }

    else if(op=='C'){
    cout<<"Id de empleado: ";
        cin>>id;
        bool validar=false;
        int numerocuenta;
        for(int i=0;i<20;i++){
            if(Em[i].getIdEmpleado()==id){
                validar=true;
                numerocuenta=i;
            }
        }
        if(!validar){
        cout<<"Id no existe \n";
        } else {
        cout<<"Horas trabajadas: ";
        cin>>horas;
        if(horas>0){
        Em[numerocuenta].RegistrarHoras(horas);
        cout<<"Operacion exitosa \n";

        }else cout<<"Horas negativas \n";


    }
    }

    else if(op=='D'){
    cout<<"Id de empleado: ";
        cin>>id;
        bool validar=false;
        int numerocuenta;
        for(int i=0;i<20;i++){
            if(Em[i].getIdEmpleado()==id){
                validar=true;
                numerocuenta=i;
            }
        }
        if(!validar){
        cout<<"Id no existe \n";
        } else {
        cout<<"Pago: "<<Em[numerocuenta].CalcularPago()<<endl;
        }
    }

    else if(op=='E'){
    for(int i=0;i<Empleados+1;i++){
        cout<<"Id: "<<Em[i].getIdEmpleado();
        cout<<" Sueldo fijo: "<<Em[i].getSueldoFijo();
        cout<<" Sueldo por horas: "<<Em[i].getSueldoHora();
        cout<<" Horas Trbajadas: "<<Em[i].getHorasTrabajo();
        cout<<" Pago: "<<Em[i].CalcularPago()<<endl;
    }
    }

    else if(op=='F'){
        terminar=false;
    }

    }while (terminar);
    cout<<"Bye";


    return 0;
}
