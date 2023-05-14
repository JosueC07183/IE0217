#include <iostream>
using namespace std;

class Empleado
{
private:
    /* data */
public:

    string nombre;
    string correo;
    int edad;
    string departamento;
    double salario;

    Empleado(string nombre, string correo, int edad, string departamento, double salario);
    ~Empleado();

    void setNombre(string nombre);
    string getNombre();

    void setCorreo(string correo);
    string getCorreo();

    void setEdad(int edad);
    int getEdad();

    void setDepartamento(string departamento);
    string getDepartamento();

    void setSalario(double salario);
    double getSalario();

    Empleado(){}

};

