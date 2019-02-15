#include <iostream>
#include <string>
using namespace std;

#include "CuentaBanc.h"

int main() {
  string nombre;
  double saldo;
  char opcion;
  cout<< "Nombre de la cuenta: ";
  getline(cin,nombre);
  cout<< "Saldo incial: ";
  cin>>saldo;

  CuentaBanc cta1(nombre, saldo);

do{
cout<<"Que transaccion desea hacer \n (A) Depositar \n (B) Retirar \n (C) Consulta Saldo \n (D) Terminar"<<endl;
cout<<"----------------->  ";
cin>>opcion;
cin.ignore();

if(opcion=='A'||opcion=='a'){

cout<<endl<<"Cuanto desea depositar: ";
double  x=0;
cin>>x;
    cta1.deposita(x);
     cout<<"---------------------------------------"<<endl;
    cout << "Deposito existoso"<<endl;
    cout<<"---------------------------------------"<<endl<<endl;

}

else if(opcion=='B'||opcion=='b'){
    cout<<endl<<"Cuanto desea retirar: ";
double x=0;
bool y;
cin>>x;
    y=cta1.retira(x);
    if(y){
     cout<<"---------------------------------------"<<endl;
    cout << "Retiro exitoso"<<endl;
    cout<<"---------------------------------------"<<endl<<endl;

    }else
        {
    cout<<"---------------------------------------"<<endl;
    cout << "No se puede hacer el retiro"<<endl;
    cout<<"---------------------------------------"<<endl<<endl;
        }

}

else if(opcion=='C'||opcion=='c'){
    cout<<endl<<"---------------------------------------"<<endl;
    cout << "el saldo de la cuenta "<<
    cta1.getNombre()<<" es: "<< cta1.getSaldo()<<endl;
    cout<<"---------------------------------------"<<endl<<endl;
}

}while (opcion!='D'&&opcion!='d');
}
