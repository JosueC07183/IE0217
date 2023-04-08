/**
 * @file campus.cpp
 * @author Josue Salmeron Cordoba
 * @brief En este archivo se realizan los constructores de las declaraciones del archivo campus.hpp
 * @version 0.1
 * @date 2023-04-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/*
* Se construyen las funciones.
*/
#include "campus.hpp"
using namespace std;

/// @brief En este archivo se realizan los constructores de las declaraciones del archivo campus.hpp

campus::campus(string name_Campus, int cantidad_Fincas, string name_Finca){
    this -> name_Campus = name_Campus; /// La variable name_Campus le cae a lo que hay en el constructor.
    this->cantidad_Fincas=cantidad_Fincas; /// La variable cantidad_Fincas le cae  a lo que hay en el constructor.
    this->name_Finca=name_Finca; /// La variable name_Finca cae en lo que hay en el constructor.
    
}
/// @brief De la clase campus hay un metodo setName_Sede que recibe como parametro un string. 

void campus::setName_Sede(string name_Campus){
    this->name_Campus = name_Campus; /// La variable name_Campus le cae a lo que hay en el constructor.
}
/// @brief Metodo getName_Sede que retorna el nombre del campus.
/// @return name_Campus
string campus::getName_Sede(){
    return name_Campus;
}
/// @brief Metodo setCantidad que recibe como parametro la cantidad de fincas.
void campus::setCantidad(int cantidad_Fincas){
    this->cantidad_Fincas=cantidad_Fincas; /// La variable cantidad_Fincas le cae  a lo que hay en el constructor.

}
/// @brief Metodo getCantidad que retorna la cantidad de fincas.
/// @return cantidad_Fincas
int campus::getCantidad(){
    return cantidad_Fincas;
}
/// @brief Metodo setName_Finca que recibe como parametro un string
void campus::setName_Finca(string name_Finca){
    this->name_Finca = name_Finca; /// La variable name_Finca cae en lo que hay en el constructor.
}
/// @brief Metdo getName_Finca que retorna el nombre de la finca.
/// @return name_Finca 
string campus::getName_Finca(){
    return name_Finca;
}
/// @brief Destructor
campus::~campus(){

}