/*
* Función main. Aquí se llaman las funciones 
* creadas hasta el momento.
*/
#include <iostream>
#include "campus.hpp"
#include "finca.hpp"
using namespace std;

int main(){

    campus temp, temp2, temp3, temp4;
    finca  aux, aux2, aux3, aux4;

// Info general:
    temp.setCantidad(4);
    temp.setName_Sede("Sede Rodrigo Facio");
    temp.setName_Finca("Finca Aire");
    temp2.setName_Finca("Finca Viento");
    temp3.setName_Finca("Finca Fuego");
    temp4.setName_Finca("Finca Agua");
    cout<<"Campus: "<< temp.getName_Sede() <<". Cantidad de fincas: "<< temp.getCantidad() << "\n"<<
    "Nombre de las fincas: "<<"\n"<<temp.getName_Finca() <<"\n"<<temp2.getName_Finca()<<"\n"<<temp3.getName_Finca()<<"\n"<<temp4.getName_Finca()<<endl;
    cout<<"\n";


//Info general de fincas:

    /*Info Finca Aire*/
    aux.setNum_Edificio(7);
    aux.setNum_Edificio_Park(2);
    aux.setNum_Edificio_Room(5);
    cout<<temp.getName_Finca() << " posee: "<<aux.getNum_Edificio()<< " edificios, "<<aux.getNum_Edificio_Park()<<
    " son de parqueo y "<<aux.getNum_Edificio_Room()<<" de aulas."<<endl;

    /*Info Finca Viento*/
    aux2.setNum_Edificio(4);
    aux2.setNum_Edificio_Park(1);
    aux2.setNum_Edificio_Room(3);
    cout<< temp2.getName_Finca()<<" posee: "<<aux2.getNum_Edificio()<< " edificios, "<<aux2.getNum_Edificio_Park()<<
    " son de parqueo y "<<aux2.getNum_Edificio_Room()<<" de aulas."<<endl;

    /*Info Finca Fuego*/
    aux3.setNum_Edificio(3);
    aux3.setNum_Edificio_Park(1);
    aux3.setNum_Edificio_Room(2);
    cout<< temp3.getName_Finca() <<" posee: "<<aux3.getNum_Edificio()<< " edificios, "<<aux3.getNum_Edificio_Park()<<
    " son de parqueo y "<<aux3.getNum_Edificio_Room()<<" de aulas."<<endl;

    /*Info Finca Agua*/
    aux4.setNum_Edificio(9);
    aux4.setNum_Edificio_Park(3);
    aux4.setNum_Edificio_Room(6);
    cout<< temp4.getName_Finca()<<" posee: "<<aux4.getNum_Edificio()<< " edificios, "<<aux4.getNum_Edificio_Park()<<
    " son de parqueo y "<<aux4.getNum_Edificio_Room()<<" de aulas."<<endl;


    return 0;
}
