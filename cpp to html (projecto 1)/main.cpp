#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void inicio (ofstream& salida){
  salida<<"<!DOCTYPE html>\n<html>\n<head>\n<title>\nDocumentación del archivo entrada.cpp\n</title>\n</head>\n<body>\n";
}

void finaly (ofstream& salida){
  salida<<"\n</body>\n</html>";
}

void funcionprincipal(string &frase,ofstream& salida,ifstream& entrada){

     if(frase=="@progName"){
       salida<<"<h2>\nPrograma: ";
       entrada>>frase;
       while(frase[0]!='@'&&frase!="*/" ){
         salida<<frase<<" ";
         entrada>>frase;
       }
       salida<<"<br>\n</h2>";
     }

      else if(frase=="@author"){
        salida<<"\n<strong> Autor: </strong> ";
       entrada>>frase;
       while(frase[0]!='@'&&frase!="*/"){
         salida<<frase<<" ";
         entrada>>frase;
       }
       salida<<"<br>";
      }

      else if (frase=="@date"){
        salida<<"\n<strong> Fecha de elaboración </strong> ";
       entrada>>frase;
       while(frase[0]!='@'&&frase!="*/"){
         salida<<frase<<" ";
         entrada>>frase;
       }
       salida<<"<br>";
      }

      else if (frase=="@funcName"){
         salida<<"\n<h3>\n <hr><br>Función: ";
       entrada>>frase;
       while(frase[0]!='@'&&frase!="*/"){
         salida<<frase<<" ";
         entrada>>frase;
       }
       salida<<"<br>\n</h3>";

      }

      else if (frase=="@desc"){
         salida<<"\n<strong> Descripción: </strong> ";
       entrada>>frase;
       while(frase[0]!='@'&&frase!="*/"){
         salida<<frase<<" ";
         entrada>>frase;
       }
       salida<<"<br>";
      }

      else if (frase=="@param"){
        salida<<"\n<strong> Parámetro: </strong> ";
       entrada>>frase;
       while(frase[0]!='@'&&frase!="*/"){
         salida<<frase<<" ";
         entrada>>frase;
       }
       salida<<"<br>";
      }

      else if (frase=="@return"){
        salida<<"\n<strong> Valor de retorno: </strong> ";
       entrada>>frase;
       while(frase[0]!='@'&&frase!="*/"){
         salida<<frase<<" ";
         entrada>>frase;
       }
       salida<<"<br>";
      }

}

int main() {

  string frase;
  string filename;
  string filenametemp;
  cout << "Enter the name of the file: ";
  cin >> filename;
  filenametemp=filename;
  filename+=".cpp";
  ifstream entrada( filename.c_str() );
  filenametemp+=".html";
  ofstream salida(filenametemp.c_str());

  inicio(salida);

  if (entrada.is_open())
    {
    while (!entrada.eof())
    {
       entrada>>frase;
       if (frase=="/**"){
         while (frase!="*/"&&!entrada.eof()){
          while(frase[0]=='@'){
            funcionprincipal(frase,salida,entrada);
          }
          entrada>>frase;
         }
       }
    }

entrada.close();
    cout<<"Archivo html creado";

}else cout<<"No hay cpp de entrada";

    finaly(salida);
    salida.close();
    return 0;
  }
