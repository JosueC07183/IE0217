#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
#include "funciones.hpp"
#include <cstring>
using namespace std;


/*bool validarEntrada(){
    cout<<"proceso";
}*/

vector<Empleado> leerArchivo(string Datos){
    cout<<"Información general de los empleados"<<endl;
    vector<Empleado> empleados;

    ifstream archivo("../../Datos.txt");
    if (!archivo) {
        cout << "Error al abrir el archivo." << endl;
        exit(1);
    }

    regex pattern("^(.*),(.*),(\\d+),(.*),(\\d+\\.?\\d*e?\\+?\\d*)$");
    string linea;
    while (getline(archivo, linea)) {
        smatch matches;
        if (regex_match(linea, matches, pattern)) {
            Empleado empleado;
            empleado.nombre = matches[1].str();
            empleado.email = matches[2].str();
            empleado.edad = stoi(matches[3].str());
            empleado.areaTrabajo = matches[4].str();
            empleado.salario = stod(matches[5].str());
            empleados.push_back(empleado);
        }
    }

    archivo.close();
    return empleados;
}

vector<Empleado> buscarPorDepartamento(const vector<Empleado>& empleados, const string& departamento) {
    vector<Empleado> resultado;
    for (const auto& empleado : empleados) {
        if (strcasecmp(empleado.areaTrabajo.c_str(), departamento.c_str())==0) {
            resultado.push_back(empleado);
        }
    }
    return resultado;
}

vector<Empleado> buscarPorSalario(const vector<Empleado>& empleados, int salarioMinimo, int salarioMaximo) {
    vector<Empleado> resultado;
    for (const auto& empleado : empleados) {
        if (empleado.salario >= salarioMinimo && empleado.salario <= salarioMaximo) {
            resultado.push_back(empleado);
        }
    }
    return resultado;
}
