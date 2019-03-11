#ifndef FUNCION_H_INCLUDED
#define FUNCION_H_INCLUDED

class funcion{
public:
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
    void display();

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
    cveFuncion=cvef;
}

void funcion::setNumeroPelicula(int num){
    numPeli=num;
}

void funcion::setHoraFuncion(hora h){
    hra=h;
}

void funcion::setSala(int s){
    sala=s;
}

string funcion::getCveFuncion(){
    return cveFuncion;
}

int funcion::getNumPelicula(){
    return numPeli;
}

hora funcion::getHoraFuncion(){
    return hra;
}

int funcion::getSala(){
    return sala;
}

void funcion::display(){
cout<<endl;
cout<<" Clave de funcion: "<<cveFuncion;
cout<<endl;
cout<<" Hora de funcion: ";
hra.display();
cout<<endl;
cout<<" Sala: "<<sala;
cout<<endl;
cout<<endl;
}

#endif // FUNCION_H_INCLUDED
