#include <iostream>
using namespace std;
#include "Empleado.hpp"

Empleado::Empleado(string nombre,string correo, int edad, string departamento, double salario){
    this->nombre=nombre;
    this->correo=correo;
    this->edad=edad;
    this->departamento=departamento;
    this->salario=salario;
}
void Empleado::setNombre(string nombre){
    this->nombre=nombre;
}

string Empleado::getNombre(){
    return nombre;
}

void Empleado::setCorreo(string correo){
    this->correo=correo;
}
string Empleado::getCorreo(){
    return correo;
}

void Empleado::setEdad(int edad){
    this->edad=edad;
}
int Empleado::getEdad(){
    return edad;
}

void Empleado:: setDepartamento(string departamento){
    this->departamento=departamento;
}

string Empleado::getDepartamento(){
    return departamento;
}

void Empleado::setSalario(double salario){
    this->salario=salario;
}
double Empleado::getSalario(){
    return salario;
}




/// @brief Destructor
Empleado::~Empleado(){
}