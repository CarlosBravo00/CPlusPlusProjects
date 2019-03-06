#ifndef reloj_h
#define reloj_h


class reloj {
public:
  reloj();
  reloj(int h,int m);
  int getHora();
  int getMin();
  void setHora(int h);
  void setMin(int m);
  void display();

  private:
  int hora, min;
};

reloj::reloj(){
  hora=0;
  min=0;
}

reloj::reloj(int h,int m){
  hora=h;
  min=m;
}

int reloj::getHora(){
  return hora;
}
int reloj::getMin(){
  return min;
}

void reloj::setHora(int h){
  hora=h;
}

void reloj::setMin(int m){
  min=m;
}

void reloj::display(){
  if (hora<10){
     cout <<"0"<< hora;
  }else {
    cout<<hora;
  }
  if (min<10){
     cout<< ":0" << min <<endl;
  }else {
    cout<< ":" << min <<endl;
  }
}

#endif
