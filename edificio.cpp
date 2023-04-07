#include <iostream>
using namespace std;
#include "edificio.hpp"


//Constructor de la clase padre.
edificio::edificio(int pisos, bool ascensor, string ubicacion){
    this->pisos=pisos;
    this->ascensor=ascensor;
    this-> ubicacion=ubicacion;
}

void edificio::setPisos(int pisos){
    this->pisos=pisos;
}
int edificio::getPisos(){
    return pisos;
}

void edificio::setAscensor(bool ascensor){
    this->ascensor=ascensor;
}
bool edificio::getAscensor(){
    return ascensor;
}

void edificio::setUbicacion(string ubicacion){
    this-> ubicacion=ubicacion;
}
string edificio::getUbicacion(){
    return ubicacion;
}

// Constructor de la clase que hereda los métodos de la clase padre.
void edificio_Parqueo::set_SodaDisponible(string Soda){
    this->Soda=Soda;

}
string edificio_Parqueo::get_SodaDisponible(){
    return Soda;
}
edificio::~edificio()
{
}
