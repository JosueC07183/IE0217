/**
 * @file funciones.cpp
 * @author Josue Salmeron Cordoba
 * @brief 
 * @version 0.1
 * @date 2023-05-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
#include "funciones.hpp"
#include <cstring>
using namespace std;


vector<Empleado> leerArchivo(string Datos){
cout<<"Información general de los empleados"<<endl;
    vector<Empleado> empleados;

    fstream registros;
    registros.open(Datos.c_str(), ios::in);
    if (!registros){
        cout << "El archivo no existe" << endl;
        return empleados; // Devuelve un vector vacío si el archivo no existe
    }

    regex pattern("^(.*),(.*),(\\d+),(.*),(\\d+\\.?\\d*e?\\+?\\d*)$");
    string linea;
    while (getline(registros, linea)) {
        smatch matches;
        if (regex_match(linea, matches, pattern)) {
            Empleado empleado;
            empleado.nombre = matches[1].str();
            empleado.correo = matches[2].str();
            empleado.edad = stoi(matches[3].str());
            empleado.areaTrabajo = matches[4].str();
            empleado.salario = stod(matches[5].str());
            empleados.push_back(empleado);
        }
    }

    registros.close();
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
