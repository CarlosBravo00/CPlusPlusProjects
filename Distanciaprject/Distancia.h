#ifndef DISTANCIA_H_INCLUDED
#define DISTANCIA_H_INCLUDED

class Distancia {
public:
    Distancia();
    Distancia(int pi, int pu);
    void setPies(int pi);
    void setPulgadas(int pu);
    int getPies();
    int getPulgadas();
    double convierteAMts();
    Distancia sumaDistancia(Distancia d);
    Distancia restaDistancia (Distancia d);
private:
    int pies;
    int pulgadas;
    void conviertePulgadas();

};

Distancia::Distancia() {
pies=0;
pulgadas=0;
}

Distancia::Distancia(int pi,int pu){
pies= pi;
pulgadas= pu;
conviertePulgadas();
}

void  Distancia::conviertePulgadas(){
    if (pulgadas>=12){
        int pulgadasEnPies = pulgadas / 12;
        pulgadas= pulgadas%12;
        pies = pies + pulgadasEnPies;
    } else {
      while (pulgadas < 0){
        pies = pies-1;
        pulgadas = pulgadas + 12;
            }
    }
}

void Distancia::setPies(int pi){
pies=pi;
}

void Distancia::setPulgadas(int pu){
pulgadas= pu;
conviertePulgadas();
}

int Distancia::getPies(){
return pies;
}

int Distancia::getPulgadas(){
return pulgadas;
}

Distancia Distancia::sumaDistancia(Distancia d){
    Distancia nd(d.getPies()+pies,d.getPulgadas()+pulgadas);
    return nd;
}

Distancia Distancia::restaDistancia(Distancia d){
    Distancia nd(pies -  d.getPies(),pulgadas - d.getPulgadas());
    return nd;
}

double Distancia::convierteAMts(){
    double metros;
    metros = ((pies * 12 + pulgadas) * 2.54 )/100;
    return metros;
}

#endif // DISTANCIA_H_INCLUDED
