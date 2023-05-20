/**
 * @file funciones.hpp
 * @author Josue Salmeron Cordoba
 * @brief En este archivo se muestran los prototipos de las funciones.
 * @version 0.1
 * @date 2023-05-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief Se crea una estructura que contiene varias variables.
 * @param nombre: nombre del empleado
 * @param email: correo del empleado
 * @param edad: variable entera que muestra la edad del empleado
 * @param areaTrabajo: puesto de trabajo del empleado
 * @param salario: cantidad de dinero que gana el empleado
 */

struct Empleado {
    string nombre;
    string email;
    int edad;
    string areaTrabajo;
    double salario;
};

/**
 * @brief Aquí se muestran los prototipos de las funciones con sus respectivos argumentos. Cada función retornará un vector con 
 * la información que se solicita para cada caso.
 * @return vector<Empleado> 
 */

vector<Empleado> leerArchivo(string Datos);
vector<Empleado> buscarPorDepartamento(const vector<Empleado>& empleados, const string& departamento);
vector<Empleado> buscarPorSalario(const vector<Empleado>& empleados, int salarioMinimo, int salarioMaximo);
