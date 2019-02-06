#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void funcion(string &frase){
  int x=frase.size();
  int cont=0;
   for(int i=x;i!=0;i--){
      if(cont==3){
        cont=1;
        frase.insert(i,",");
      }else cont++;
      }

}

int main() {

  string frase;
  ifstream entrada("numeros(act4).txt");
  ofstream salida("salida(act4).txt");


  if (entrada.is_open())
    {
    while (!entrada.eof())
    {
        entrada >> frase;
        funcion(frase);
        salida  << frase << endl;
        }

    entrada.close();
    cout<<"Archivo de salida creado";
    }else cout<<"No hay archvio de entrada";

    salida.close();
    return 0;
}
