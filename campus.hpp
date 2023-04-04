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
    string getName_Sede();
    int getCantidad();
    void setCantidad(int cantidad_Fincas);
    string getName();
};
