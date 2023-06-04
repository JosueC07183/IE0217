

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
    elif opcion == "2":
        archivo_principal = "../../employees.csv" # Archivo por default para calificar
        sal_Min = int(input("Digite el salario mínimo: "))
        sal_Max = int(input("Digite el salario máximo: "))
        

    else:
        print("opcion inválida \n")
