#ifndef PELICULA_H_INCLUDED
#define PELICULA_H_INCLUDED

class pelicula{
public:

pelicula();

int getNumPeli();
string getTitulo();
int getAno();
int getDuracion();
string getGenero();
int getCantidadActores();


int getListaActores (int id);

void setNumPeli(int np);
void setTitulo(string tit);
void setAno(int a);
void setDuracion(int du);
void setGenero(string ge);

bool addtoListaActores(int id);

void display();

private:

int numPeli;
string titulo;
int ano;
int duracion;
string genero;
int cantidadActores;
int listaActores[10];

};

pelicula::pelicula(){
 numPeli=0;
titulo="";
ano=0;
duracion=0;
genero="";
cantidadActores=0;
for(int i=0;i<10;i++){
  listaActores[i]=0;
}
}

int pelicula::getNumPeli(){
return numPeli;
}
string pelicula::getTitulo(){
return titulo;
}
int pelicula::getAno(){
return ano;
}
int pelicula::getDuracion(){
return duracion;
}
string pelicula::getGenero(){
return genero;
}
int pelicula::getCantidadActores(){
return cantidadActores;
}

int pelicula::getListaActores (int indice){
return listaActores[indice];
}

void pelicula::setNumPeli(int np){
numPeli=np;
}
void pelicula::setTitulo(string tit){
titulo=tit;
}
void pelicula::setAno(int a){
ano=a;
}
void pelicula::setDuracion(int du){
duracion=du;
}
void pelicula::setGenero(string ge){
genero=ge;
}

bool pelicula::addtoListaActores(int id){
    bool x=true;
    if(cantidadActores==10){
        x=false;
    }else {
    for(int i=0;i<10;i++){
        if(listaActores[i]==id){
        x=false;
        }
    }
    }
    if(x){
     listaActores[cantidadActores]=id;
     cantidadActores++;
    }
   return x;


}

void pelicula::display(){
cout<<"Titulo: "<<titulo<<"\nNumero de pelicula: "<<numPeli<<"\nAño: "<<ano
       <<"\nDuracion: "<<duracion<<" Minutos\nGenero: "<<genero
       <<"\nCantidad de Actores: "<<cantidadActores<<endl;
        cout<<endl;
}

#endif // PELICULA_H_INCLUDED
