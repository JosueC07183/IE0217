#include <iostream>
#include "campus.hpp"
using namespace std;

int main(){

    campus c1("Sede Rodrigo Facio", 4, "Finca Aire");
    campus c2("Sede Rodrigo Facio",4, "Finca Viento");
    campus c3("Sede Rodrigo Facio",4, "Finca Fuego");
    campus c4("Sede Rodrigo Facio",4, "Finca Agua");
    cout<<"Campus: "<<c1.getName_Sede()<<". Cantidad de fincas: "<<c1.getCantidad()<<endl;
    cout<<"Nombre de las fincas: "<<c1.getName()<<endl;
    cout<<"Nombre de las fincas: "<<c2.getName()<<endl;
    cout<<"Nombre de las fincas: "<<c3.getName()<<endl;
    cout<<"Nombre de las fincas: "<<c4.getName()<<endl;
    

    return 0;
}
