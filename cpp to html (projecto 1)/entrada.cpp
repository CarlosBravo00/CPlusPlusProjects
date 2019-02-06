/**
@progName Act3
@desc Programa que contiene varios ejercisios de Strings
@author Carlos Bravo
@date 24/1/2019
*/
#include <iostream>
#include <string>

using namespace std;

/**
@funcName Ej 1
@desc programa que pide una frase y que muestre un mensaje que indica si se trata de un palíndromo o no
*/
void ej1(){
    cout<<"Ejercicio 1"<<endl;
    string palabra;
    cout<<"Teclear una frase: "<<endl<<endl;
    getline(cin,palabra);
    string fraseoriginal=palabra;

   //borrar espacio
    int espacio=0;
    while (espacio>=0){
        espacio=palabra.find(" ");
        if(espacio>=0){
            palabra.erase(espacio,1);
        }
    }


    //validacion
    bool palindromo= true;
    int longitudfrase = palabra.size();
    int j=longitudfrase-1;
    for(int i=0;i<longitudfrase/2 && palindromo; i++){
        if(tolower (palabra[i])!= tolower (palabra[j])){
            palindromo=false;
        }
        else{
            j--;
        }
    }
    if(palindromo){
            cout<<endl<<"la frase "<<fraseoriginal<<" si es un palindromo"<<endl;
    }else{
        cout<<endl<<"la frase "<<fraseoriginal<<" no es un palindromo"<<endl;

    }
}