#include <iostream>

using namespace std;

int main()

{

  int matriz[4][4];
  int n;
  int nmatriz[4][4];

  cin>>n;
  n=n%4;
  for (int i = 0; i<4 ; i++){
        for (int j = 0; j<4; j++){
            cin>>matriz[i][j];
        }
  }
  if (n>0){
    for(int i=0; i<n ;i++){
        for (int i = 0; i<4 ; i++){
        for (int j = 0; j<4; j++){
            nmatriz[j][3-i] = matriz[i][j];
        }
          }

    for (int i = 0; i<4 ; i++){
        for (int j = 0; j<4; j++){
             matriz[i][j] = nmatriz[i][j];
        }
          }

}
  }
else if (n<0){
      for(int i=0; i>n ;i--){
          for (int i = 0; i<4 ; i++){
        for (int j = 0; j<4; j++){

           nmatriz[3-j][i] = matriz[i][j];
    }
  }
      for (int i = 0; i<4 ; i++){
        for (int j = 0; j<4; j++){
             matriz[i][j] = nmatriz[i][j];
        }
          }
}
    }
        for (int i = 0; i<4 ; i++){
        for (int j = 0; j<4; j++){
            cout<<matriz[i][j];
            if (j != 3){
                cout<<" ";
            }
        }
        cout<<endl;

  }

    return 0;
}
