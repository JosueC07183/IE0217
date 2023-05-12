/**
 * @file finca.cpp
 * @author Josue Salmeron Cordoba
 * @brief Aqui se realizan los constructores de la clase finca
 * @version 0.1
 * @date 2023-04-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
using namespace std;
#include "finca.hpp"

/// @brief Realizan los constructores de la clase finca

finca::finca(int num_Edificios, int edificio_Park, int edificio_Room,bool bus_Service){
    this-> num_Edificios=num_Edificios; // Esta variable: num_Edificios, cae sobre lo que hay en el constructor
    this->edificio_Park=edificio_Park; // Esta variable: edificio_Park, cae sobre lo que hay en el constructor
    this->edificio_Room=edificio_Room; // Esta variable: edificio_Room, cae sobre lo que hay en el constructor
    this->bus_Service=bus_Service; // Esta variable: bus_Service, cae sobre lo que hay en el constructor
}
/// @brief Metodo setNum_Edificio que recibe como para la cantidad de edificios 
/// @param num_Edificios 
void finca::setNum_Edificio(int num_Edificios){
     this-> num_Edificios=num_Edificios;
}
/// @brief Metodo getNum_Edificio que retorna el numero de edificios.
/// @return num_Edificios 
int finca::getNum_Edificio(){
    return num_Edificios;
}
/// @brief Metodo setNum_Edificio_Park que recibe como parametro la cantidad de edificios como parqueo en la finca
/// @param edificio_Park
void finca::setNum_Edificio_Park(int edificio_Park){
     this-> edificio_Park=edificio_Park;
}
/// @brief Metodo getNum_Edificio_Park que retorna la cantidad de parqueos tipo edificio en la finca
/// @return edificio_Park 
int finca::getNum_Edificio_Park(){
    return edificio_Park;
}
/// @brief Metodo setNum_Edificio_Room donde se establece la cantidad de edificios tipo aula en la finca.
/// @param edificio_Room
void finca::setNum_Edificio_Room(int edificio_Room){
     this-> edificio_Room=edificio_Room;
}
/// @brief Metodo getNum_Edificio_Room que retorna el numero de edificios tipo aula
/// @return edificio_Room 
int finca::getNum_Edificio_Room(){
    return edificio_Room;
}
/// @brief Metodo setbus_Service que recibe un parametro booleano
/// @param bus_Service
void finca::setbus_Service(bool bus_Service){
     this->bus_Service=bus_Service;
}
/// @brief Metodo getbus_Service que indica si el bus interno pasa por una finca o no.
/// @return bus_Service 
bool finca::getbus_Service(){
    return bus_Service;
}

/// @brief Destructor
finca::~finca(){
    
};