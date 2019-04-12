#include <iostream>
using namespace std;

#include "Reloj.h"
#include "Reserva.h"
#include "Servicio.h"
#include "Maquina.h"
#include "Cancha.h"

int main()
{
    Reloj r1(12,30);
    Reserva r2("Hola",12,r1,34);
    Servicio *r3[2];
    Cancha r4(12,12,"Futboal","HOLA",12,'d');
    Maquina r5(21,true,"hola","pepe",12,'c');
    r3[0]=&r4;
    r3[1]=&r5;
    r3[1]->muestra();
    cout<<"\n--------------------\n";
    r3[0]->muestra();
    cout<<endl<<r2.calculaHoraFinReservacion();





    return 0;
}
