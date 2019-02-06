#include <iostream>

using namespace std;

#include "reloj.h"

int main() {
  int hora, minutos;
  cout<<"Teclea la hora inicial: ";
  cin>>hora;
  cout<<"Teclea los minutos: ";
  cin>>minutos;

  reloj hrInicial(hora,minutos);

  cout<<"Teclea la hora final: ";
  cin>>hora;
  cout<<"Teclea los minutos: ";
  cin>>minutos;

  reloj hrFinal (hora,minutos);

  hrInicial.display();
  hrFinal.display();
}