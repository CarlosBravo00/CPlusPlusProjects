#include <iostream>

using namespace std;

void functionx(int &a,int &b,int c)
{
    a=a*60;
    b=a+b;
    c=c+b;

    a=c/60;
    b=c%60;

}


int main()
{
    int hora, minutos, tarda;
    cin >>hora>>minutos>>tarda;

    functionx(hora,minutos,tarda);


    cout <<hora<<" "<<minutos<<endl;
    return 0;
}
