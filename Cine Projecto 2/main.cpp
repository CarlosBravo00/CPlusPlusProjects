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
    for(int i=0;i<conta;i++){
        a[i].display();
        cout<<endl;
    }

    //cargar peliculas
    int numPeli;
    int ano;
    int duracion;
    string genero;
    int cantactores;
    int idact;
    string titulo;
    bool x;

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
        getline(peliculas,titulo);
        p[contp].setTitulo(titulo);

        contp++;
    }
    for(int i=0;i<contp;i++){
        cout<<p[i].getNumPeli()<<p[i].getAno()<<p[i].getDuracion()<<p[i].getGenero()<<p[i].getCantidadActores()<<p[i].getTitulo()<<endl;

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
    if(op=='A'){
    for(int i=0;i<conta;i++){
        a[i].display();
        cout<<endl;
    }
    }
    else if (op=='B'){
    for(int i=0;i<contp;i++){
       cout<<p[i].getNumPeli()<<p[i].getAno()<<p[i].getDuracion()<<p[i].getGenero()<<p[i].getCantidadActores()<<p[i].getTitulo()<<endl;
        cout<<endl;
    }

    }
    else if (op=='C'){
    for(int i=0;i<contf;i++){
        f[i].display();
        cout<<endl;
    }

    }

    else if (op=='D'){

    }
    else if (op=='E'){

    }
    else if (op=='F'){
    for(int i=0;i<contp;i++){
       for(int i=0;i<p[i].getCantidadActores();i++){

       }
    }
    }

    }while(op!='G');










    return 0;
}
