#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED



class Empleado{
 public:
     Empleado();
    ~Empleado();

    Empleado(int Id,double SF,double SH,int Hrs);
    void  setIdEmpleado(int Id);
    int getIdEmpleado();

    void setSueldoFijo(double SF);
    double getSueldoFijo();

    void  setSueldoHora(double SH);
    double getSueldoHora();

    void setHorasTrabajo(int Hrs);
    int getHorasTrabajo();

    void RegistrarHoras(int THrs);
    double CalcularPago();

 private:
    int idEmpleado;
    double SueldoFijo;
    double SueldoHora;
    int HorasTrabajo;
 };

 Empleado::Empleado(){
 idEmpleado=0;
 SueldoFijo=0;
 SueldoHora=0;
 HorasTrabajo=0;
 }

 Empleado::~Empleado(){
 }

 Empleado::Empleado(int Id,double SF,double SH,int Hrs){
 idEmpleado=Id;
 SueldoFijo=SF;
 SueldoHora=SH;
 HorasTrabajo=Hrs;
 }

 void Empleado::setIdEmpleado(int id){
    idEmpleado=id;
 }

 int Empleado::getIdEmpleado(){
    return idEmpleado;
 }

 void Empleado::setSueldoFijo(double SF){
     SueldoFijo=SF;
 }

 double Empleado::getSueldoFijo(){
    return SueldoFijo;
 }

 void Empleado::setSueldoHora(double SH){
    SueldoHora=SH;
 }

 double Empleado::getSueldoHora(){
    return SueldoHora;
 }

 void Empleado::setHorasTrabajo(int Hrs){
    HorasTrabajo=Hrs;
 }

 int Empleado::getHorasTrabajo(){
    return HorasTrabajo;
 }

 void Empleado::RegistrarHoras(int THrs){
 HorasTrabajo=HorasTrabajo+THrs;
 }

 double Empleado::CalcularPago(){
 double saldo;
    saldo=SueldoFijo+(HorasTrabajo*SueldoHora);

 return saldo;
 }


#endif // EMPLEADO_H_INCLUDED
