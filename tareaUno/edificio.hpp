/**
 * @file edificio.hpp
 * @author Josue Salmeron Cordoba
 * @brief Clase padre donde existen otras clases que heredan los metodos y atributos de ella.
 * @version 0.1
 * @date 2023-04-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
using namespace std;
/// @brief Esta es la clase padre de las clases: edificio_Parqueo y Aulas.

class edificio
{

public:

    int pisos;
    bool ascensor;
    string ubicacion;
    
    edificio(int pisos, bool ascensor, string ubicacion); 
    ~edificio(); 

    edificio(){

}
/**
 * @brief Set the Pisos object
 * 
 * @param pisos: cantidad de pisos en un edificio
 * @param ascensor: variable booleana que indica si en un edificio hay o no ascensor
 * @param Ubicacion : lugar donde estan construidos los edificios 
 */
    void setPisos(int pisos);
    int getPisos();

    void setAscensor(bool ascensor);
    bool getAscensor();

    void setUbicacion(string ubicacion);
    string getUbicacion();
};


/** @brief Herencia edificio a edificio_Parqueo. Bastará con instanciarlos desde el main.
* @param Soda: string que indica si existe o no soda en un edificio
*/
class edificio_Parqueo : public edificio{
public:
    string Soda; 
    void set_SodaDisponible(string Soda);
    string get_SodaDisponible();

};


/**
 * @brief Se crea la clase Aulas y se aprovecha la clase padre: edificio para hacer uso  de algunos métodos.
 * @param sillas: cantidad de sillas en cada aula.
 * @param proyector: indica si hay o no proyector en el aula
 * @param cafeteria: indica si el edificio cuenta con cafeteria
 * @param num_Aula: cantidad de aulas en un edificio
 * @param enum_Aula: numeracion del aula y no perderse
 * @param cant_Pizarra: numero de pizarras en un aula
 * @param Location: ubicacion especifica de un aula
 */
class Aulas : public edificio{
    public:

        int sillas;
        string proyector;
        string cafeteria;
        int num_Aula;
        string enum_Aula;
        int cant_Pizarra;
        string Location;

        void set_Sillas(int sillas); 
        int get_Sillas(); 

        void set_Proyector(string proyector);
        string get_Proyector();

        void set_Cafeteria(string cafeteria);
        string get_Cafeteria();
        
        void set_NumAula(int num_Aula);
        int get_NumAula();

        void set_EnumAula(string enum_Aula);
        string get_EnumAula();

        void setCantPizarra(int cant_Pizarra);
        int getCantPizarra();

        void setLocation(string Location);
        string getLocation();

};