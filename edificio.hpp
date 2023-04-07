#include <iostream>
using namespace std;

class edificio
{
private:
    /* data */
    
public:
    int pisos;
    bool ascensor;
    string ubicacion;
    
    edificio(int pisos, bool ascensor, string ubicacion);
    ~edificio();

    edificio(){

}

    void setPisos(int pisos);
    int getPisos();

    void setAscensor(bool ascensor);
    bool getAscensor();

    void setUbicacion(string ubicacion);
    string getUbicacion();
};


/*
* Herencia edificio a edificio_Parqueo.
* Aquí se hará uso de todos los métodos de-
* la clase padre: edificio, es decir bastará
* con instanciarlos en el main para usarlos.
*/

class edificio_Parqueo : public edificio{
public: // Métodos
    string Soda; // Variable tipo string
    //edificio_Parqueo(string); // Constructor
    void set_SodaDisponible(string Soda);
    string get_SodaDisponible();

};
