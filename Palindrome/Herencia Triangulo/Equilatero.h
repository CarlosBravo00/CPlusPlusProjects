#ifndef Equilatero_h
#define Equilatero_h

class Equilatero {
public:
    Equilatero();
    Equilatero(int lado, char caracter);
    void setLado(int lado);
    int getLado();
    void setCaracter(char caracter);
    char getCaracter();
    void show();
protected:
    int lado;
    char caracter;
    int offset;
};

Equilatero::Equilatero()
 {
    lado = 1;
    caracter = '*';
    offset = 0;
}

Equilatero::Equilatero(int lado, char caracter)
 {
    this->lado = lado;
    this->caracter = caracter;
    this->offset = 0;
}

void Equilatero::setLado(int lado)
{
    this->lado = lado;
}

int Equilatero::getLado()
{
    return this->lado;
}

void Equilatero::setCaracter(char caracter)
 {
    this->caracter = caracter;
}

char Equilatero::getCaracter()
 {
    return this->caracter;
}

void Equilatero::show()
 {
    for (int i=1; i<=lado; i++) {
        for (int k=1; k<=(lado-i + offset); k++) {
            cout << " ";
        }
        for (int j=1; j<=i; j++) {
            cout << caracter << " ";
        }
        cout << endl;
    }

}

#endif
