### Universidad de Costa Rica
#### Escuela de Ingeniería Eléctrica
#### Faculta de Ingeniería
#### IE0217-Estructuras de Abstractas de Datos y Algoritmos
##### Profesor: Esteban Badilla
##### Estudiante: Josué Salmerón Córdoba
##### I ciclo 2023
#### Tarea 4

## Resumen
> Esta asignación realiza las mimas funciones que se implementaron en la tarea 3, pero con la gran diferencia que se usó Python. Inicialmente se muestra un menú con 3 opciones 0-Salir, 1-Consultar por departamento y 3-Consultar por salario. En cada una de estas opciones se implementó expresiones regulares y excepciones para que la ejecución del programa no deje de funcionar, es decir, está diseñada para ejecutarse a pesar de que se introduzcan por consola valores o inconsitencias durante su ejecución. 

## Relación C++ y Python. 
> Al tratarse de un lenguaje compilado y otro interpretado se lograron encontrar algunas relaciones principales a lo largo de la programación de esta tarea. La primera es el uso de las expresiones regulares, se trata de algo universal pero esto aplicó para ambas tareas. La segunda relación tiene que ver con el catch de las excepciones, básicamente se usa el mismo comando para atraparlas, o sea, un try catch para C++ y lo mismo para Python, solo que en vez de catch, se usa la palabra except. La tercera relación es que para ambas tareas tareas se usó un archivo por aparte para construir las funciones solicitadas, y en ambos main.cpp y main.py se hizo el include y el import respectivamente, note que la diferencia aquí es únicamente la palabra para hacer referencia a otro archivo que tiene funciones que no se encuentran en el main. Ahora, la misma lógica se realizó  (por medio de un punto (**.**)) una vez que se accede a las opciones de búsqueda, o sea, se tiene el llamado de la función con sus respectivos parámetros.

## Nueva implementación en Python.
> En esta nueva implementación fueron muy pocas las librerías que se hicieron uso, entre ellas: sys, csv y re. Por medio de una clase se definieron las funciones que realizan el trabajo solicitado, esto por medio de una lectura del csv y por medio de un ciclo for se recorren los arrays de cada empleado con su respectiva característica (nombre, correo, edad, departamento, salario). Se fijo una posición en específico para hacer el estudio, es decir, al estar buscando el departamento, entonces, se toma el array 3 (asumiendo que el archivo **employees.csv** posee el orden de cada característica dado en el enunciado de la tarea 3.) De esa manera, por medio de condicionales y expresiones regulares se filtra la información consistente a lo solicitado. Similarmente con la segunda parte de esta tarea, primero se lee el csv y con un loop for, condicionales con regex de por medio se filtra la información y con un append se obtiene lo solicitado por el usuario. Finalmente desde el main, se tiene un menú que se encargará de guiar al usuario con lo que éste desee realizar. Se tomaron todas las medidas posibles para mostrar la información adecuada en todo momento, por ejemplo, que el usuario digite algún puesto de trabajo que no está en el archivo csv, entonces se muestra un mensaje con la información respectiva. Otro caso sea que el usuario digite salarios muy altos o muy bajos, en ese sentido el programa le mostrará un mensaje dependiendo del contexto.

## Investigación de pre-commit hooks.
> Los pre-commits hooks es una herramienta automática que se encarga de revisar los cambios en un código antes de hacer commit, es capaz de mostrar las estadísticas de error que posee el código antes del commit. Esta da la oportunidad de revisar para hacer los cambios necesarios para finalmente hacer el commit. Para poder hacer esto primero se tiene que instalar la herramienta, basta con escribir: _pip install pre-commit_. Después se debe crear un archivo con extensión .yaml de donde se va configurar los id para estudiar el código con flake. La configuración del archivo .yaml es la siguiente:
```
repos:
-   repo: https://github.com/JosueC07183/IE0217/tree/main/Tarea4
    rev: task4
    hooks:
    -   id: flake8
        language_version: python3
```
De donde:
- repo: contiene el link del repositorio.
- rev: es una etiqueta de esta tarea.
- hooks: esto se encargará de ver de manera automática lo relacionado a flake 8.

## Jerarquía de archivos.
A continuación, se muestra el orden de los archivos de esta tarea.

```
├── IE0217
    ├── Tarea4
        ├── main.py
        ├── Makefile
        ├── README.md
        └── Trabajadores.py
```

## Comandos para correr la tarea
> Basta con abrir una terminal dentro de la carpeta donde se encuentren todos los archivos y escribir ``make``. Hecho esto se genera una carpeta ``__pycache__``, para eliminar esto basta con escribir ``make clean`` y así puede limpiar el directorio actual.