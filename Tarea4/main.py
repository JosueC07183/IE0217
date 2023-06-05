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
        archivo_principal = "../../employees.csv" # Archivo por default para calificar
        departamento = input("Escribe el departamento que desea buscar\n")
        Empleado.buscarPorDepartamento(archivo_principal, departamento)
    elif opcion == "2":
        archivo_principal = "../../employees.csv" # Archivo por default para calificar
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
                    print("Error al digitar el orden del intervalo solicitado.\n")
                    continue
                break
            except ValueError:
                print("Al menos uno de los rangos digitados no es válido\n")
                continue
        intervalo_Salario = Empleado.buscarPorSalario(archivo_principal, sal_Min, sal_Max)
        for empleado in intervalo_Salario:
            correo = empleado[1].strip()
            print(f"Nombre: {empleado[0].strip()}")
            #print(f"Correo: {empleado[1].strip()}")
            print(f"Correo: {correo}")
            print(f"Edad: {empleado[2].strip()}")
            print(f"Departamento: {empleado[4].strip()}")
            print("\n") # Se muestre un salto de línea por cada empleado.
    else:
        print("opcion inválida \n")