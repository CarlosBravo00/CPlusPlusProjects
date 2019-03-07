#ifndef reloj_h
#define reloj_h


class hora {
public:
    hora ();
  hora(int h,int m);
  int getHora();
  int getMin();
  void setHora(int h);
  void setMin(int m);
  void display();

  private:
  int hh, mm;
};

hora::hora(){
  hh=0;
  mm=0;
}

hora::hora(int h,int m){
  hh=h;
  mm=m;
}

int hora::getHora(){
  return hh;
}
int hora::getMin(){
  return mm;
}

void hora::setHora(int h){
  hh=h;
}

void hora::setMin(int m){
  mm=m;
}

void hora::display(){
  if (hh<10){
     cout <<"0"<< hh;
  }else {
    cout<<hh;
  }
  if (mm<10){
     cout<< ":0" << mm<<endl;
  }else {
    cout<< ":" << mm <<endl;
  }
}

#endif
