import sys
from Trabajadores import Empleado


# En este archivo se hace el llamado del archivo Trabajadores.py,
# que permite hacer uso de todas las funciones que se encuentran
# dentro de esta clase. Se tienen dos funciones, una se encarga
# de buscar los empleados por departamento, es decir, cuando por
# consola se digita la palabra: IT o it o iT, IT, se debe filtrar
# todas las personas que cumplan con este requisito, y esto se lo-
# gró usando una regex que permite escribir esta búsqueda de esa
# manera, por tanto, el resultado se mostrará por consola sin pro-
# blema alguno. La segunda función busca por rango de salarios, pr-
# imero se escribe el valor más bajo a buscar y luego el rango más
# alto, entonces la función tiene un ciclo for que hará todo este
# trabajo, que al final se guarda en una lista que mostrará por
# consola todas aquellas personas que cumplen con este requisito.
# Primeramente, lo que se mostrará será un menú que posee 3 opcion-
# es, si el usuario escribe alguna inconsistencia entonces el progr-
# ama mostrará un mensaje por consola: opción inválida y así de mane-
# ra infita. Luego, si el usuario digita la opción 1 entonces, como
# ya está definida la ruta del archivo .csv, lo único que hará el u-
# suario será escribir el puesto de trabajo que desea solicitar y con
# el llamado de la función buscarPorDepartamento se muestra por conso-
# la el resultado de todos los registros hallados. Si el usuario digita
# la opción 2, entonces se le pide el rango de salarios por consultar y
# con el llamado de la función: buscarPorSalario se muestra los registros
# de los trabajadores que cumplen con lo digitado por el usuario.


while True:
    print("Menú principal")
    print("0. Salir")
    print("1. Consultar por departamento")
    print("2. Consultar por salario")
    opcion = input("Ingrese una opción\n")
    if opcion == "0":
        sys.exit()
    elif opcion == "1":
        archivo_principal = "../../employees.csv" 
        departamento = input("Escribe el departamento que desea buscar\n")
        Empleado.buscarPorDepartamento(archivo_principal, departamento)
    elif opcion == "2":
        archivo_principal = "../../employees.csv"
        while True:
            try:
                sal_Min = int(input("Digite el salario mínimo: "))
                if sal_Min < 0:
                    print("El salario mínimo debe ser un número positivo")
                    continue
                sal_Max = int(input("Digite el salario máximo: "))
                if sal_Max < 0:
                    print("El salario máximo debe ser un número positivo")
                    continue
                if sal_Min > sal_Max:
                    print("Error en el orden del intervalo solicitado.\n")
                    continue
                break
            except ValueError:
                print("Al menos uno de los rangos digitados no es válido\n")
                continue
        intervalo_Salario = Empleado.buscarPorSalario(
            archivo_principal, sal_Min, sal_Max
        )
    else:
        print("opcion inválida \n")
