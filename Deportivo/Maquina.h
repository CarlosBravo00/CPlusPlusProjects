#ifndef MAQUINA_H_INCLUDED
#define MAQUINA_H_INCLUDED

class Maquina:public Servicio{
public:
    Maquina();
    Maquina(double costoX15min,bool conInstructor,string descripcion,string clave,int tiempoMax,char tipo);
    double getCostoX15min();
    bool getConInstructor();
    string getDescripcion();
    void setCostoX15min(double costoX15min);
    void setConInstructor(bool conInstructor);
    void setDescripcion(string descripcion);

    void muestra();
    double calculaCosto(int tiempo);

private:
    double costoX15min;
    bool conInstructor;
    string descripcion;
};

Maquina::Maquina():Servicio(){
    costoX15min=0;
    conInstructor=false;
    descripcion="";

 }
Maquina::Maquina(double costoX15min,bool conInstructor,string descripcion,string clave,int tiempoMax,char tipo):Servicio(clave,tiempoMax,tipo){
this->costoX15min=costoX15min;
this->conInstructor=conInstructor;
this->descripcion=descripcion;
}


double Maquina::getCostoX15min(){
    return costoX15min;
}
bool Maquina::getConInstructor(){
    return conInstructor;
}
string Maquina::getDescripcion(){
    return descripcion;
}
void Maquina::setCostoX15min(double costoX15min){
    this->costoX15min=costoX15min;
}
void Maquina::setConInstructor(bool conInstructor){
    this->conInstructor=conInstructor;
}
void Maquina::setDescripcion(string descripcion){
    this->descripcion=descripcion;
}

void Maquina::muestra(){
   cout<<"Servicio: Aparato";
   cout<<"\nTipo: ";
   if(tipo=='C'){
    cout<<"Caminadora";
   }
   else if(tipo=='E'){
    cout<<"Escaladora";
   }
   else if(tipo=='B'){
    cout<<"Bicicleta estacionaria";
   }

   cout<<"\nClave: "<<clave<<"\nTiempo Max: "<<tiempoMax;
   cout<<"\nCosto por 15 minutos: "<<costoX15min<<"\nDescrpcion: "<<descripcion<<"\nCon Instructor: ";
   if(conInstructor){
    cout<<"si";
   }else cout<<"no";
}
double Maquina::calculaCosto(int tiempo){
    double tiempodouble=tiempo;
    tiempodouble=tiempodouble/15;
    return tiempodouble*costoX15min;
}



#endif // MAQUINA_H_INCLUDED
