def leerArchivo():
    aux = input("Escriba la dirección del archivo\n")
    with open(aux, "r") as file:
        info = file.read()
    print(info)
    file.close()


while True:
    print("Menú principal")
    print("1. Leer archivo")
    print("2. Buscar por departamento")
    print("3. Buscar por salario")
    print("4. Salir")
    opcion = input("Ingrese una opción\n")
    if opcion == "1":
        leerArchivo()  # Poner excepción aqui.
    elif opcion == "4":
        exit()

    else:
        print("opcion inválida \n")
