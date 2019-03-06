#ifndef TAXI_H_INCLUDED
#define TAXI_H_INCLUDED

class Taxi{
public:

Taxi();
Taxi(Persona res,int id);
void setResponsable(Persona res);
void setIdnet(int id);
Persona getResponsable();
int getIdent();



private:
Persona responsable;
int ident;
};

Taxi::Taxi(){
Persona vacio("","");
responsable=vacio;
ident=0;
}
Taxi::Taxi(Persona res,int id){
responsable=res;
ident=id;

}
void Taxi::setResponsable(Persona res){
    responsable=res;
}
void Taxi::setIdnet(int id){
    ident=id;
}
Persona Taxi::getResponsable(){
    return responsable;
}
int Taxi::getIdent(){
    return ident;
}



#endif // TAXI_H_INCLUDED
