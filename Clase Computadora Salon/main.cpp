#include <iostream>

using namespace std;
#include "Computadora.h"
#include "Salon.h"

int main()
{
    int salont=0;
    string marcat="";
    string OSt="";
    int ramt=0;

    cout<<"Numero de salones: ";
    int x;
    cin>>x;
    salon salones[x];
    for(int i=0;i<x;i++){
        cout<<"-------------------\n";
        cout<<"Numero de salon: ";
        cin>>salont;
        cout<<"Marca de la computadora: ";
        cin>>marcat;
        cout<<"Sistema operativo: ";
        cin>>OSt;
        cout<<"RAM de la computadora: ";
        cin>>ramt;
        computadora tempo(marcat,OSt,ramt);
        salones[i].setNumsalon(salont);
        salones[i].setComputadora(tempo);
    }
    char op;
    do{
    cout<<"\n--------------------------------\n";
    cout<<"Menu\n(A) Buscar por marca\n(B) Buscar por Sistema Operativo\n(C) Mostrar todos los salones\n(D) Terminar\n---------------> ";
    cin>>op;
    if(op=='A'){
    cout<<"Nombre de marca: ";
    cin>>marcat;
    for(int i=0;i<x;i++){
        computadora tempo=salones[i].getComputadora();
        if(marcat==tempo.getMarca()){
            cout<<"Salon: "<<salones[i].getNumSalon();
        }
    }
    }
    else if(op=='B'){
    cout<<"Nombre de OS: ";
    cin>>OSt;
    for(int i=0;i<x;i++){
        computadora tempo=salones[i].getComputadora();
        if(OSt==tempo.getOS()){
            cout<<"Salon: "<<salones[i].getNumSalon();
        }
    }


    }
    else if(op=='C'){
    for(int i=0;i<x;i++){

       cout<<"Salon: "<<salones[i].getNumSalon();
        computadora tempo=salones[i].getComputadora();
        cout<<"\nMarca: "<<tempo.getMarca();
        cout<<"\nSistema operativo: "<<tempo.getOS();
        cout<<"\nRAM: "<<tempo.getRam();
        if(i+1!=x){
         cout<<"\n------------------------------";
        }
    }
    }
    } while (op!='D');
    return 0;
}
