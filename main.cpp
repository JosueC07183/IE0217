/**
 * @file main.cpp
 * @author Josué Salmerón Córdoba 
 * @brief Esto es la primer tarea de IE0217.
 * @version 0.1
 * @date 2023-04-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/*
* Función main. Aquí se llaman las funciones 
* creadas hasta el momento.
*/

#include <iostream>
#include "campus.hpp"
#include "finca.hpp"
#include "edificio.hpp"

using namespace std;

int main(){
    
/**
 * @brief En este archivo se hace el llamado de todas las clases para instanciar sus atributos.
 * También se hizo uso de herencia para aprovechar los metodos de la clase edificio, por lo que
 * solo basta con incluir el archivo: edificio.hpp en el main y gracias a esto se pueden acceder
 * a todo lo que se creo en esta clase facilmente.
 * 
 */
    
    campus temp, temp2, temp3, temp4; // Variables para clase campus.
    finca  aux, aux2, aux3, aux4; // Variables para clase finca.
// Variables para clase edificio_Parqueo heredada de clase edificio.
    edificio_Parqueo Build, Build2;
// Variables para clase Aulas heredada de clase edificio.
    Aulas Build3, Build4, Build5, Build6, Build7; 

    
    

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
    
cout<<"Info general de fincas:"<<endl;

    cout<<"Info Finca Aire"<<endl;
    aux.setNum_Edificio(7);
    aux.setNum_Edificio_Park(2);
    aux.setNum_Edificio_Room(5);
    aux.setbus_Service(true);
    cout<<temp.getName_Finca() << " posee: "<<aux.getNum_Edificio()<< " edificios, "<<aux.getNum_Edificio_Park()<<
    " son de parqueo y "<<aux.getNum_Edificio_Room()<<" de aulas."<< " Pasa el bus interno? "<< aux.getbus_Service() <<endl;

    cout<<"Info Finca Viento"<<endl;
    aux2.setNum_Edificio(4);
    aux2.setNum_Edificio_Park(1);
    aux2.setNum_Edificio_Room(3);
    aux2.setbus_Service(true);
    cout<< temp2.getName_Finca()<<" posee: "<<aux2.getNum_Edificio()<< " edificios, "<<aux2.getNum_Edificio_Park()<<
    " son de parqueo y "<<aux2.getNum_Edificio_Room()<<" de aulas."<< " Pasa el bus interno? "<< aux2.getbus_Service()<<endl;

    cout<<"Info Finca Fuego"<<endl;
    aux3.setNum_Edificio(3);
    aux3.setNum_Edificio_Park(1);
    aux3.setNum_Edificio_Room(2);
    aux3.setbus_Service(true);
    cout<< temp3.getName_Finca() <<" posee: "<<aux3.getNum_Edificio()<< " edificios, "<<aux3.getNum_Edificio_Park()<<
    " son de parqueo y "<<aux3.getNum_Edificio_Room()<<" de aulas."<<" Pasa el bus interno? "<<aux3.getbus_Service()<<endl;

    cout<<"Info Finca Agua"<<endl;
    aux4.setNum_Edificio(9);
    aux4.setNum_Edificio_Park(3);
    aux4.setNum_Edificio_Room(6);
    aux4.setbus_Service(false);
    cout<< temp4.getName_Finca()<<" posee: "<<aux4.getNum_Edificio()<< " edificios, "<<aux4.getNum_Edificio_Park()<<
    " son de parqueo y "<<aux4.getNum_Edificio_Room()<<" de aulas."<<" Pasa el bus interno? "<< aux4.getbus_Service() <<endl;

cout<<"Detalles de los edificios de parqueo."<<endl;

cout<<"************Finca Aire: edificios parqueo************"<<endl;
    cout<<"*Información edificio A.1*"<<endl;
    Build.setPisos(4);
    Build.setAscensor(false);
    Build.setUbicacion("Costado sureste edificio Ciencias Sociales.");
    Build.set_SodaDisponible("Como es un parqueo no tiene soda");
    cout<<"Edificio A1 posee: "<<Build.getPisos()<< " pisos. "<< "Tiene ascensor? "<<Build.getAscensor()
    <<". Esta ubicado en: "<<Build.getUbicacion()<< " Tiene soda ? "<< Build.get_SodaDisponible() <<endl;
    
    cout<<"*Información edificio A.1*"<<endl;
    Build2.setPisos(6);
    Build2.setAscensor(true);
    Build2.setUbicacion("Diagonal Edificio CELEQ");
    Build2.set_SodaDisponible("Como es un parqueo no tiene soda");
    cout<<"Edificio A2 posee: "<<Build2.getPisos()<< " pisos. "<< "Tiene ascensor? "<<Build2.getAscensor()
    <<". Esta ubicado en: "<<Build2.getUbicacion()<< " Tiene soda ? "<< Build2.get_SodaDisponible() <<endl;
cout<<"************Finca Aire: edificios aula************"<<endl;
    cout<<"Información A.3"<<endl;
    Build3.setPisos(5);
    Build3.setAscensor("Si");
    Build3.setUbicacion("Costado oeste Laname");
    Build3.set_Cafeteria("Si");
    Build3.set_NumAula(30);
    Build3.set_Sillas(20);
    Build3.set_Proyector("Si");
    cout<<"Aquí la información del edificio A3."<<endl;
    cout<<"Edificio A3 posee: "<<Build3.getPisos()<< " pisos"<<endl;
    cout<<"Tiene ascensor ?: "<<Build3.getAscensor()<<endl;
    cout<<"Ubicación: "<<Build3.getUbicacion()<<endl;
    cout<<"Tiene cafetería ?: "<<Build3.get_Cafeteria()<<endl;
    cout<<"Tiene: "<<Build3.get_NumAula()<< " aulas" <<endl;
    cout<<"Cada aula tiene: "<<Build3.get_Sillas()<< " sillas" <<endl;
    cout<<"Y las aulas tienen proyector ?: "<<Build3.get_Proyector()<<endl;
    
    cout<<"Información A.4"<<endl;
    Build4.setPisos(3);
    Build4.setAscensor("No");
    Build4.setUbicacion("Frente a laboratorio de Docencia");
    Build4.set_Cafeteria("Si");
    Build4.set_NumAula(20);
    Build4.set_Sillas(20);
    Build4.set_Proyector("Si");
    cout<<"Aquí la información del edificio A4."<<endl;
    cout<<"Edificio A4 posee: "<<Build4.getPisos()<< " pisos"<<endl;
    cout<<"Tiene ascensor ?: "<<Build4.getAscensor()<<endl;
    cout<<"Ubicación: "<<Build4.getUbicacion()<<endl;
    cout<<"Tiene cafetería ?: "<<Build4.get_Cafeteria()<<endl;
    cout<<"Tiene: "<<Build4.get_NumAula()<< " aulas" <<endl;
    cout<<"Cada aula tiene: "<<Build4.get_Sillas()<< " sillas" <<endl;
    cout<<"Y las aulas tienen proyector ?: "<<Build4.get_Proyector()<<endl;
    
    cout<<"Información A.5"<<endl;
    Build5.setPisos(6);
    Build5.setAscensor("Si");
    Build5.setUbicacion("Frente al Planetario");
    Build5.set_Cafeteria("Si");
    Build5.set_NumAula(70);
    Build5.set_Sillas(20);
    Build5.set_Proyector("Si");
    cout<<"Aquí la información del edificio A5."<<endl;
    cout<<"Edificio A5 posee: "<<Build5.getPisos()<< " pisos"<<endl;
    cout<<"Tiene ascensor ?: "<<Build5.getAscensor()<<endl;
    cout<<"Ubicación: "<<Build5.getUbicacion()<<endl;
    cout<<"Tiene cafetería ?: "<<Build5.get_Cafeteria()<<endl;
    cout<<"Tiene: "<<Build5.get_NumAula()<< " aulas" <<endl;
    cout<<"Cada aula tiene: "<<Build5.get_Sillas()<< " sillas" <<endl;
    cout<<"Y las aulas tienen proyector ?: "<<Build5.get_Proyector()<<endl;

    cout<<"Información A.6"<<endl;
    Build6.setPisos(4);
    Build6.setAscensor("No");
    Build6.setUbicacion("100 mts norte del Planetario");
    Build6.set_Cafeteria("No");
    Build6.set_NumAula(20);
    Build6.set_Sillas(15);
    Build6.set_Proyector("Si");
    cout<<"Aquí la información del edificio A6."<<endl;
    cout<<"Edificio A6 posee: "<<Build6.getPisos()<< " pisos"<<endl;
    cout<<"Tiene ascensor ?: "<<Build6.getAscensor()<<endl;
    cout<<"Ubicación: "<<Build6.getUbicacion()<<endl;
    cout<<"Tiene cafetería ?: "<<Build6.get_Cafeteria()<<endl;
    cout<<"Tiene: "<<Build6.get_NumAula()<< " aulas" <<endl;
    cout<<"Cada aula tiene: "<<Build6.get_Sillas()<< " sillas" <<endl;
    cout<<"Y las aulas tienen proyector ?: "<<Build6.get_Proyector()<<endl;

    cout<<" ---------------------------"<<endl;
    cout<<"  Información edificio A.7  "<<endl;
    cout<<" ---------------------------"<<endl;
    Build7.setPisos(3);
    Build7.setAscensor("No");
    Build7.setUbicacion("Frente al edificio de Ingeniería");
    Build7.set_Cafeteria("Si");
    Build7.set_NumAula(25);
    Build7.set_Sillas(18);
    Build7.set_Proyector("Si");
    cout<<"Edificio A7 posee: "<<Build7.getPisos()<< " pisos"<<endl;
    cout<<"Tiene ascensor ?: "<<Build7.getAscensor()<<endl;
    cout<<"Ubicación: "<<Build7.getUbicacion()<<endl;
    cout<<"Tiene cafetería ?: "<<Build7.get_Cafeteria()<<endl;
    cout<<"Tiene: "<<Build7.get_NumAula()<< " aulas" <<endl;
    cout<<"Cada aula tiene: "<<Build7.get_Sillas()<< " sillas" <<endl;
    cout<<"Y las aulas tienen proyector ?: "<<Build7.get_Proyector()<<endl;
    /* Información de un aula en específico */
    Build7.set_EnumAula("IE 303");
    Build7.setCantPizarra(2);
    Build7.setLocation("la Finca Aire, en el tercer piso");
    cout<<"***********************************"<<endl;
    cout<<" Información aula del curso IE0217 "<<endl;
    cout<<"***********************************"<<endl;
    cout<< "El aula "<< Build7.get_EnumAula() << " se encuentra en " 
    << Build7.getLocation()<< " posee " << Build7.getCantPizarra()<< " pizarras y "
    << Build7.get_Proyector()<< " tiene proyector, además el edificio "<<Build7.get_Cafeteria()
    << " cuenta con cafetería"<<endl;


    return 0;
}
