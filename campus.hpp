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
    campus(string name_Campus, int cantidad_Fincas, string name_Finca);
    ~campus();

    void setName_Sede(string name_Campus);
    string getName_Sede();

    void setCantidad(int cantidad_Fincas);
    int getCantidad();
    
    void setName_Finca(string name_Finca);
    string getName_Finca();

campus(){
    
}
};
