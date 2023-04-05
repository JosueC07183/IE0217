/*
* Se construyen las funciones.
*/
#include "campus.hpp"
using namespace std;


campus::campus(string name_Campus, int cantidad_Fincas, string name_Finca){
    this -> name_Campus = name_Campus;
    this->cantidad_Fincas=cantidad_Fincas;
    this->name_Finca=name_Finca;
    
}

void campus::setName_Sede(string name_Campus){
    this->name_Campus = name_Campus;
}

string campus::getName_Sede(){
    return name_Campus;
}

void campus::setCantidad(int cantidad_Fincas){
    this->cantidad_Fincas=cantidad_Fincas;

}

int campus::getCantidad(){
    return cantidad_Fincas;
}

void campus::setName_Finca(string name_Finca){
    this->name_Finca = name_Finca;
}

string campus::getName_Finca(){
    return name_Finca;
}

string campus::getName(){
    return name_Finca;
}

campus::~campus(){

}