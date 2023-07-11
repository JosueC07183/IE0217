def freq_app(cadena_txt):
    frase = cadena_txt.split()
    dic_count = {}
    for i in frase:
        dic_count[i] = dic_count.get(i, 0)+1

    print(dic_count)
aux = "Hola 3 Esteban todo bien Esteban 4 bien"
freq_app(aux)