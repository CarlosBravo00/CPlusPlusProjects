#include <iostream>
#include <string>
using namespace std;
#include "Equilatero.h"
#include "EquilateroNombre.h"

int main() {

    cout << "nombre: ";
    string nombre = "";
    getline(cin,nombre);
    cout << "niveles: ";
    int niveles;
    cin >> niveles;
    cout << "caracter: ";
    char caracter;
    cin >> caracter;
    cout << endl;
    EquilateroNombre etn(niveles,caracter,nombre);
    etn.show();
    return 0;

}
