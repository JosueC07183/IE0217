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
# Se crea la función con tres argumentos, el nombre del archivo por default
# los otros dos argumentos es salario pequeño y el grande.
# Después se crea una variable para almacenar la lista de intervalos que el 
# usuario desee buscar. Luego, se abre el archivo csv, se lee su contenido.
# Y con el ciclo for entonces primero se ubica el array de estos valores para
# poder realizar la comparación de ambas cantidades, hecho esto se guarda en la
# variable interval_Salario por medio de append y esta función devolverá esa lista.
    def buscarPorSalario(file_csv, sal_Min, sal_Max):
        interval_Salario=[]
        with open(file_csv, 'r') as file:
            leer = csv.reader(file)
            next(leer)
            for empleado in leer:
# Se ubica la columna donde está el array de salarios.                
                salario = int(empleado[4].strip())
                if sal_Min <= salario <= sal_Max:
                    interval_Salario.append(empleado)
        return interval_Salario