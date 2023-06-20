# Inicialmente de la carpeta Functions-
# se importa el archivo funciones.
from Functions import funciones

# Llamado de los datos de la página web dada.
llamar_datos = funciones.llamado_datos()

# Ordenanamiento del csv
ordenar_csv = funciones.orden_datos()

# Se hace uso de la primera función para comprobar-
# el manejo de excepciones.
prueba = funciones.stats_energy('1990', 'Electricity Net Generation From Water, All Sectors')

# Análisis tendencia exponencial con los datos de-
# generación neta: Gas natural.
bars = funciones.exp_analysis()

# esto genera un error. Pero aquí se puede hace el catch, luego,-
# realizar un ciclo for que vaya iterando los años, y muestre el-
#  maximo y el minimo.
CoefPearson = funciones.pearson_val(
    "Electricity Net Generation From Natural Gas, All Sectors",
    "Electricity Net Generation From Solar, All Sectors",
 )

# Análisis de datos con generación neta: Carbón, por medio de un-
# diagrama de pastel de donde se muestra la desviación estándar.
std_value_pieanalysis = funciones.pie_analysis()

# Análisis de datos con generación neta: de otros sectores no-
# considerados por medio de un diagrama de dispersión.
info_scatter = funciones.scatter_analysis()

