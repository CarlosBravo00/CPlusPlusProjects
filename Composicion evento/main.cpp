#include <iostream>
#include <string>
using namespace std;
#include "reloj.h"
#include "Evento.h"

int main()
{
    char op='s';
    int hrs,min,du,cont=0;
    reloj hora;
    string asunto;
    Evento arrEvento[20];
    Evento evento;
    cout<<"Quieres agregar un evento (s/n): ";
    cin>>op;
    while (op=='s' && cont<20){
    cout<< "Hora inical del evento (hh,mm) : ";
    cin>>hrs>>min;
    hora.setHora(hrs);
    hora.setMin(min);
    cout<<"Cuanto durara el evento: ";
    cin>>du;
    cout<<"Asunto del evento: ";
    cin.ignore();
    getline(cin,asunto);
    evento.setHoraInicial(hora);
    evento.setDuracion(du);
    evento.setAsunto(asunto);
    arrEvento[cont]=evento;
    cont++;
    cout<<"-----------------------------------------\n";
    cout<<"Quieres agregar otro evento (s/n): ";
    cin>>op;
    }


     cout<<"------------------------------------------\nEVENTOS\n------------------------------------------"<<endl;
for(int i=0;i<cont;i++){
 cout << "Evento: "<<arrEvento[i].getAsunto();
 cout<< "\nHora inicial ";
 reloj temp=arrEvento[i].getHoraInicial();
 temp.display();
 cout<<"Duracion: "<<arrEvento[i].getDuracion()<<" Minutos";
  cout<<"\n-----------------------------------------\n";
}
    return 0;
}
