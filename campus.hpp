/*
* Aquí se hacen las declaraciones de las
* funciones.
*/
#include <string>
using namespace std;

class campus
{

private:
    string name_Campus;
    int cantidad_Fincas;
    string name_Finca;

public:
    campus(string name_Campus, int cantidad_Fincas, string name_Finca);
    ~campus();

    void setName_Sede(string name_Campus);
    string getName_Sede();

    void setCantidad(int cantidad_Fincas);
    int getCantidad();
    
    void setName_Finca(string name_Finca);
    string getName_Finca();

    string getName();
campus(){
    
}
};
