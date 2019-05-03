#ifndef CANCHA_H_INCLUDED
#define CANCHA_H_INCLUDED

class Cancha:public Servicio{
public:
    Cancha();
    Cancha(double costo,int maxpers, string deporte, string clave, int tiempoMax,char tipo);
    double getCostoXHr();
    int getCantMaxPers();
    string getDeporte();
    void setCostoXHr(double costo);
    void setCantMaxPers(int cant);
    void setDeporte (string depor);

    void muestra();
    double calculaCosto(int tiempo);

private:
    double costoXHr;
    int cantMaxPers;
    string Deporte;
};

Cancha::Cancha():Servicio(){
    costoXHr=0;
    cantMaxPers=0;
    Deporte="";
}

Cancha::Cancha(double costo,int maxpers, string deporte, string clave, int tiempoMax,char tipo):Servicio(clave,tiempoMax,tipo){
    costoXHr=costo;
    cantMaxPers=maxpers;
    this->Deporte=deporte;
}

double Cancha::getCostoXHr(){
    return costoXHr;

}
int Cancha::getCantMaxPers(){
    return cantMaxPers;

}
string Cancha::getDeporte(){
    return Deporte;

}
void Cancha::setCostoXHr(double costo){
    costoXHr=costo;

}
void Cancha::setCantMaxPers(int cant){
    cantMaxPers=cant;

}
void Cancha::setDeporte (string depor){
    Deporte=depor;
}


void Cancha::muestra(){
cout<<"Servicio: Cancha";
   cout<<"\nTipo: ";
   if(tipo=='T'){
    cout<<"Cancha Tenis";
   }
   else if(tipo=='F'){
    cout<<"Cancha Fronton";
   }
   else if(tipo=='V'){
    cout<<"Cancha Volley Ball";
   }

cout<<"\nClave: "<<clave<<"\nTiempo Max: "<<tiempoMax;
cout<<"\nDeporte: "<<Deporte<<"\nCantidad maxima de personas: "<<cantMaxPers<<"\nCosto por hora: "<<costoXHr;
}

double Cancha::calculaCosto(int tiempo){
     double tiempodouble=tiempo;
    tiempodouble=tiempodouble/60;
    return tiempodouble*costoXHr;
}

#endif // CANCHA_H_INCLUDED
