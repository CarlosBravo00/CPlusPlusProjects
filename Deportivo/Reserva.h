#ifndef Reserva_h
#define Reserva_h

class Reserva{
public:
    Reserva();
    Reserva(string clave,int id,Reloj Hora,int du);
    string getClaveServicio();
    int getIdCliente();
    Reloj getHoraInicio();
    int getDuracion();
    void setClaveServicio(string claveServicio);
    void setIdCliente (int idCliente);
    void setHoraInicio(Reloj HoraInicio);
    void setDuracion(int duracion);
    Reloj calculaHoraFinReservacion();

private:
    string claveServicio;
    int idCliente;
    Reloj HoraInicio;
    int duracion;
};

 Reserva::Reserva(){
 claveServicio="";
idCliente=0;
Reloj r(0,0);
HoraInicio=r;
 duracion=0;
 }


Reserva::Reserva(string clave,int id,Reloj Hora,int du){
claveServicio=clave;
idCliente=id;
HoraInicio=Hora;
 duracion=du;
}
string Reserva::getClaveServicio(){
return claveServicio;
}
int Reserva::getIdCliente(){
return idCliente;
}
Reloj Reserva::getHoraInicio(){
return HoraInicio;
}
int Reserva::getDuracion(){
return duracion;
}
void Reserva::setClaveServicio(string claveServicio){
this->claveServicio=claveServicio;
}
void Reserva::setIdCliente (int idCliente){
this->idCliente=idCliente;
}
void Reserva::setHoraInicio(Reloj HoraInicio){
this->HoraInicio=HoraInicio;
}
void Reserva::setDuracion(int duracion){
this->duracion=duracion;
}

Reloj Reserva::calculaHoraFinReservacion(){
return HoraInicio+duracion;
}




#endif // RESERVA_H_INCLUDED
