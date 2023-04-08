/**
 * @file finca.hpp
 * @author Josue Salmeron Cordobba
 * @brief Aca se encontraran las principales caracteristicas de las fincas.
 * @version 0.1
 * @date 2023-04-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
using namespace std;
/// @brief Muestra las principales caracteristicas de las fincas: numero de edificios (parqueo y aulas) y disponibilidad del servicio de bus.
class finca
{
public:
    int num_Edificios;
    int edificio_Park;
    int edificio_Room;
    bool bus_Service;
/**
 * @brief Construccion de los objetos para la clase finca.
 * 
 * @param num_Edificios: cantidad de edificios general
 * @param edificio_Park: cantidad de edificios parqueo
 * @param edificio_Room: cantidad de edificios aulas
 * @param bus_Service: variable que determina si pasa o no el bus interno
 */
    finca(int num_Edificios, int edificio_Park, int edificio_Room, bool bus_Service); /// Constructor
    ~finca(); /// Destructor

    finca(){
    
    }

    void setNum_Edificio(int num_Edificios); /// Metodo setter que establece la cantidad de edificios
    int getNum_Edificio(); /// Metodo getter que muestra la cantidad de edificios

    void setNum_Edificio_Park(int edificio_Park); /// Metodo setter que establece los edificios de parqueo
    int getNum_Edificio_Park(); /// Metodo getter que muestra la cantidad de edificios de parqueo

    void setNum_Edificio_Room(int edificio_Room); /// Metodo setter que establece la cantidad de edificios aulas
    int getNum_Edificio_Room(); /// Metodo getter que muestra la cantidad de edificios aula

    void setbus_Service(bool bus_Service); /// Metodo setter que da un valor booleano al servicio del bus interno
    bool getbus_Service(); /// Metodo getter que muestra si pasa o no el bus interno.
};