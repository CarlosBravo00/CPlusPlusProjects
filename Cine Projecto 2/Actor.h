#ifndef ACTOR_H_INCLUDED
#define ACTOR_H_INCLUDED

class actor{
public:
actor();
actor(int i,string n);
void setId(int i);
void setNombre(string n);
int getId();
string getNombre();
void display();

private:
int id;
string nombre;
};

actor::actor(){
id=0;
nombre="";
}

actor::actor(int i,string n){
id=i;
nombre=n;
}

void actor::setId(int i){
id=i;
}

void actor::setNombre(string n){
nombre=n;
}

int actor::getId(){
return id;
}

string actor::getNombre(){
return nombre;
}

void actor::display(){
cout<<"Id: "<<id<<" Nombre: "<<nombre;
}

#endif // ACTOR_H_INCLUDED
