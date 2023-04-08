/**
 * @file campus.hpp
 * @author JSC
 * @brief Esta clase tiene la info general de la universidad; nombre del campus, cantidad de fincas y sus nombres.
 * @version 0.1
 * @date 2023-04-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <string>
using namespace std;
/// @brief Definicion de metodos, atributos de esta clase.
class campus
{

private:
    string name_Campus;
    int cantidad_Fincas;
    string name_Finca;

public:
/**
 * @brief Construccion de los objetos de la clase campus.
 * 
 * @param name_Campus: nombre campus.
 * @param cantidad_Fincas: variable entera cantidad de fincas.
 * @param name_Finca: nombre de la finca
 */
    campus(string name_Campus, int cantidad_Fincas, string name_Finca);/// Constructor.
    ~campus(); /// Destructor.

    void setName_Sede(string name_Campus); /// Metodo set para nombre del campus.
    string getName_Sede(); ///Metodo get que muestra el nombre del campus.

    void setCantidad(int cantidad_Fincas); /// Metodo set para cantidad de fincas.
    int getCantidad(); ///Metodo get que muestra la cantidad de fincas.
    
    void setName_Finca(string name_Finca); ///Metodo set para nombre de cada finca
    string getName_Finca(); ///Metodo get que muestra el nombre de las fincas.

campus(){
    
}
};
