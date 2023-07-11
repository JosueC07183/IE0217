#include "Operaciones.hpp"
#include <iostream>
using namespace std;

ops::ops(float num_1, float num_2)
{
    x = num_1;
    y = num_2;
}

void ops::Resultado()
{
    
    cout << "La suma de: " << x << " y "<< y << " es:" <<Suma() << endl;
    cout << "La resta de: " << x << " y "<< y << " es:" <<Resta() << endl;
    cout << "El producto de: " << x << " y "<< y << " es:" <<Producto() << endl;
    cout << "La división de: " << x << " y "<< y << " es:" <<Division() << endl;
}

float ops::Suma()
{
    return x + y;
}

float ops::Resta()
{
    return x - y;
}

float ops::Producto()
{
    return x * y;
}

float ops::Division()
{
    return x / y;
}
