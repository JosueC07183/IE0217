import csv

class Empleado:


    def buscarPorDepartamento(file_csv, departamento):
        with open(file_csv, 'r') as file:
            leer = csv.reader(file) # Se lee el csv 
            next(leer) # Esto salta los headlines
# El siguiente loop lo que hara es una lectura de todo el documento
# csv para ir buscando el puesto de trabajo en el array 3 del csv, 
# pues así está definido el orden de las columnas(según el formato de
# la tarea). Entonces, al usar strip().lower se ignoran las minusculas
# y mayusculas, es decir, será una lectura pareja. Entonces cuando se 
# encuentran coincidencias entre los string, se procede a imprimir los
# datos (respetando los array) de cada empleado que cumple lo introducido 
# por consola.
            for empleado in leer:
                if empleado[3].strip().lower == departamento.lower():
                    print(f"Nombre: {empleado[0].strip()}")
                    print(f"Correo: {empleado[1].strip()}")
                    print(f"Edad: {empleado[2].strip()}")
                    print(f"Salario: {empleado[4].strip()}")
                    print("\n")


