/**
@progName Conversor de Segundos y Minutos
@desc Programa que convierte segundos o minutos a otra medida
@author Carlos Bravo
@date 6 de Febrero de 2019

*/
#include <iostream>

using namespace std;\

/**
@funcName Segundos a horas
@desc Calcula cuantas horas hay en unos dados segundos
@param Num la cantidad de segundos
@return el número de horas en Num
*/

double segundos_a_horas (double num){
double  x=0;
x=num/3600;
return x;
}
/**
@funcName Segundos a minutos
@desc Calcula cuántos minutos hay en unos dados segundos
@param Num la cantidad de segundos
@return el número de minutos en Num
*/

double segundos_a_minutos (double num){
double  x=0;
x=num/60;
return x;
}
/**
@funcName Minutos a segundos
@desc Calcula cuántos segundos hay en unos dados minutos
@param Num la cantidad de minutos
@return el número de segundos en Num
*/

double minutos_a_segundos (double num){
double  x=0;
x=num*60;
return x;
}

/**
@funcName Minutos a horas
@desc Calcula cuántas horas hay en unos dados minutos
@param Num la cantidad de minutos
@return el número de horas en Num
*/

double minutos_a_horas (double num){
double  x=0;
x=num/60;
return x;
}



/**
@funcName main
@desc Le pregunta al usuario que conversión desea hacer y posteriormente pide el número de segundos o minutos para hacer la conversión
*/
int main()
{
    char x;
    double resultado=0;
    double num=0;

    cout<<"(A) Segundos a horas\n(B) Segundos a minutos\n(C) Minutos a segundos\n(D) Minutos a horas\n------------------------>";
    cin>>x;
    switch (x){
case 'A':
    cout<<"\nDame segundos: ";
    cin>>num;
    resultado=segundos_a_horas(num);
    cout<<endl<<num<<" Tiene "<<resultado<<" Horas\n";
    break;
case 'B':
    cout<<"\nDame segundos: ";
    cin>>num;
    resultado=segundos_a_minutos(num);
    cout<<endl<<num<<" Tiene "<<resultado<<" Minutos\n";
    break;
case 'C':
    cout<<"\nDame minutos: ";
    cin>>num;
    resultado=minutos_a_segundos(num);
    cout<<endl<<num<<" Tiene "<<resultado<<" Segundos\n";
    break;
case 'D':
    cout<<"\nDame minutos: ";
    cin>>num;
    resultado=minutos_a_horas(num);
    cout<<endl<<num<<" Tiene "<<resultado<<" Horas\n";
    break;

default:
    cout<<"no";


    }

    return 0;
}
