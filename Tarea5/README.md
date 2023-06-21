### Universidad de Costa Rica
#### Escuela de Ingeniería Eléctrica
#### Faculta de Ingeniería
#### IE0217-Estructuras de Abstractas de Datos y Algoritmos
##### Profesor: Esteban Badilla
##### Estudiante: Josué Salmerón Córdoba
##### I ciclo 2023
#### Tarea 5

## Resumen
> En esta tarea se hizo uso de varias librerías de Python tales como pandas, requests, matplotlib y numpy, todo ellas fueron necesarias para poder crear cada una de las funciones, iniciando con la llamado de datos, es decir, accediendo al contenido de una página web y extraer el link del archivo .xls, todo esto gracias a la librería ``requests`` y luego con ayuda de pandas se convirtió a csv. Hecho esto, la librería de pandas ayudó a optimizar el archivo csv ya que el archivo generado contenía algunas filas, celdas con contenido no necesario para el respectivo análisis. Una vez que el csv fue opmtimizado las demás funciones creadas para conocer la media, la desviación estándar, la autocorrelación y coeficiente de Pearson fue una tarea sencilla porque simplemente bastó con escribir _.mean()_, y obtener el valor deseado. Lo que prosiguió fue hacer uso de la librería matplotlib y numpy, esto para visualizar los datos de usando gráficos de barras, de pastel y de dispersión. Finalmente, se realizó el respectivo análisis para cada una de las gráficas generadas, de donde se obtuvieron 3 conclusiones, la primera es que la generación de electricidad a partir de gas natural aumenta conforme pasan los años. La segunda conclusión es que en el pasado la generación de electricidad a partir del carbón fue muy alto en el año 1983, hoy en día se sigue usando este recurso, pero con cierto control. La tercer conclusión fue un resultado predecible, ya que la generación de electricidad se está obteniendo a partir de recursos diferentes, por lo que probablemente el año 1999 y el 1997 usaron otro recurso, y así en el segundo milenio, esto justifica el hecho de tener muchos datos dispersos.
---
## Desarrollo 
- A continuación, se presenta el análisis realizado para cada gráfica obtenida.

### Primer análisis
-Se consideraron los años 1973 al 1978, 1990 al 1995 y 2000 al 2005, de donde se obtuvo la media de la generación de electricidad neta a partir de gas natural, así, realizando 3 gráficos de barras se obtuvo el siguiente resultado:
![App Screenshot](https://github.com/JosueC07183/IE0217/blob/main/Tarea5/Imgs/Figure_1.png)

Note que el comportamiento tiene una tendencia parábolica, no se puede decir que es 100% exponencial porque el aumento no es tan brusco ya que en los años 70's hubo una producción considerable que con los años fue haciéndose más grande.

### Segundo análisis
- En este caso se realizó un diagrama de pastel y notar que principalmente en el año 1983 se tiene
la desviación estándar más alta, esto significa que la generación de electricidad neta a partir del carbón fue muy dispersa con respecto a la media de ese año. Los siguientes dos años (1983 y 1984) registran la desviación estándar más pequeña, es decir, en esos periodos, la generación se mantuvo estable, dentro del rango de la media. Un comportamiento similar se mostró en la época del 2000, pues en el 2004 y 2007 la producción fue estable, pero en el pasado, en el 2003 la producción se disparó, quiere decir que se trata de alguna fluctuación en esa época.
![App Scrennshot](https://github.com/JosueC07183/IE0217/blob/main/Tarea5/Imgs/Figure_2.1.png)

### Tercer análisis
- Para este análisis se realizó un diagrama de dispersión para un período de 10 años en la decada de los noventas e inicios del 2000, esto a partir de la autocorrelación que se obtuvo en cada año. Así,
en los años 1993 y 1994, 1995 y 1996 se puede asegurar que se presenta un patrón estacional, ya que la producción del año anterior y el siguiente está relacionadas, claro existe cierta diferencia, pero el diagrama de dispersión muestra que la producción estuvo alrededor de los 0.48-0.50. El mismo comportamiento para el año 1995 y 1996, ambas producciones están correlacionadas. En esta misma decada, a partir de 1997 en adelante, se obtienen datos muy dispersos, por lo que no hay autocorrelación alguna en esos años. Luego, para los años 2005 en adelante se podría afirmar la existencia de autocorrelación en los datos, no obstante, se tiene un punto de inflexión, en el año 2006 si se comparan los años 2005 y 2007, lo mismo sucede con los años 2008 y 2010, y 2007 con 2011. A pesar, de este patrón al generación de electricidad usando otros medios están autocorrelacionados en los periodos mencionados. 
![App Scrennshot](https://github.com/JosueC07183/IE0217/blob/main/Tarea5/Imgs/Figure_3.png)

>**Nota**: Los datos del eje X, para la primer y tercer imagen se ven así porque la imagen debe expandirse para poder observarla con mayor claridad cuando corre la tarea con el makefile.


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
