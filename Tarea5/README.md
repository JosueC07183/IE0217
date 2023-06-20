### Universidad de Costa Rica
#### Escuela de Ingeniería Eléctrica
#### Faculta de Ingeniería
#### IE0217-Estructuras de Abstractas de Datos y Algoritmos
##### Profesor: Esteban Badilla
##### Estudiante: Josué Salmerón Córdoba
##### I ciclo 2023
#### Tarea 5

## Resumen
> En esta tarea se hizo uso de pandas...
---
## Desarrollo 
> 

### Primer análisis
-Se consideraron los años 1973 al 1978, 1990 al 1995 y 2000 al 2005, de donde se obtuvo la media de la generación de electricidad neta a partir de gas natural, así, realizando 3 gráficos de barras se obtuvo el siguiente resultado:
![App Screenshot](https://github.com/JosueC07183/IE0217/blob/main/Tarea5/Imgs/Figure_1.png)
Note que el comportamiento tiene una tendencia parábolica, no se puede decir que es 100% exponencial porque el aumento no es tan brusco ya que en los años 70's hubo producción que con los años fue haciéndose más grande.

### Segundo análisis
- En este caso se realizó un diagrama de pastel y notar que principalmente en el año 1983 se tiene
la desviación estándar más alta, esto significa que:... y dos años después se registra la desviación más baja, es decir,...
el otro detalle es que este dato fue constante en el 2004 y 2007, esto es... lo mismo en los años 2005 y 2006 con un leve incertidumbre.
![App Scrennshot](https://github.com/JosueC07183/IE0217/blob/main/Tarea5/Imgs/Figure_2.1.png)

### Tercer análisis
- Para este análisis se realizó un diagrama de dispersión para un período de 10 años en la decada de los noventas e inicios del 2000, esto a partir de la autocorrelación que se obtuvo en cada año. Por su parte, en los años noventa, se tienen datos agrupados conforme los años pasan, esto indica que... a como también existen algunos otros que están dispersos, esto es....
Para los años 2000, se tiene un agrupamiento similar con algunos datos muy dispersos. 
![App Scrennshot](https://github.com/JosueC07183/IE0217/blob/main/Tarea5/Imgs/Figure_3.png)

>**Nota**: Los datos del eje X, se ven así porque la imagen debe expandirse para poder observarla con mayor claridad.


## Jerarquía de archivos.
A continuación, se muestra el orden de los archivos de esta tarea.

```
├── IE0217
    ├── Tarea5
        ├── main.py
        ├── Makefile
        ├── README.md
        └── Functions
            ├──funciones.py
        ├──Imgs
            ├── 4.png
            ├── 5.png
            ├── Figure_1.png
            ├── Figure_2.1.png
            ├── Figure_2.png
            └── Figure_3.png
        
```

## Comandos para correr la tarea
> Basta con abrir una terminal dentro de la carpeta donde se encuentren todos los archivos y escribir ``make``. Hecho esto se genera una carpeta ``__pycache__``, para eliminar esto basta con escribir ``make clean`` y así puede limpiar el directorio actual.

## Manejo de excepciones.
- Este pequeño apartado es una breve demostración del manejo de excepciones dentro de esta tarea. La primer excepción se trata de algunos datos que no son de tipo float sino más bien string, esto porque en ese año, no se realizaba dicho proceso para obtener electricidad, por lo que no existen registros, entonces lo que hay es una etiqueta: _Not Available_, por lo que a la hora de hacer el análisis sin tener una excepción, el programa mostrará errores. Solo que en este caso se logró atrapar dicha excepción.
![App Scrennshot](https://github.com/JosueC07183/IE0217/blob/main/Tarea5/Imgs/4.png)
- La otra excepción que se atrapó fue la de tratar de realizar un análisis en un rango de años que no está disponible en el csv, o sino tratar de extraer los datos de generación neta de electricidad de un recurso que no se considera en el csv, _Water_ por ejemplo. Entonces, a la hora de hacer el llamado de la función *stats_energy()*, esto mostrará un error, pero al tener el **try-except** esto no sucederá.
![App Scrennshot](https://github.com/JosueC07183/IE0217/blob/main/Tarea5/Imgs/5.png)
