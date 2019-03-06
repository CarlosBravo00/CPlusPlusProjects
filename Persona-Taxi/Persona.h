#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

class Persona{
public:
    Persona();
    Persona(string nom,string cel);
    string getNombre();
    string getNumCel();
    void setNombre (string nom);
    void setNumCel (string cel);


private:
    string nombre;
    string numCel;

};

Persona::Persona(){
nombre="";
numCel="";
}

Persona::Persona(string nom,string cel){
nombre=nom;
numCel=cel;
}
string Persona::getNombre(){
    return nombre;
}
string Persona::getNumCel(){
    return numCel;
}

void Persona::setNombre (string nom){
    nombre=nom;
}

void Persona::setNumCel (string cel){
    numCel=cel;

}

#endif // PERSONA_H_INCLUDED
