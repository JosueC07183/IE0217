/**
 * @file main.cpp
 * @author Josue Salmeron Cordoba
 * @brief Primeramente se le pide al usuario la dirección del nombre del archivo a usar.
 * Si el archivo no existe el programa termina de manera inmediata. Luego se tiene una
 * expresión regular que controla toda la información que se manejará dentro del archivo
 * en cuestión. Cuando se escribe bien la dirección del archivo se hace un loop while donde
 * se almacenará la información correspondiente en un vector con el uso de push_back. Después
 * se muestra el menu intuitivo con 4 opciones.
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
/**/
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
                        empleado.correo = matches[2].str();
                        empleado.edad = stoi(matches[3].str());
                        empleado.areaTrabajo = matches[4].str();
                        empleado.salario = stod(matches[5].str());
                        empleados.push_back(empleado);
                    }
                }

                registros.close();
/**
 * @brief Aquí se muestra el menu. En este menu se maneja la expresión regular de solo admitir
 * valores entre 0 y 3, de lo contrario, el programa le dirá al usuario que la opción digitada
 *  es incorrecta y volverá a mostrar el menu. Es decir, se hizo uso de una expresión regular
 * y el uso de la función stoi para contralar el flujo de esta parte del programa.
 * 
 * 
 */
    int opcion;
    bool salir = true;
    regex opcionRegex("[0-4]"); //Expresión regular que filtra números del 0 al 3.
    
    do {
        
        cout << "----- Menú -----" << endl;
        cout << "1. Imprimir información de los empleados" << endl;
        cout << "2. Buscar por departamento" << endl;
        cout << "3. Buscar por salario" << endl;
        cout << "0. Salir" << endl;
        cout << "Elija una opción: ";
        string entrada;
        cin >> entrada;
        if (!regex_match(entrada, opcionRegex)) {
        cout << "Opción inválida. Intente nuevamente." << endl;
        continue;  // Volver al inicio del bucle
        }

        opcion = stoi(entrada);
        
        switch (opcion) {
/**
 * @brief El primer caso se encarga de mostrar la información del archivo donde se digitó la respectiva dirección,
 * entonces, al dar opción 1, el programa desplegará toda la información correspondiente. Ahora, si en el archivo 
 * a analizar existe una línea sin datos, entonces el programa mostrará una excepeción.
 * 
 */
            case 1: {
             try{ 
               vector<Empleado> empleados = leerArchivo(adrArchivo);
                    for (const auto& empleado : empleados) {
                        cout << "Nombre: " << empleado.nombre << endl;
                        cout << "Correo: " << empleado.correo << endl;
                        cout << "Edad: " << empleado.edad << endl;
                        cout << "Departamento: " << empleado.areaTrabajo << endl;
                        cout << "Salario: " << empleado.salario << endl;
                        cout << endl;
                }
             }
             catch(const std::exception& e){
                cout << "Inconsistencia encontrada: " << e.what() << endl;

             }
            }
            break;
/**
 * @brief El segundo caso pide el nombre del departamento donde se mostrará todas las personas que pertenecen 
 * a un puesto de trabajo en especifico. Se hizo uso de expresiones regulares para mostrar controlar las palabras
 * que digite el usuario, es decir, que sea mayor a 2 letras, que se imprima la información aunque se escriban los
 * nombres de los trabajos en minúscula. Luego, si el usuario escribe una número o un caracter que no tiene sentido 
 * con lo solicitado entonces el programa termina.
 */
            case 2: {
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
                        cout << "Correo: " << empleado.correo << endl;
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
/**
 * @brief En el tercer caso se definen las variables enteras de salario minimo y maximo. Las cuales se deben pasar strings
 * porque serán trabajadas con regex. Por tanto, en el condicional se usa un "Y" para que reconozca que si el usuario digita
 * un valor extraño por consola de manera inmediata haga falsa toda la expresión y el programa termine, es decir, el programa
 * no se tomará la molestia de solicitar el otro valor, pues no tendrá sentido alguno. Ahora, si el usuario escribe correctamente
 * las cantidades a analizar entonces, el programa mostrará las personas que cumplen con los requisitos dados. Y si los valores son
 * muy altos entonces el programa mostrará una excepción.
 * 
 */
            case 3: {
                int salarioMinimo, salarioMaximo;
                string temp_Min, temp_Max;
                regex patron3("^[0-9]+$");
                cout << "Ingrese el salario mínimo: ";
                cin >> salarioMinimo;
                cout << "Ingrese el salario máximo: ";
                cin >> salarioMaximo;
                temp_Min = to_string(salarioMinimo);
                temp_Max = to_string(salarioMaximo);
                try
                {
                    if(regex_match(temp_Min, patron3) && regex_match(temp_Max, patron3)){
                        vector<Empleado> empleadosPorSalario = buscarPorSalario(empleados, salarioMinimo, salarioMaximo);
                        cout << "Empleados con salario entre " << salarioMinimo << " y " << salarioMaximo << ":" << endl;
                        for (const auto& empleado : empleadosPorSalario) {
                            cout << "Nombre: " << empleado.nombre << endl;
                            cout << "Correo: " << empleado.correo << endl;
                            cout << "Edad: " << empleado.edad << endl;
                            cout << "Departamento: " << empleado.areaTrabajo << endl;
                            cout << endl;
                        }
                    }
                    else{
                        cout<<"El rango de salarios no es válido"<<endl;
                        exit(1);
                    }
                }
                catch(const std::exception& e){
                    cout<<"Error: "<<e.what()<<endl;
                }
                registros.close();
                break;
            }
/**
 * @brief En este último caso, es el más sencillo ya que acá es donde el programa finaliza, y esto basta con escribir un 0, de esa manera 
 * el ciclo do while() finalizará.
 * 
 */
            case 0: {

                salir = false;
                break;
            }
        }
    }while (salir);
        return 0;
}       
