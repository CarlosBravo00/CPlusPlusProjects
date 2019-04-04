#ifndef TRIANGULO_H
#define TRIANGULO_H
using namespace std;


class Triangulo
{
    public:
        Triangulo();
        Triangulo (int lado,char caracter);
        void setLado(int lado);
        void setCaracter (char caracter);
        int getLado ();
        char setCaracter();
        void show();



    private:
    int lado;
    char caracter;
};

Triangulo::Triangulo(){
    lado=0;
    this->caracter=' ';

}
Triangulo::Triangulo(int lado,char caracter){
    this->lado=lado;
    this->caracter=caracter;
}
void Triangulo::setLado(int lado){
    this->lado=lado;
}

void Triangulo::setCaracter (char caracter){
    this->caracter=caracter;
}

int Triangulo::getLado (){
    return lado;
}

char Triangulo::setCaracter(){
    return caracter;
}

void Triangulo::show(){
    for(int i=1;i<=lado;i++){
        for(int j=1;j<lado-i;j++){
            cout<<" ";
        }
        for(int j=1;j<=i;j++){
            cout<<caracter<<" ";
        }
        cout<<endl;
    }
}



#endif // TRIANGULO_H
