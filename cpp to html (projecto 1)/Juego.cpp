//Carlos Bravo copyright
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void intro(){
cout<<" Hola "<<endl;
cout<<"Bienvendio a Mahjong!"<<endl;
cout<<"• El objetivo del juego es eliminar todas las fichas del tablero"<<endl;
cout<<"• Se pueden eliminar fichas del tablero seleccionando 2 fichas iguales que esten libres."<<endl;
cout<<"• Una ficha esta libre cuando no tiene fichas a su lado derecho o a su lado izquierdo."<<endl;
cout<<"• El jugador gana si elimina todas las fichas del tablero."<<endl;
cout<<endl<<"Enter para empezar";
cin.ignore();

}

void equivalencias (int &z,int x,int y){
    z=0;
for (int i=0;i<=x;i++){
    for (int j=0;j<=y;j++){
        z=(8*i)+j+1;
}}
}

void valorxy(int z,int &x,int &y){
    int cont=0;
for (int i=0;i<5;i++){
    for (int j=0;j<8;j++){
        cont++;
        if(cont==z){
            x=i;
            y=j;
            break;
        }
}}
}

void llenaTablero(char tablero[5][8], char figuras[10]){
    int iR, iC, iContFicha, iValorFicha;

    for (iR = 0; iR < 5; iR++){
        for (iC = 0; iC < 8; iC++){
            tablero[iR][iC] = ' ';
        }
    }
srand((int)time(0));
    for (iValorFicha = 0, iContFicha = 0; iValorFicha < 10;
iContFicha = 0, iValorFicha++)
    {
        do
        {
            iR = rand() % (5);
            iC = rand() % (8);
            if (tablero[iR][iC] == ' ')
            {
                tablero[iR][iC] = figuras[iValorFicha];
                iContFicha++;
            }
        } while (iContFicha != 4); // debo poner 4 Fichas de cada numero

    }

}

void imprimirver2 (char tablero[5][8]){
    int z;
for (int i=0;i<5;i++){
    for (int j=0;j<8;j++){
            equivalencias(z,i,j);

        if(z<10){
            if(tablero[i][j]==' '){
                cout<<"  "<<" "<<" "<<tablero[i][j]<<" ";
            }else cout<<"( "<<z<<")"<<tablero[i][j]<<" ";
        }else{
        if(tablero[i][j]==' '){
                cout<<"  "<<" "<<" "<<tablero[i][j]<<" ";
            }else cout<<"("<<z<<")"<<tablero[i][j]<<" ";}
    }
    cout<<endl;
}
}

void imprimir (char tablero[5][8]){
    int z;
for (int i=0;i<5;i++){
    for (int j=0;j<8;j++){
            equivalencias(z,i,j);

        if(z<10){
            cout<<"( "<<z<<")"<<tablero[i][j]<<" ";
        }else cout<<"("<<z<<")"<<tablero[i][j]<<" ";}

    cout<<endl;
}
}

void sigue(char &conf){
do {
        cout<<"Seguir? (S/N)";
       cin>>conf;
        }while((conf!='s')&&(conf!='S')&&(conf!='n')&&(conf!='N'));

}

void victoria(char tablero [5][8],bool &v){
    int cont=0;
for (int i=0;i<5;i++){
    for (int j=0;j<8;j++){
            if(tablero[i][j]==' '){
                cont++;
            }
    }
}

    if(cont==40){
        v=true;
    }else v=false;
}

void fichaa(char tablero[5][8]){
    int cont=0;
for (int i=0;i<5;i++){
    for (int j=0;j<8;j++){
            if(tablero[i][j]!=' '){
                cont++;
            }
    }
}
    cout<<"Quedan "<<cont<<" Fichas"<<endl;


}

void checarc1(int &c1, char tablero[5][8]){
    int x=0,y=0;
    valorxy(c1,x,y);
    if(c1>40||c1<1){
        cout<<"Casilla no esta en el tablero"<<endl;
        c1=-1;
    }
    else if(tablero[x][y]==' '){
        cout<<"Casilla no tiene ficha"<<endl;
        c1=-1;
    }
    else if(y!=0&&y!=7){
        if((tablero[x][y-1]!=' ')&&(tablero[x][y+1]!=' ')){
            c1=-1;
            cout<<"Casilla no esta libre"<<endl;
        }
    }
}

void checarc2(int &c2, char tablero[5][8], int c1){
    int x=0,y=0;
     int x1=0,y1=0;
     valorxy(c2,x,y);
     valorxy(c1,x1,y1);
    if (c2==c1){
        c2=-1;
        cout<<"Casillas no pueden ser iguales"<<endl;
    }
    else if(c2>40||c2<0){
        cout<<"Casilla no esta en el tablero"<<endl;
        c2=-1;
    }
    else if(tablero[x][y]==' '){
            c2=-1;
        cout<<"Casilla no tiene ficha"<<endl;
    }
    else if(y!=0&&y!=7){
        if((tablero[x][y-1]!=' ')&&(tablero[x][y+1]!=' ')){
            c2=-1;
            cout<<"Casilla no esta libre"<<endl;
        }
    }
}

void juego(int c1,int c2,char tablero[5][8]){
int x=0,y=0;
int x1=0,y1=0;
valorxy(c1,x,y);
valorxy(c2,x1,y1);

if(tablero[x][y]==tablero[x1][y1]){
        tablero[x][y]=' ';
        tablero[x1][y1]=' ';
    }else cout<<"No son iguales las fichas"<<endl;
}

void mensajev(){
cout<<"------------------------------------------------"<<endl;
cout<<"------------------------------------------------"<<endl;
cout<<"------------------------------------------------"<<endl;
cout<<"--------------------VICTORIA--------------------"<<endl;
cout<<"------------------------------------------------"<<endl;
cout<<"------------------------------------------------"<<endl;
cout<<"------------------------------------------------"<<endl;

}

int main()
{
    intro();
    char tablero[5][8];
    char figuras [10] = {'A','B','C','D','E','F','G','H','I','J'};
    char conf;
    bool v;
    int c1,c2;
    char nivel;

    do{
    llenaTablero(tablero,figuras);

    do {
        cout<<"Nivel (D---Dificil/F---Facil)";
       cin>>nivel;
        }while((nivel!='D')&&(nivel!='d')&&(nivel!='F')&&(nivel!='f'));


    //juego
cout<<"------------------------------------------------"<<endl;
    if (nivel=='F'||nivel=='f'){
        imprimirver2(tablero);
    }else imprimir(tablero);
cout<<"------------------------------------------------"<<endl;

    do{
        fichaa(tablero);
        //trabajo

        do{
        cout<<"Casilla 1 --> ";
        cin>>c1;
        checarc1(c1,tablero);
        }while(c1==-1);

        do{
        cout<<"Casilla 2 --> ";
        cin>>c2;
        checarc2(c2,tablero,c1);
        }while(c2==-1);

        juego(c1,c2,tablero);
        victoria(tablero,v);
        if (v){
            mensajev();
            break;
        }
        cout<<"------------------------------------------------"<<endl;
        if (nivel=='F'||nivel=='f'){
        imprimirver2(tablero);
            }else imprimir(tablero);
        cout<<"------------------------------------------------"<<endl;
        sigue(conf);
         }while(conf=='S'||conf=='s');

     do {
        cout<<"Nueva partida? (S/N)";
       cin>>conf;
        }while((conf!='s')&&(conf!='S')&&(conf!='n')&&(conf!='N'));


    }while(conf=='S'||conf=='s');


    return 0;
}
