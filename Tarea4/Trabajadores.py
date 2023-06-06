import csv
import re


class Empleado:
    def buscarPorDepartamento(file_csv, departamento):
        """Función que muestra el valor de lambda.

        Esta función contiene dos parámetros que se van a
        encargar de mostrar los registros de los empleados
        que cumplan con el puesto de trabajo que se digite
        por consola. Independientemente si se escribe en m-
        inúscula o mayúscula el programa será capaz de bus-
        car e imprimir los registros. Además, si el program-
        a no encuentra el departamento solicitado simplemen-
        te no va mostrar nada. Luego, suponiendo que el csv
        tendrá varios errores entonces, lo que se hizo fue
        uso de regex para poder imprimir la información cor-
        rectamente. Por ejemplo, si en el nombre hay caract-
        eres y números, se sabe que esto no es un formato c-
        orrecto, entonces cuando se imprime la información
        de todos los empleados que trabajan en cierto depar-
        tamento y hay un registro que no cumple con la regex,
        entonces se mostrará un valor de "None". Similarment-
        e con el formato del email, si el programa se topa
        con un email inválido, entonces a ese registro se mos-
        trará un valor de "None". Lo mismo para la edad, solo
        se admitirán números positivos mayores a 18, de lo con-
        trario, habrá un "None" para ese espacio. Y así con las
        dos columnas restantes.


        Parameters
        ----------
        file_csv : este parámetro se encarga de abrir el csv.
        Importante codificar en utf-8, sino flake 8 no funci-
        ona bien.

        file : contiene el contenido del csv.

        leer : junto con el comando next se puede saltar los
        headlines del csv.

        Returns
        -------
        empleado[] : muestra la lista de los empleados.
        """

        with open(file_csv, "r", encoding="utf-8") as file:
            leer = csv.reader(file)  # Se lee el csv
            next(leer)  # Esto salta los headlines
            # El siguiente loop lo que hara es una lectura de todo el documento
            # csv para ir buscando el puesto de trabajo en el array 3 del csv,
            # pues así está definido el orden de las columnas(según el formato
            #  de la tarea). Entonces, al usar strip().lower se ignoran las
            # minusculas y mayusculas, es decir, será una lectura pareja. Ento-
            # nces cuando se encuentran coincidencias entre los string, se
            # procede a imprimir los datos (respetando los array) de cada
            # empleado que cumple lo introducido por consola.
            for empleado in leer:
                if empleado[3].strip().lower() == departamento.lower():
                    nombre = empleado[0].strip()
                    if re.search(r"^[A-Z][a-zA-Z ]*$", nombre):
                        print(f"Nombre: {nombre}")
                    else:
                        print("Nombre: None")

                    correo = empleado[1].strip()
                    if re.search(
                        r"^[a-zA-Z0-9._-]+@[a-zA-Z0-9]+.[a-zA-Z.]{3,8}$", correo
                    ):
                        print(f"Correo: {correo}")

                    edad = empleado[2].strip()
                    if re.search(r"^(1[8-9]|[2-9]\d+)$", edad):
                        print(f"Edad: {edad}")
                    else:
                        print("Edad: None")

                    departamento = empleado[3].strip()
                    if re.search(r"^[a-zA-Z\s]{2,}$", departamento):
                        print(f"Departamento: {departamento}")
                        # print(f"Salario: {empleado[4].strip()}")
                    else:
                        print("Departamento: None")

                    salario = empleado[4].strip()
                    if re.search(r"^[1-9][0-9]*$", salario):
                        print(f"Salario: {salario}")
                    else:
                        print("Salario: None")
                    print("\n")

    # Se crea la función con tres argumentos, el nombre del archivo
    # por default los otros dos argumentos es salario pequeño y el
    # grande. Después se crea una variable para almacenar la lista
    # de intervalos que el usuario desee buscar. Luego, se abre el
    # archivo csv, se lee su contenido. Y con el ciclo for entonces
    # primero se ubica el array de estos valores para realizar
    # la comparación de ambas cantidades, hecho esto se guarda en la
    # variable interval_Salario por medio de append y esta función
    # devolverá esa lista.

    def buscarPorSalario(file_csv, sal_Min, sal_Max):
        interval_Salario = []
        with open(file_csv, "r", encoding="utf-8") as file:
            leer = csv.reader(file)
            next(leer)
            for empleado in leer:
                # Se ubica la columna donde está el array de salarios.
                salario = int(empleado[4].strip())
                if sal_Min <= salario <= sal_Max:
                    nombre = empleado[0].strip()
                    if re.search(r"^[A-Z][a-zA-Z ]*$", nombre):
                        print(f"Nombre: {nombre}")
                    else:
                        print("Nombre: None")

                    correo = empleado[1].strip()
                    if re.search(
                        r"^[a-zA-Z0-9._-]+@[a-zA-Z0-9]+.[a-zA-Z.]{3,8}$", correo
                    ):
                        print(f"Correo: {correo}")
                    else:
                        print("Correo: None")

                    edad = empleado[2].strip()
                    if re.search(r"^(1[8-9]|[2-9]\d+)$", edad):
                        print(f"Edad: {edad}")
                    else:
                        print("Edad: None")

                    departamento = empleado[3].strip()
                    if re.search(r"^[a-zA-Z\s]{2,}$", departamento):
                        print(f"Departamento: {departamento}")
                    else:
                        print("Departamento: None")
                    print("\n")

                    salario = empleado[4].strip()
                    if re.search(r"^[1-9][0-9]*$", salario):
                        print(f"Salario: {salario}")
                    else:
                        print("Salario: None")

                    interval_Salario.append(empleado)
        return interval_Salario
