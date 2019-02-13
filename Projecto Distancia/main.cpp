#include <iostream>

using namespace std;

#include "Distancia.h"

int main()
{
    Distancia a;
    Distancia b(5,11);
    Distancia c(0,4);

    Distancia d= b.sumaDistancia(c);

    cout<<"Pies: "<<d.getPies()<<" Pulgadas: "<<d.getPulgadas();
    return 0;
}
