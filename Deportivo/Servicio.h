
#ifndef APARATO_H_INCLUDED
#define APARATO_H_INCLUDED

class Servicio{
public:
    Servicio();
    Servicio(string clave,int tiempoMax,char tipo);
    string getClave();
    int getTiempoMax();
    char getTipo();
    void setClave(string clave);
    void setTiempoMax (int tiempoMax);
    void setTipo(char tipo);

    virtual void muestra()=0;
    virtual double calculaCosto(int tiempo)=0;

protected:
    string clave;
    int tiempoMax;
    char tipo;
};
Servicio::Servicio(){
clave="";
tiempoMax=0;
tipo=' ';
}

Servicio::Servicio(string clave,int tiempoMax,char tipo){
this->clave=clave;
this->tiempoMax=tiempoMax;
this->tipo=tipo;
}


string Servicio::getClave(){
return clave;
    }
int Servicio::getTiempoMax(){
return tiempoMax;
    }
char Servicio::getTipo(){
return tipo;
    }
void Servicio::setClave(string clave){
    this->clave=clave;
    }
void Servicio::setTiempoMax (int tiempoMax){
    this->tiempoMax=tiempoMax;
    }
void Servicio::setTipo(char tipo){
    this->tipo=tipo;
    }

void Servicio::muestra(){
cout<<"Clave: "<<clave<<"\nTiempo Max: "<<tiempoMax<<"\nTipo: "<<tipo<<endl;
}



#endif // APARATO_H_INCLUDED

