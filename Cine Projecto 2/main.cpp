#include <iostream>
#include <string>
#include <fstream>

using namespace std;
#include "Hora.h"
#include "Actor.h"
#include "Funcion.h"
#include "Pelicula.h"

int main()
{
    //EXTRA muetsra nombre de pelicula cuando pide funcion
    //dar respuesta si hora o clave no tiene funcion
    //buscar funcion or titulo de peliucla
    //que pelicula hay en una sala

    //abrir archivos
    ifstream actores("actores.txt");
    ifstream peliculas("peliculas.txt");

    //
    actor a[500];
    pelicula p[20];
    funcion f[20];

    //cargar actores
    int id;
    string actor;
    int conta=0;
     while (!actores.eof())
    {
        actores >> id;
        a[conta].setId(id);
        getline(actores,actor);
        a[conta].setNombre(actor);
        conta++;
    }

    //cargar peliculas
    int numPeli;
    int ano;
    int duracion;
    string genero;
    int cantactores;
    int idact;
    string titulo;
    bool x=true;

    int contp=0;

      while (!peliculas.eof())
    {
        peliculas >> numPeli;
        p[contp].setNumPeli(numPeli);
        peliculas >> ano;
        p[contp].setAno(ano);
        peliculas >> duracion;
        p[contp].setDuracion(duracion);
        peliculas >> genero;
        p[contp].setGenero(genero);
        peliculas >> cantactores;

        for(int i=0;i<cantactores;i++){
                peliculas>>idact;

            x=p[contp].addtoListaActores(idact);
        }
        if(!x){
            cout<<"No se pudieron cargar todos los actores";
        }
        getline(peliculas,titulo);
        p[contp].setTitulo(titulo);

        contp++;
    }

    //cargar funciones
    int contf;
    cout<<"Cargar las funciones del dia"<<endl;
    cout<<"Cuantas funciones: ";
    cin>>contf;

    string cveFuncion;
    int numPelif;
    int sala;

    int hh,mm;
    hora hfuncion;
    for(int i=0;i<contf;i++){
        cout<<"Clave de funcion: ";
        cin>>cveFuncion;
        f[i].setCveFuncion(cveFuncion);
        cout<<"Numero de pelicula: ";
        cin>>numPelif;
        f[i].setNumeroPelicula(numPelif);
        cout<<"Hora de la funcion(HH,MM): ";
        cin>>hh>>mm;
        hfuncion.setHora(hh);
        hfuncion.setMin(mm);
        f[i].setHoraFuncion(hfuncion);
        cout<<"Sala: ";
        cin>>sala;
        f[i].setSala(sala);
    }

    //menu

    char op;
    do{
    cout<<"---------------------------------------------------------------\n";
    cout<<"Menu\n[A] Consulta de todos los actores que estan en la lista.\n[B] Consulta de todas las peliculas que estan en la lista.\n[C] Consulta de todas las funciones disponibles.";
    cout<<"\n[D] Consulta de funciones por hora.\n[E] Consulta por clave de funcion.\n[F] Consulta la lista peliculas en las que participa un actor.\n[G] Terminar.\n------------->  ";
    cin>>op;
    if(op=='A'||op=='a'){
    for(int i=0;i<conta;i++){
        a[i].display();
        cout<<endl;
    }
    }
    else if (op=='B'||op=='b'){
    for(int i=0;i<contp;i++){
       p[i].display();
       cout<<"Actores: "<<endl;
       for(int j=0;j<p[i].getCantidadActores();j++){
            int indice=p[i].getListaActores(j);
            for(int k=0;k<conta;k++){
                if(a[k].getId()==indice){
                    cout<<a[k].getNombre();
                    cout<<endl;
                }
            }
        }
        cout<<endl;
    }

    }
    else if (op=='C'||op=='c'){
    for(int i=0;i<contf;i++){
    cout<<" Clave de funcion: "<<f[i].getCveFuncion()<<endl;
    int tempo=f[i].getNumPelicula();
    for(int j=0;j<contf;j++){
        if(tempo==p[j].getNumPeli()){
            cout<<p[j].getTitulo();
        }
    }
    f[i].display();
    }

    }
    else if (op=='D'||op=='d'){
    cout<<"Ingrese una hora (hh,mm): ";
    cin>>hh>>mm;
    hora ht(hh,mm);
    for(int i=0;i<contf;i++){
    hora tm=f[i].getHoraFuncion();
    if(tm.getHora()==ht.getHora()){
        if(tm.getMin()==ht.getMin()){
            f[i].display();
        }
    }
    }
    }
    else if (op=='E'||op=='e'){
     cout<<"Ingrese clave de funcion: ";
     string  fun;
    cin>>fun;
    for(int i=0;i<contf;i++){
    if(fun==f[i].getCveFuncion()){
    cout<<" Clave de funcion: "<<f[i].getCveFuncion()<<endl;
    int tempo=f[i].getNumPelicula();
    for(int j=0;j<contf;j++){
        if(tempo==p[j].getNumPeli()){
            cout<<p[j].getTitulo();
        }
    }
    f[i].display();
    }
        }
    }
    else if (op=='F'||op=='f'){
    for(int i=0;i<contp;i++){
       for(int i=0;i<p[i].getCantidadActores();i++){

       }
    }
    }

    }while(op!='G'&&op!='g');










    return 0;
}
