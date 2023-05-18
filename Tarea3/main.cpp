/**
 * @file main.cpp
 * @author Josue Salmeron Cordoba
 * @brief 
 * @version 0.1
 * @date 2023-05-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <vector>
#include "funciones.hpp"
using namespace std;

int main() {
//Primer se muestra el menu.
    vector<Empleado> empleados;
    string adrArchivo; // Variable de dirección del archivo.
    cout << "Ingrese la ruta completa del archivo: ";
    cin >>adrArchivo;
    fstream registros; // variable que contendrá la info de los empleados.
    registros.open(adrArchivo.c_str(), ios::in);
    if (!registros){
        cout<<"El archivo no existe";
        exit(1);
    }
     regex pattern("^(.*),(.*),(\\d+),(.*),(\\d+\\.?\\d*e?\\+?\\d*)$"); // Esta expresión regular permite analizar todos los posibles caracteres en un archivo.
                string linea;
                while (getline(registros, linea)) {
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

                registros.close();
    int opcion;
    bool salir = true;
    regex opcionRegex("[0-4]"); //Expresión regular que filtra números del 0 al 3.
    
    do {
        
        cout << "----- Menú -----" << endl;
        cout << "1. Validar entrada" << endl;
        cout << "2. Leer archivo" << endl;
        cout << "3. Buscar por departamento" << endl;
        cout << "4. Buscar por salario" << endl;
        cout << "0. Salir" << endl;
        cout << "Elija una opción: ";
        string entrada;
        cin >> entrada;
        if (!regex_match(entrada, opcionRegex)) {
        cout << "Opción inválida. Intente nuevamente." << endl;
        continue;  // Volver al inicio del bucle
        }
//Importante: hay que poner regex a las opciones de escribir.
        opcion = stoi(entrada);
        
        switch (opcion) {
            
            case 1: {
                
                cout << "Procesando"<<endl;
                break;
                
            }
            
            case 2: {
            
                string nombreArchivo;
                cout << "Ingrese el nombre del archivo: ";
                cin >> nombreArchivo;
                fstream registros_2;
                registros_2.open(nombreArchivo.c_str(), ios::in);

                if(!registros_2){
                    cout<<"El archivo no existe";
                    exit(1);   
                }
                else{

                    vector<Empleado> empleados = leerArchivo(nombreArchivo);
                    for (const auto& empleado : empleados) {
                        cout << "Nombre: " << empleado.nombre << endl;
                        cout << "Email: " << empleado.email << endl;
                        cout << "Edad: " << empleado.edad << endl;
                        cout << "Área de Trabajo: " << empleado.areaTrabajo << endl;
                        cout << "Salario: " << empleado.salario << endl;
                        cout << endl;
                    }
                }
            }
        
                break;

            case 3: {
                string departamento;
                cout << "Ingrese el departamento: ";
                cin.ignore();
                getline(cin, departamento);
                regex patron2("^[a-zA-Z ]{2,}$", regex_constants::icase); // regex que restringe a dos letras.
                if (regex_match(departamento, patron2)) {
                    cout << "Entrada válida"<<endl;
                    vector<Empleado> empleadosPorDepartamento = buscarPorDepartamento(empleados, departamento);
                    cout << "Empleados en el departamento de " << departamento << ":" << endl;
                    for (const auto& empleado : empleadosPorDepartamento) {
                        cout << "Nombre: " << empleado.nombre << endl;
                        cout << "Email: " << empleado.email << endl;
                        cout << "Edad: " << empleado.edad << endl;
                        cout << "Salario: " << empleado.salario << endl;
                        cout << endl;
                    }
                }
                else {
                    cout << "Entrada inválida";
                    exit(1);
                }
                break;
            }

            case 4: {
                int salarioMinimo, salarioMaximo;
                string temp_Min, temp_Max;
                regex patron3("^[0-9]+$");
                cout << "Ingrese el salario mínimo: ";
                cin >> salarioMinimo;
                cout << "Ingrese el salario máximo: ";
                cin >> salarioMaximo;
                temp_Min = to_string(salarioMinimo);
                temp_Max = to_string(salarioMaximo);

                if(regex_match(temp_Min, patron3) && regex_match(temp_Max, patron3)){
                    vector<Empleado> empleadosPorSalario = buscarPorSalario(empleados, salarioMinimo, salarioMaximo);
                    cout << "Empleados con salario entre " << salarioMinimo << " y " << salarioMaximo << ":" << endl;
                    for (const auto& empleado : empleadosPorSalario) {
                        cout << "Nombre: " << empleado.nombre << endl;
                        cout << "Email: " << empleado.email << endl;
                        cout << "Edad: " << empleado.edad << endl;
                        cout << "Área de Trabajo: " << empleado.areaTrabajo << endl;
                        cout << endl;
                    }
                }
                else{
                    cout<<"El rango de salarios no es válido"<<endl;
                    exit(1);
                }
                
                break;
            }

            case 0: {

                salir = false;
                break;
            }
        }
    }while (salir);
        return 0;
}       
