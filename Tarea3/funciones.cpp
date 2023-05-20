/**
 * @file funciones.cpp
 * @author Josue Salmeron Cordoba
 * @brief En este archivo se implementan las funciones creadas en el prototipo. Inicialmente se hace hace la función leerArchivo(),luego la de buscarPorDepartamento
 * y buscarPorSalario. Cada una de estas funciones tiene implementada una expresión regular que le da sentido al programa, es decir, cada vez que el usuario digite una
 * solicitud el programa responderá como se debe.
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

/**
 * @brief La función leerArchivo() se encarga de pedir la ruta del archivo del archivo a imprimir, y esto
 * se logra usando un loop for, que accede al vector de Struct y toma los valores del archivo escrito por
 * consola. En ese sentido, se puede ver por consola toda la información del archivo porque al final de 
 * cada iteración, se usa un push_back() para agregar los objetos al final del vector.
 * Luego, si el usuario no escribe correctamente la dirección del archivo que desea estudiar
 * entonces el programa mostrará un error e indicará que el archivo no existe y se vuelve a 
 * mostrar el menu. Claramente, se puede ver la demás información como departamento de trabajo
 * y desgloses de salarios, pero es mejor primero ver toda la información de los empleados para 
 * poder realizar el filtrado de la información. Ahora, una vez que se digita correctamente la ruta
 * del archivo a estudiar, se hace uso de una expresión regular para permitir la mayoría de caracteres 
 * para que el archivo a leer tenga sentido con la información que contiene, así, se hace uso de un ciclo
 *  while para acceder a las variables de interes, de donde se hace uso de funciones como stoi, esto
 * para convertir un string a integer ya que al tratarse de regex, solo se deben manejar strings. Finalmente, 
 * se cierra el archivo para detener el flujo del programa.
 * @param Datos: en esta variable se encuentra el string de los archivos a trabajar. 
 * @param registros: sirve para ubicar la ruta del archivo general.
 * @return vector<Empleado> 
 */
vector<Empleado> leerArchivo(string Datos){
cout<<"Información general de los empleados"<<endl;
    vector<Empleado> empleados;

    fstream registros;
    registros.open(Datos.c_str(), ios::in);
    if (!registros){
        cout << "El archivo no existe" << endl;
        return empleados;
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
            empleado.salario = stoi(matches[5].str());
            empleados.push_back(empleado);
        }
    }

    registros.close();
    return empleados;
}
/**
 * @brief En esta función se accede a la dirección de los parámetros del vector Empleado, es decir, la información
 * de estos y en este caso, el puesto de trabajo de cada uno de ellos. Para esto se hizo uso de un ciclo for para ver
 * estos resultados por consola. Un detalle que optimiza el resultado mostrado por consola es que si el usuario escribe
 * algún caracter que no corresponda a una letra del abecedario, o un numero o un puesto de trabajo con una soloa letra, 
 * entonces el programa termina de manera inmediata, para esto hay una expresión regular que controla esto. Ahora, si el
 * usuario escribre un puesto de trabajo que coincida con la información mostrada en el primer case, el programa mostrará
 * correctamente lo solicitado, independientemente si escribe: Salud o salud, se espera que muestren las personas con estos
 * puestos esto porque se hizo uso de c_str() para poder mostrar la información correctamente.
 * 
 * @param empleados: cadena de información de las personas.
 * @param departamento: puesto de trabajo de cada persona.
 * @return vector<Empleado> 
 */
vector<Empleado> buscarPorDepartamento(const vector<Empleado>& empleados, const string& departamento) {
    vector<Empleado> resultado;
    for (const auto& empleado : empleados) {
        if (strcasecmp(empleado.areaTrabajo.c_str(), departamento.c_str())==0) {
            resultado.push_back(empleado);
        }
    }
    return resultado;
}

/**
 * @brief Esta función solictará por consola dos valores enteros al usuario con el fin de filtrar la información de los empleados y
 * mostrarla por consola aquellas personas que cumplan dentro de los parámetros o intervalo establecido por el usuario. Si el usuario
 * escribe algún caracter que no corresponda a un número o digita un número negativo, el programa termina. De esta manera, se usa un 
 * ciclo for para acceder a todos estos valores y eso justifica el uso de un condicional para comparar la primera y segunda cantidad 
 * escrita por el usuario. Y como en las demás funciones, también se hace uso de push_back para agregar los valores de los objetos al 
 * final del vector.
 * 
 * @param empleados: personas de la corporación.
 * @param salarioMinimo: límite inferior de salario.
 * @param salarioMaximo: límite superior de salario.
 * @return vector<Empleado> 
 */
vector<Empleado> buscarPorSalario(const vector<Empleado>& empleados, int salarioMinimo, int salarioMaximo) {
    vector<Empleado> resultado;
    for (const auto& empleado : empleados) {
        if (empleado.salario >= salarioMinimo && empleado.salario <= salarioMaximo) {
            resultado.push_back(empleado);
        }
    }
    
    return resultado;
}
