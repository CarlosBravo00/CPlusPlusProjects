#include <iostream>

using namespace std;
#include "Persona.h"
#include "Taxi.h"

int main()
{
    int x;
    cout<<"Cuantos taxis desea registrar: ";
    cin>>x;
    Taxi Taxis[240];
    for(int i=0;i<x;i++){
        cout<<"Taxi "<<i+1<<endl;
        string cel;
        string nom;
        int idtaxi;
        cout<<"Id Taxi: ";
        cin>>idtaxi;
        cout<<"Nombre de responsable: ";
        cin>>nom;
        cout<<"Numero celular del resposanble: ";
        cin>>cel;
        Taxi tax;
        Persona res;
        tax.setIdnet(idtaxi);
        res.setNombre(nom);
        res.setNumCel(cel);
        tax.setResponsable(res);
        Taxis[i]=tax;
    }
    char op;
    do{
    cout<<"Menu\n";
    cout<<"(A) Consultar la lista de Taxis disponibles\n(B) Consultar la lista de Taxis por nombre de responsable\n(C) Que permita agregar Taxis a la lista\n(D) Terminar\n";
    cout<<"---------------------------------------> ";
    cin>>op;

    if(op=='A'){
    cout<<"------------------------------------\n";
    for(int i=0;i<x;i++){
        cout<<"Taxi: "<<Taxis[i].getIdent();
        Persona temp=Taxis[i].getResponsable();
        cout<<"\nPersona responsable: "<<temp.getNombre()<<"\nNumero celular: "<<temp.getNumCel();
        cout<<"\n------------------------------------\n";
    }
    }

    else if(op=='B'){
    string noom;
    cout<<"Nombre del responsable: ";
    cin>>noom;
    for (int i=0;i<x;i++){
    Persona temporal=Taxis[i].getResponsable();
    string noomc=temporal.getNombre();
    if(noomc==noom){
        cout<<"Taxi: "<<Taxis[i].getIdent();
        Persona temp=Taxis[i].getResponsable();
        cout<<"\nNumero celular: "<<temp.getNumCel();
        cout<<"\n------------------------------------\n";
    }
    }
    }
    else if(op=='C'){
    x++;
    int id;
    string nombre;
    string cell;
    Persona temporal;
     cout<<"Id Taxi: ";
    cin>>id;
    cout<<"Nombre de responsable: ";
    cin>>nombre;
    cout<<"Numero celular del resposanble: ";
    cin>>cell;
    Taxis[x-1].setIdnet(id);
    temporal.setNombre(nombre);
    temporal.setNumCel(cell);
    Taxis[x-1].setResponsable(temporal);


    }

    }while (op!='D');
}
