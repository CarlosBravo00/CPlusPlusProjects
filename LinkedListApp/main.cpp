#include <iostream>

using namespace std;

#include "LinkedList.h"

int main(){
	LinkedList<string> miLista;
	miLista.addFirst("HOLA");
	miLista.addLast("CRAYOLA");
	miLista.print();
	LinkedList<int> tuLista;
	tuLista.addLast(5);
	tuLista.addLast(10);
	tuLista.addFirst(1);
	tuLista.print();
}
