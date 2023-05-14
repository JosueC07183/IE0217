#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include "Empleado.hpp"
#include <regex>
using namespace std;

int main () {

    string datos;
    Empleado aux, aux2, aux3;
    ofstream Registros;
    Registros.open("Registros.txt", ios::out); // Abriendo archivo
    if (Registros.fail()){
        cout<<"Archivo dañado";
        exit(1);
    }
// Primer persona
    aux.setNombre("Yahir");
    aux.setCorreo("yahir.salmeron@gnu.ac.cr");
    aux.setEdad(18);
    aux.setDepartamento("Finanzas");
    aux.setSalario(1500000);
//Segunda persona
    aux2.setNombre("Noemy");
    aux2.setCorreo("noemy.salmeron@gnu.ac.cr");
    aux2.setEdad(28);
    aux2.setDepartamento("IT");
    aux2.setSalario(1600000);
//Tercer persona
    aux3.setNombre("Lorena");
    aux3.setCorreo("lorena.cordoba@gnu.ac.cr");
    aux3.setEdad(50);
    aux3.setDepartamento("Salud");
    aux3.setSalario(2600000);

    Registros << aux.getNombre()<<","<<aux.getCorreo()<<","<<aux.getEdad()<<","<<aux.getDepartamento()<<","<<aux.getSalario()<<endl;
    Registros << aux2.getNombre()<<","<<aux2.getCorreo()<<","<<aux2.getEdad()<<","<<aux2.getDepartamento()<<","<<aux2.getSalario()<<endl;
    Registros << aux3.getNombre()<<","<<aux3.getCorreo()<<","<<aux3.getEdad()<<","<<aux3.getDepartamento()<<","<<aux3.getSalario()<<endl;
    
    Registros.close();

}