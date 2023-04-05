/*
* Función main. Aquí se llaman las funciones 
* creadas hasta el momento.
*/
#include <iostream>
#include "campus.hpp"
using namespace std;

int main(){

    campus temp, temp2, temp3, temp4;

    temp.setCantidad(4);
    temp.setName_Sede("Sede Rodrigo Facio");
    temp.setName_Finca("Finca Aire");
    temp2.setName_Finca("Finca Viento");
    temp3.setName_Finca("Finca Fuego");
    temp4.setName_Finca("Finca Agua");
    cout<<"Campus: "<< temp.getName_Sede() <<". Cantidad de fincas: "<< temp.getCantidad() << "\n"<<
    "Nombre de las fincas: "<<"\n"<<temp.getName_Finca() <<"\n"<<temp2.getName_Finca()<<"\n"<<temp3.getName_Finca()<<"\n"<<temp4.getName_Finca()<<endl;


    return 0;
}
