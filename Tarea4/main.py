from Trabajadores import Empleado

while True:
    print("Menú principal")
    print("0. Salir")
    print("1. Consultar por departamento")
    print("2. Consultar por salario")
    opcion = input("Ingrese una opción\n")
    if opcion == "0":
        exit()
    elif opcion == "1":
        archivo_principal = "../../Datos.csv"
        departamento = input("Escribe el departamento que desea buscar\n")
        Empleado.buscarPorDepartamento(archivo_principal, departamento)
    elif opcion == "2":
        archivo_principal = "../../Datos.csv"
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
                elif sal_Min > sal_Max:
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
