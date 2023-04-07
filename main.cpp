/*
* Función main. Aquí se llaman las funciones 
* creadas hasta el momento.
*/
#include <iostream>
#include "campus.hpp"
#include "finca.hpp"
#include "edificio.hpp"
#include "edificio_Aulas.hpp"
//#include "edificio_Parqueo.hpp"
using namespace std;

int main(){
    
    //bool bus_Service, *val_Service;// Variable para comprobar el transito del bus interno
    
    campus temp, temp2, temp3, temp4; // Variables para clase campus
    finca  aux, aux2, aux3, aux4; // Variables para clase finca
    //edificio build, build2;// Variables para clase edificio
// Variables para clase edificio_Parqueo heredada de clase edificio
    edificio_Parqueo Build, Build2; 

    
    

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

// Determinar si pasa bus interno por ciertas fincas.
// PREGUNTAR ESTO.
    /*if (temp.getName_Finca()=="Finca Aire")
    {
        bus_Service="Si";
        val_Service= &bus_Service;
    }
    else if (temp2.getName_Finca()=="Finca Viento")
    {
        bus_Service="Si";
        val_Service= &bus_Service;
    }
    else if (temp3.getName_Finca()=="Finca Fuego")
    {
        bus_Service="Si";
        val_Service= &bus_Service;
    }
    else if(temp4.getName_Finca()=="Finca Agua"){
        bus_Service="No";
        val_Service= &bus_Service;
    }
    else{
        return 0;
    }*/
    
//Info general de fincas:

    /*Info Finca Aire*/
    aux.setNum_Edificio(7);
    aux.setNum_Edificio_Park(2);
    aux.setNum_Edificio_Room(5);
    aux.setbus_Service(true);
    cout<<temp.getName_Finca() << " posee: "<<aux.getNum_Edificio()<< " edificios, "<<aux.getNum_Edificio_Park()<<
    " son de parqueo y "<<aux.getNum_Edificio_Room()<<" de aulas."<< " Pasa el bus interno? "<< aux.getbus_Service() <<endl;

    /*Info Finca Viento*/
    aux2.setNum_Edificio(4);
    aux2.setNum_Edificio_Park(1);
    aux2.setNum_Edificio_Room(3);
    aux2.setbus_Service(true);
    cout<< temp2.getName_Finca()<<" posee: "<<aux2.getNum_Edificio()<< " edificios, "<<aux2.getNum_Edificio_Park()<<
    " son de parqueo y "<<aux2.getNum_Edificio_Room()<<" de aulas."<< " Pasa el bus interno? "<< aux2.getbus_Service()<<endl;

    /*Info Finca Fuego*/
    aux3.setNum_Edificio(3);
    aux3.setNum_Edificio_Park(1);
    aux3.setNum_Edificio_Room(2);
    aux3.setbus_Service(true);
    cout<< temp3.getName_Finca() <<" posee: "<<aux3.getNum_Edificio()<< " edificios, "<<aux3.getNum_Edificio_Park()<<
    " son de parqueo y "<<aux3.getNum_Edificio_Room()<<" de aulas."<<" Pasa el bus interno? "<<aux3.getbus_Service()<<endl;

    /*Info Finca Agua*/
    aux4.setNum_Edificio(9);
    aux4.setNum_Edificio_Park(3);
    aux4.setNum_Edificio_Room(6);
    aux4.setbus_Service(false);
    cout<< temp4.getName_Finca()<<" posee: "<<aux4.getNum_Edificio()<< " edificios, "<<aux4.getNum_Edificio_Park()<<
    " son de parqueo y "<<aux4.getNum_Edificio_Room()<<" de aulas."<<" Pasa el bus interno? "<< aux4.getbus_Service() <<endl;

// Detalles de los edificios de parqueo
    /*Finca Aire: edificios parqueo*/
    /*Información primer edificio A.1*/
    //build.setPisos(4);
    //build.setAscensor(false);
    Build.setPisos(4);
    Build.setAscensor(false);
    Build.setUbicacion("Costado sureste edificio Ciencias Sociales.");
    Build.set_SodaDisponible("Como es un parqueo no tiene soda");
    cout<<"Edificio A1 posee: "<<Build.getPisos()<< " pisos. "<< "Tiene ascensor? "<<Build.getAscensor()
    <<". Esta ubicado en: "<<Build.getUbicacion()<< " Tiene soda ? "<< Build.get_SodaDisponible() <<endl;
    

    
    /*Información edificio A.2*/
    Build2.setPisos(6);
    Build2.setAscensor(true);
    Build2.setUbicacion("Diagonal Edificio CELEQ");
    Build2.set_SodaDisponible("Como es un parqueo no tiene soda");
    cout<<"Edificio A2 posee: "<<Build2.getPisos()<< " pisos. "<< "Tiene ascensor? "<<Build2.getAscensor()
    <<". Esta ubicado en: "<<Build2.getUbicacion()<< " Tiene soda ? "<< Build2.get_SodaDisponible() <<endl;
    return 0;
}
