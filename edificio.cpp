#include <iostream>
using namespace std;
#include "edificio.hpp"

///@brief Constructor de la clase padre.
/// @param pisos 
/// @param ascensor 
/// @param ubicacion 
edificio::edificio(int pisos, bool ascensor, string ubicacion){
    this->pisos=pisos; /// variable pisos cae sobre lo que hay en el constructor
    this->ascensor=ascensor; /// variable ascensor cae sobre lo que hay 
    this-> ubicacion=ubicacion; ///variable ubicacion cae sobre lo que hay en el constructor
}
/// @brief Metodo setPisos que recibe el numero de pisos
/// @param pisos
void edificio::setPisos(int pisos){
    this->pisos=pisos;
}
/// @brief Metodo getPisos que retorna la cantidad de pisos
/// @return pisos 
int edificio::getPisos(){
    return pisos;
}
/// @brief Metodo setAscensor que recibe un parametro booleano
/// @param ascensor
void edificio::setAscensor(bool ascensor){
    this->ascensor=ascensor;
}
/// @brief Metodo getAscensor que muestra si el edificio tiene o no ascensor
/// @return ascensor 
bool edificio::getAscensor(){
    return ascensor;
}
/// @brief Metodo setUbicacion donde se indica la ubicacion de un edificio
/// @param ubicacion
void edificio::setUbicacion(string ubicacion){
    this-> ubicacion=ubicacion;
}
/// @brief Metodo getUbicacion muestra la ubicacion del edificio
/// @return ubicacion 
string edificio::getUbicacion(){
    return ubicacion;
}

/// @brief Constructor de la clase que hereda los métodos de la clase padre.
/// @param Soda 
void edificio_Parqueo::set_SodaDisponible(string Soda){
    this->Soda=Soda; /// Variable Soda cae sobre lo que hay en el constructor

}
/// @brief Metodo get_SodaDisponible donde se muestra si hay o no soda
/// @return Soda
string edificio_Parqueo::get_SodaDisponible(){
    return Soda;
}

/// @brief Metodo set_Sillas donde se escribe la cantidad de sillas
/// @param sillas 
void Aulas::set_Sillas(int sillas){
    this->sillas=sillas; /// Variable sillas cae sobre lo que hay en el constructor
}
/// @brief Metodo get_Sillas que muestra el numero de sillas
/// @return sillas
int Aulas::get_Sillas(){
    return sillas;
}
/// @brief Metodo set_Proyector donde se escribe si hay o no proyector
/// @param proyector 
void Aulas::set_Proyector(string proyector){
    this->proyector=proyector; /// Variable proyector cae sobre lo que hay en el constructor

}
/// @brief Metodo get_Proyector que muestra la disponibilidad del proyector
/// @return proyector 
string Aulas::get_Proyector(){
    return proyector;
}
/// @brief Metodo set_Cafeteria que recibe como parametro un string
/// @param cafeteria
void Aulas::set_Cafeteria(string cafeteria){
    this->cafeteria=cafeteria; /// Variable cafeteria cae sobre lo que hay en el constructor
}
/// @brief Metodo get_Cafeteria que muestra la disponibilidad de la cafeteria
/// @return cafeteria
string Aulas::get_Cafeteria(){
    return cafeteria;
}
/// @brief Metodo set_NumAula que recibe como parametro un int
/// @param num_Aula 
void Aulas::set_NumAula(int num_Aula){
    this->num_Aula=num_Aula; /// Variable num_Aula cae sobre lo que hay en el constructor
}
/// @brief Metodo get_NumAula muestra la cantidad de aulas
/// @return num_Aula 
int Aulas::get_NumAula(){
    return num_Aula;
}
/// @brief Metodo set_EnumAula que recibe como parametro un string
/// @param enum_Aula
void Aulas::set_EnumAula(string enum_Aula){
    this->enum_Aula=enum_Aula; /// Variable enum_Aula cae sobre lo que hay en el constructor
}
/// @brief Metodo get_EnumAula muestra la enumeracion de un aula
/// @return enum_Aula 
string Aulas::get_EnumAula(){
    return enum_Aula;
}
/// @brief Metodo setCantPizarra que recibe como parametro un int 
/// @param cant_Pizarra 
void Aulas::setCantPizarra(int cant_Pizarra){
    this->cant_Pizarra=cant_Pizarra; /// Esta variable cae sobre lo que en el constructor
}
/// @brief Metodo getCantPizarra que muestra la cantidad de pizarras
/// @return cant_Pizarra
int Aulas::getCantPizarra(){
    return cant_Pizarra;
}
/// @brief Metodo setLocation que recibe como parametro un string
/// @param Location
void Aulas::setLocation(string Location){
    this-> Location = Location; /// variable Location cae sobre lo que hay en el constructor
}
/// @brief Metodo getLocation muestra la ubicacion de un aula
/// @return Location
string Aulas::getLocation(){
    return Location;
}
/// @brief Destructor
edificio::~edificio()
{
}
