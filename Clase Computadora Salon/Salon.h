#ifndef SALON_H_INCLUDED
#define SALON_H_INCLUDED

class salon{
public:
salon();
salon(int s,computadora c);
int getNumSalon();
computadora getComputadora();
void setNumsalon(int num);
void setComputadora(computadora c);

private:
int numSalon;
computadora PC;


};

salon::salon(){
    PC.setMarca("");
    PC.setOS("");
    PC.setRam(0);
    numSalon=0;

}
salon::salon(int s,computadora c){
    PC=c;
    numSalon=s;
}

int salon::getNumSalon(){
    return numSalon;
}
computadora salon::getComputadora(){
    return PC;
}
void salon::setNumsalon(int num){
    numSalon=num;
}
void salon::setComputadora(computadora c){
    PC=c;
}

#endif // SALON_H_INCLUDED
