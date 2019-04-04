#ifndef Cuadratica_h
#define Cuadratica_h

class Cuadratica {
    public:Cuadratica();
    Cuadratica(int, int, int);
    void muestra();

    Cuadratica operator + (Cuadratica c);
    Cuadratica operator - (Cuadratica c1,Cuadratica c2);
    Cuadratica operator * (int x);
   Cuadratica operator += (Cuadratica c1,Cuadratica c2);
    bool operator == (Cuadratica c);
    Cuadratica operator ++ (Cuadratica c1);


    private:
    int iCoefA, iCoefB, iCoefC;

    };

    Cuadratica Cuadratica::operator + (Cuadratica c){
        Cuadratica resultado(iCoefA+c.iCoefA,iCoefB+c.iCoefB,iCoefC+c.iCoefC);
        return resultado;
    }
    Cuadratica Cuadratica::operator - (Cuadratica c1,Cuadratica c2){
        Cuadratica resultado(c1.iCoefA-c2.iCoefA,c1.iCoefB-c2.iCoefB,c1.iCoefC-c2.iCoefC);
        return resultado;
    }
     Cuadratica Cuadratica::operator * (int x){
        Cuadratica resultado(iCoefA*x,iCoefB*x,iCoefC*x);
        return resultado;
    }
    Cuadratica Cuadratica::operator += (Cuadratica c1,Cuadratica c2){
        Cuadratica resultado(iCoefA-c.iCoefA,iCoefB-c.iCoefB,iCoefC-c.iCoefC);
        return resultado;
    }
    bool Cuadratica::operator == (Cuadratica c){

    }

    Cuadratica Cuadratica::operator ++ (Cuadratica c1,Cuadratica c2){
        Cuadratica resultado(iCoefA-c.iCoefA,iCoefB-c.iCoefB,iCoefC-c.iCoefC);
        return resultado;
    }

Cuadratica::Cuadratica() {
    iCoefA = 1;iCoefB = 1;iCoefC = 1;
    }
Cuadratica::Cuadratica(int iA, int iB, int iC){
    iCoefA = iA;iCoefB = iB;iCoefC = iC;
    }
void Cuadratica::muestra() {
        if (iCoefA != 0){
            cout << iCoefA;cout << "x^2 ";
        }
        if (iCoefB != 0)
        {
        if (iCoefB > 0)
        {
        cout << " + ";
        }
        cout << iCoefB;cout << "x ";
        }
        if (iCoefC != 0{
        if (iCoefC > 0) {
        cout << " + ";
        }
        cout << iCoefC << endl;

        }

}


#endif
