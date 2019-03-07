#ifndef ACTOR_H_INCLUDED
#define ACTOR_H_INCLUDED

class actor{
public:
actor();
actor(string i,string n);
void setId(string i);
void setNombre(string n);
string getId();
string getNombre();
void display();
private:
string id;
string nombre;
};

actor::actor(){
id="";
nombre="";
}

actor::actor(string i,string n){
id=i;
nombre=n;
}

void actor::setId(string i){
id=i;
}

void actor::setNombre(string n){
nombre=n;
}
string actor::getId(){
return id;
}
string actor::getNombre(){
return id;
}
void actor::display(){
cout<<"Id: "<<id<<" Nombre: "<<nombre;
}

#endif // ACTOR_H_INCLUDED
