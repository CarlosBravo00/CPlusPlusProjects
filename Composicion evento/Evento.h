#ifndef EVENTO_H_INCLUDED
#define EVENTO_H_INCLUDED


class Evento{
  public:
    Evento();
    Evento(reloj hi,int d,string a);
    reloj getHoraInicial();
    int getDuracion();
    string getAsunto();
    void setHoraInicial(reloj hi);
    void setDuracion (int d);
    void setAsunto(string a);

 private:
    reloj horaInicial;
    int duracion;
    string asunto;


};

Evento::Evento(){
    reloj hi(0,0);
    horaInicial=hi;
    duracion=0;
    asunto="";
}

Evento::Evento(reloj hi,int d,string a){
 horaInicial=hi;
 duracion=d;
 asunto=a;
}

reloj Evento::getHoraInicial(){
return horaInicial;
}

int Evento::getDuracion(){
return duracion;
}

string Evento::getAsunto(){
return asunto;
}

void Evento::setHoraInicial(reloj hi){
    horaInicial=hi;
}

void Evento::setDuracion (int d){
    duracion=d;
}

void Evento::setAsunto(string a){
    asunto=a;
}


#endif // EVENTO_H_INCLUDED
