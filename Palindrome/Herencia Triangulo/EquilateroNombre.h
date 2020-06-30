#ifndef EquilateroNombre_h
#define EquilateroNombre_h

class EquilateroNombre: public Equilatero {
public:
    EquilateroNombre();
    EquilateroNombre(int lado, char caracter, string nombre);
    void setNombre(string nombre);
    string getNombre();
    void show();
protected:
    string nombre;
    int offsetn;
};

EquilateroNombre::EquilateroNombre() : Equilatero()
 {
    this->nombre = "*";
    offsetn = 0;
}

EquilateroNombre::EquilateroNombre(int lado, char caracter, string nombre) : Equilatero(lado, caracter)
 {
    this->nombre = nombre;
    offsetn = 0;
}

void EquilateroNombre::setNombre(string nombre)
 {
    this->nombre = nombre;
}

string EquilateroNombre::getNombre()
 {
    return this->nombre;
}

void EquilateroNombre::show()
 {
    if (nombre.length() > lado * 2 - 1)
        {
        offset = (nombre.length() - (lado * 2 - 1)) / 2;
    }
    else
    {
        offsetn = ((lado * 2 - 1)-nombre.length())/2;
    }
    Equilatero::show();
    for (int i=1; i<=offsetn; i++)
        {
        cout << " ";
    }
    cout << nombre << endl;

}



#endif
