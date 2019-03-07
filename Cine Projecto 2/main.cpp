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
    ifstream actores("actores.txt");
    ifstream peliculas("peliculas.txt");

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
    int numactor;
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






    //cargar peliculas

    return 0;
}
