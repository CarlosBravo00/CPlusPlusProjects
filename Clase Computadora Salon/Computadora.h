#ifndef COMPUTADORA_H_INCLUDED
#define COMPUTADORA_H_INCLUDED

class computadora{
public:
    computadora();
    computadora(string m,string os,int r);
    string getMarca();
    string getOS();
    int getRam();
    void setMarca(string m);
    void setOS(string os);
    void setRam (int r);


private:
    string marca;
    string sistemaOperativo;
    int Ram;
};

computadora::computadora(){
    marca="";
    sistemaOperativo="";
    Ram=0;
}

computadora::computadora (string m,string os,int r){
    marca=m;
    sistemaOperativo=os;
    Ram=r;
}

string computadora::getMarca(){
    return marca;
}

string computadora::getOS(){
    return sistemaOperativo;
}

int computadora::getRam(){
    return Ram;
}

void computadora::setMarca(string m){
    marca=m;
}

void computadora::setOS(string os){
    sistemaOperativo=os;
}

void computadora::setRam (int r){
    Ram=r;
}


#endif // COMPUTADORA_H_INCLUDED
