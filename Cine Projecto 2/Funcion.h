#ifndef FUNCION_H_INCLUDED
#define FUNCION_H_INCLUDED

class funcion{
    funcion();
    funcion(string cveF, int num, hora h, int s);
    void setCveFuncion(string cvef);
    void setNumeroPelicula(int num);
    void setHoraFuncion(hora h);
    void setSala(int s);
    string getCveFuncion();
    int getNumPelicula();
    hora getHoraFuncion();
    int getSala();

private:
    string cveFuncion;
    int numPeli;
    hora hra;
    int sala;
};

funcion::funcion(){
    cveFuncion="";
    numPeli=0;
    hora vacio(0,0);
    hra=vacio;
    sala=0;
}
funcion::funcion(string cveF, int num, hora h, int s){
    cveFuncion=cveF;
    numPeli=num;
    hra=h;
    sala=s;
}

void funcion::setCveFuncion(string cvef){
}

void funcion::setNumeroPelicula(int num){
}

void funcion::setHoraFuncion(hora h){
}

void funcion::setSala(int s){
}

string funcion::getCveFuncion(){
}

int funcion::getNumPelicula(){
}

hora funcion::getHoraFuncion(){
}

int funcion::getSala(){
}



#endif // FUNCION_H_INCLUDED
