#ifndef Reloj_h
#define Reloj_h

class Reloj {
private:
    int hora;
    int minu;
public:
    Reloj();
    Reloj(int h);
    Reloj(int h, int m);
    void setHora(int h);
    void setMin(int m);
    int getHora();
    int getMin();
    friend istream& operator >> (istream &is, Reloj &r);
    friend ostream& operator << (ostream &os, Reloj r);
    void operator++();  // incrementa un minuto al reloj
    void operator--();  // decrementa un minuto al reloj
    Reloj operator+(int m);  // suma un Reloj con una cantidad de minutos y regresa el nuevo Reloj
    friend Reloj operator+(Reloj r1,Reloj r2);  // suma un Reloj con otro Reloj y regresa un nuevo Reloj
    Reloj operator-(int m);  // a un Reloj le resta una cantidad de minutos y regresa el nuevo Reloj
    friend Reloj operator-(Reloj r1,Reloj r2); // a un Reloj le resta otro Reloj y regresa el nuevo Reloj
    bool operator>(Reloj r);  // regresa true/false si el primer Reloj es > el segundo
    bool operator<(Reloj r); // regresa true/false si el primer Reloj es < el segundo
    bool operator==(Reloj r); // regresa true/false si ambos relojes son iguales
    bool operator <= (Reloj r); // regresa true/false si el primer Reloj es <= el segundo
    bool operator >= (Reloj r);// regresa true/false si el primer Reloj es >= el segundo
    void operator -=(int m);
    void operator +=(int m);

};

istream& operator >> (istream &is, Reloj &r){
is>>r.hora;
is>>r.minu;
return is;
}


ostream& operator << (ostream &os, Reloj r){
  if (r.hora<10){
        os << "0";
  }
    os <<r.hora<<" ";
if (r.minu<10){
        os << "0";
}
    os  <<r.minu;
return os;
}

Reloj::Reloj(){
    hora = 0;
    minu = 0;
}
Reloj::Reloj(int h){
    hora = h;
    minu = 0;
}
Reloj::Reloj(int h, int m){
    hora = h;
    minu = m;
}

void Reloj::setHora(int h){
    hora = h;
}

void Reloj::setMin(int m){
    minu = m;
}

int Reloj::getHora(){
    return hora;
}

int Reloj::getMin(){
    return minu;
}


void Reloj::operator++(){
    minu++;
    if(minu == 60){
        minu=0;
        hora++;
        if(hora == 24){
            hora=0;
        }
    }
}

void Reloj::operator--(){
    minu--;
    if(minu == -1){
        minu=59;
        hora--;
        if(hora == -1){
            hora=23;
        }
    }
}

void Reloj::operator+=(int m){
    minu=minu+m;
    while(minu>=60){
        minu=minu-60;
        hora=hora+1;
        if(hora== 24){
            hora=0;
        }
    }
}

void Reloj::operator-=(int m){
    minu=minu-m;
    while(minu < 0){
        minu=minu+60;
        hora=hora-1;
        if(hora== 0){
            hora=23;
        }
    }
}

Reloj Reloj::operator+(int m){
Reloj r= *this;
r.minu=r.minu+m;
while (r.minu>=60){
    r.minu=r.minu-60;
    r.hora=r.hora + 1;
    if(r.hora==24){
        r.hora = 0;
    }
}
return r;
}

Reloj Reloj::operator-(int m){
Reloj r= *this;
r.minu=r.minu-m;
while(r.minu<0){
    r.minu=r.minu+60;
    r.hora=r.hora-1;
    if(r.hora<0){
        r.hora = 23;
    }
}
return r;
}

Reloj operator+(Reloj r1,Reloj r2){
Reloj r;
r=r1;
r += (r2.minu + (r2.hora *60));
return r;
}

Reloj operator-(Reloj r1,Reloj r2){
Reloj r;
r=r1;
r -= (r2.minu + (r2.hora *60));
return r;
}

bool Reloj::operator>(Reloj r){
int minu1,minu2;
minu1= hora*60 + minu;
minu2= r.hora*60 + r.minu;
return (minu1>minu2);
}

bool Reloj::operator<(Reloj r){
int minu1,minu2;
minu1= hora*60 + minu;
minu2= r.hora*60 + r.minu;
return (minu1<minu2);
}

bool Reloj::operator==(Reloj r){
int minu1,minu2;
minu1= hora*60 + minu;
minu2= r.hora*60 + r.minu;
return (minu1==minu2);
}

bool Reloj::operator<=(Reloj r){
int minu1,minu2;
minu1= hora*60 + minu;
minu2= r.hora*60 + r.minu;
return (minu1<=minu2);
}

bool Reloj::operator>=(Reloj r){
int minu1,minu2;
minu1= hora*60 + minu;
minu2= r.hora*60 + r.minu;
return (minu1>=minu2);
}




#endif /* Reloj_h */
