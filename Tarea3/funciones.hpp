#include <iostream>
#include <vector>
using namespace std;

//Prototipo de las funciones.

struct Empleado {
    string nombre;
    string email;
    int edad;
    string areaTrabajo;
    double salario;
};

//bool validarEntrada();
vector<Empleado> leerArchivo(string Datos);
vector<Empleado> buscarPorDepartamento(const vector<Empleado>& empleados, const string& departamento);
vector<Empleado> buscarPorSalario(const vector<Empleado>& empleados, int salarioMinimo, int salarioMaximo);
