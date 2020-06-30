#include <iostream>

using namespace std;

 void funcion(){
 string numero;
    int numtempo;
    cout<<"Teclea el numero de 9 digitos"<<endl;
    getline(cin,numero);
    int total=0;
    for(int i=0;i<9;){
        numtempo=numero[i]-48;
        i++;
        total=total+numtempo*i;
    }
    total=total%11;
    if(total==10){
        cout<<"El ISBN es "<<numero<<"-X";
    }else cout<<"El ISBN es "<<numero<<"-"<<total;
 }

int main()
{
    bool x;
    char y;
    do{
    funcion();
    cout<<endl<<"Otro ?  ";
    cin>>y;
    if(y=='S'||y=='s'){
        x=true;
        cin.ignore();
    } else  x=false;
    }while (x);
    return 0;
}
