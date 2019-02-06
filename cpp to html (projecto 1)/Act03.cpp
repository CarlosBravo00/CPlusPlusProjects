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
/**
@funcName Ej 2
@desc el programa construye un string formado con la primera letra de cada una de las palabras de la frase dada por el usuario
*/
void ej2(){
    cout<<"Ejercicio 2"<<endl;
    string frase;
    cout<<"Teclear una frase: "<<endl;
    getline(cin,frase);
    string frasefinal="";

    for(int i=0; i<frase.size(); i++){
        if(i==0&&frase[0]!=' '){
            frasefinal += frase[i];
        }
        if(frase[i]==' '&& frase [i+1] !=' '){
            frasefinal += frase[i+1];
        }
    }
    cout<<"La frase resultante es: "<<frasefinal<<endl;


}
/**
@funcName Ej 3
@desc programa que pide al usuario una frase y construye un string que contiene la frase con las palabras al revés.
*/
void ej3(){
    cout<<"Ejercicio 3"<<endl;
    cout<<"Teclear una frase: "<<endl;
    string frase;
    string frasef="";
    getline(cin,frase);
    int x=frase.size();
    int espacios[x];
    int j=0;
    for(int i=0;i<x;i++){
        if(frase[i]==' '){
                espacios[j]=i;
                j++;


        }

    }
    for(int i=j;i>=0;i--){
        int z;
        z=espacios[i]-espacios[i-1];
        int tempo=espacios[i-1];
        if(i==0){
            z=espacios[i];
            tempo=0;
            frasef+=" ";
        }
        string temporal="";
        temporal=frase.substr(tempo,z);
        frasef=frasef+temporal;

    }
    if(frasef[0]==' '){
        frasef.erase(0,1);
    }
    cout<<frasef<<endl;


}
/**
@funcName Ej 4
@desc programa que pide una frase y una palabra y construye un string que contiene la frase original pero sustituyendo la palabra especificada por el caracter *
*/
void ej4(){
    cout<<"Ejercicio 4"<<endl;
    cout<<"Teclear una frase: "<<endl;
string frase;
string palabra;
getline(cin,frase);
cout<<"Teclear una palabra: "<<endl;
getline(cin,palabra);
int x=frase.size();
int fe=palabra.size();

for(int i=0;i<x;i++){
    int y=frase.find(palabra);
    if(y!=-1){
        frase.insert(y,"*");
    }else break;
    frase.erase(y+1,fe);

}
cout<<frase<<endl;

}
/**
@funcName Ej 5
@desc programa que pide un número flotante positivo. El programa verifica que se trata de un número de punto flotante.
*/
void ej5(){
    cout<<"Ejercicio 5"<<endl;
    cout<<"Teclear un numero flotante positivo: "<<endl;
string frase;
getline(cin,frase);
int x=frase.size();
bool yo=true;
bool condicional=true;
for(int i=0;i<x;i++){
    if(frase[i]!='0'&&frase[i]!='1'&&frase[i]!='2'&&frase[i]!='3'&&frase[i]!='4'&&frase[i]!='5'&&frase[i]!='6'&&frase[i]!='7'&&frase[i]!='8'&&frase[i]!='9'){
        if(condicional&&frase[i]=='.'){
                condicional=false;
        }else{
    yo=false;
    }
    }
}
if(yo){
    cout<<"Numero Valido"<<endl;
}else cout<<"Numero Invalido"<<endl;

}
/**
@funcName Ej 6
@desc programa que pide una frase y  elimina los espacios en blanco que sobren, de manera que no quedan espacios en blanco ni al inicio ni al final
*/
void ej6(){
    cout<<"Ejercicio 6"<<endl;
    cout<<"Teclear una frase: "<<endl;
string frase;
getline(cin,frase);
int x=frase.size()+1;
bool condicional=true;

for(int i=0;i<x;i++){
        if(frase[i]==' '){
        if(frase[i+1]==' '){
            frase.erase(i,1);
            i--;

            condicional=false;

        }
}
    }
    if(frase[0]==' '){
        frase.erase(0,1);
    }
    int y=frase.size();
    if(frase[y-1]==' '){
        frase.erase(y-1,1);
    }
         cout<<frase<<"."<<endl;



}
/**
@funcName main
@desc Le pregunta al usuario que ejercicio desea acceder corre la funcion del ejercicio y vuelve a preguntar si quiere otro
*/
int main()
{

int ej;

char otro;

do{

cout<<"Numero de ejercicio"<<endl;
cin>>ej;
cout<<"----------------------------------------"<<endl;


cin.ignore();
if(ej==1){
    ej1();
}
else if(ej==2){
    ej2();
}
else if(ej==3){
    ej3();
}
else if(ej==4){
    ej4();
}
else if(ej==5){
    ej5();
}
else if(ej==6){
    ej6();
}
cout<<"----------------------------------------"<<endl;
cout<<"Otro ejercicio?(S/N)";
cin>>otro;
cout<<endl;

}while(otro=='S'||otro=='s');

    return 0;
}
