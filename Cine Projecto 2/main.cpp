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
    //Display de actores
    if(op=='A'||op=='a'){
    for(int i=0;i<conta;i++){
        a[i].display();
        cout<<endl;
    }
    }
    //Display de peliculas
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
    //Display de funciones
    else if (op=='C'||op=='c'){
    for(int i=0;i<contf;i++){
    int tempo=f[i].getNumPelicula();
    for(int j=0;j<contp;j++){
        if(tempo==p[j].getNumPeli()){
            cout<<p[j].getTitulo()<<endl;
        }
    }
    f[i].display();
    }
    }
    //Buscar funcion por hora
    else if (op=='D'||op=='d'){
    do{
    cout<<"Ingrese hora (0-23): ";
    cin>>hh;
    }while(hh>23||hh<0);
    do{
    cout<<"Ingrese minutos (0-59): ";
    cin>>mm;
    }while(mm>59||mm<0);

    hora ht(hh,mm);
    bool bayli=false;
    cout<<endl;
    for(int i=0;i<contf;i++){
    hora tm=f[i].getHoraFuncion();
    if(tm.getHora()==ht.getHora()){
        if(tm.getMin()==ht.getMin()){
            bayli=true;
            int tempo=f[i].getNumPelicula();
            for(int j=0;j<contp;j++){
            if(tempo==p[j].getNumPeli()){
            cout<<p[j].getTitulo()<<endl;
            }}
            cout<<" Sala: "<<f[i].getSala()<<endl<<endl;
    }
    }
    }
    if(!bayli){
        cout<<"No hay funciones a esta hora"<<endl;
    }
}
    //Buscar por clave de funcion
    else if (op=='E'||op=='e'){
     cout<<"Ingrese clave de funcion: ";
     string  fun;
    bool pepe=false;
    cin>>fun;
    for(int i=0;i<contf;i++){
        if(fun==f[i].getCveFuncion()){
            int tempo=f[i].getNumPelicula();
            for(int j=0;j<contp;j++){
            if(tempo==p[j].getNumPeli()){
            cout<<p[j].getTitulo()<<endl;
            cout<<" Duracion: "<<p[j].getDuracion()<<" Minutos"<<endl;
            cout<<" Genero: "<<p[j].getGenero()<<endl;
            cout<<" Actores: "<<endl;
            for(int k=0;k<p[j].getCantidadActores();k++){
            int indice=p[j].getListaActores(k);
            for(int l=0;l<conta;l++){
                if(a[l].getId()==indice){
                    cout<<a[l].getNombre();
                    cout<<endl;
                }
            }
        }
            }
            }
            f[i].display();
            pepe=true;
            }
        }
    if (!pepe){
        cout<<"Clave no tiene funcion"<<endl;
    }
    }
    //Buscar por id de actor
    else if (op=='F'||op=='f'){
    int idactor;
    cout<<"Id del Actor: ";
    cin>>idactor;
    bool marco=false;
    for(int k=0;k<conta;k++){
    if(a[k].getId()==idactor){
        cout<<a[k].getNombre();
        marco=true;
        cout<<endl<<endl;
    }
    }
    if(marco){
    for(int i=0;i<contp;i++){
       for(int j=0;j<p[i].getCantidadActores();j++){
            if(idactor==p[i].getListaActores(j)){
                cout<<p[i].getTitulo()<<endl<<" Año: "<<p[i].getAno()<<endl;
                cout<<endl;
            }
       }
    }
    }else cout<<"No existe Id actor"<<endl;
    }

    }while(op!='G'&&op!='g');

    return 0;
}
