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

string campus::getName_Sede(){
    return name_Campus;
}

int campus::getCantidad(){
    return cantidad_Fincas;
}

void campus::setCantidad(int cantidad_Fincas){
    this->cantidad_Fincas=cantidad_Fincas;

}

string campus::getName(){
    return name_Finca;
}

campus::~campus(){

}