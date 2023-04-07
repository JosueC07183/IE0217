
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


/*
* Se crea la clase Aulas y se aprovecha
* la clase padre: edificio para hacer uso
* de algunos métodos.
*/
class Aulas : public edificio{
    public:
        int sillas;
        string proyector;
        string cafeteria;
        int num_Aula;
        void set_Sillas(int sillas);
        int get_Sillas();
        void set_Proyector(string proyector);
        string get_Proyector();
        void set_Cafeteria(string cafeteria);
        string get_Cafeteria();
        void set_NumAula(int num_Aula);
        int get_NumAula();

};