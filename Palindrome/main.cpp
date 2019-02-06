#include <iostream>


using namespace std;

int main()
{
    int x;
    string Palabra;
    string A;
    int con=0;

    cin>>Palabra;


    x= Palabra.size();

    for(int i=0,j=x-1;i<x;i++,j--){
        A[j]=Palabra[i];
  }

 for(int i=0;i!=x;i++){
        if (A[i]==Palabra[i]){
            con++;
        }
}
if (con==x){
    cout<<"Si es palindrome";
} else cout<<"No es palindrome";
    return 0;
}
