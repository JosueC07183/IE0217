import pandas as pd
import requests
import matplotlib.pyplot as plt
import numpy as np


def llamado_datos():
    """
    En esta función se accede a la página web dada para acceder
    al archivo .xls, luego se hace una conversión a csv.

    Parameters
    ----------
    info_Datos : contiene la dirección de los datos.
    response : se hace el requests a los datos en la web.
    df : lee el excel y luego guarda el csv file con el
    nombre "datos2.csv".

    Returns
    --------
    Guarda el archivo csv en el directorio actual.
    """
    info_datos = "https://www.eia.gov/totalenergy/data/browser/xls.php?tbl=T07.02A"
    response = requests.get(info_datos)
    datos = pd.read_excel(response.content)
    datos.to_csv("datos2.csv", index=False)
    return 0


def orden_datos():
    """
    Esta función se encarga de arreglar el csv con el nombre
    datos2.csv ya que el original tiene filas que no contribuyen
    al análisis que se desea realizar. Por eso es que se saltan las
    primeras 9 filas del datos2.csv. También se elimina la fila 0, ya
    que posee nombres que se generaron una vez que se pasó de xls a csv.
    Se encontró columnas Nan, por lo que también se eliminaron.

    Parameters
    -----------
    aux : lee el csv que se creó al inicio. Luego, elimina las celdas con
    títulos sin nombre.
    temp : lee el csv recientemente creado y se eliminan las celdas con
    valores Nan. Luego se hace un reemplazo de la hora que muestra cada año
    por un espacio en blanco. Finalmente, se guarda el csv.

    Returns
    --------
    Guarda el csv con el formato deseado.
    """
    aux = pd.read_csv("datos2.csv")
    aux = aux.drop([0])
    aux.to_csv("datos.csv", index=False)
    temp = pd.read_csv("datos.csv", skiprows=range(9))
    # Con esto quito los Nan.
    temp = temp.dropna()
    # Se quita 00:00:00 a la columna Month.
    temp["Month"] = temp["Month"].str.replace(" 00:00:00", "")
    temp.to_csv("orden_datos.csv")
    return 0


def stats_energy(period, source_electric):
    """
    Esta función filtra el periodo del csv y el nombre del recurso de
    generación neta de electricidad. Entonces primero se accede al csv y
    se ubica el periodo de interés, así como el recurso del sector. Hecho
    esto se procede a calcular la media de cierto periodo. También se con-
    sidera la excepción de que si el usuario escribe ya sea el año o el
    nombre del recurso de generación de electricidad mal, si esto sucede
    entonces habrá un try-except de tipo Keyerror que ayudará a atrapar esta
    excepción.

    Parameters
    ----------
    temp_2 : lee el csv ordenado.
    filtered_data : selecciona la columna Month y el recurso del
    sector.
    mean_value : calcula la media de los datos selccionados.
    Returns
    -------
    mean_value : la media de cierto periodo en cierto sector.
    """
    try:
        temp_2 = pd.read_csv("orden_datos.csv")
        filtered_data = temp_2.loc[
            temp_2["Month"].str.startswith(period), [source_electric]
        ]
        mean_value = filtered_data[source_electric].mean()
        return mean_value
    except KeyError:
        print('El año o el recurso de generación no existen en el csv.')
        return None
    return 0

def stats2_energy(period, source_electric):
    """
    Esto es una función similar a la anterior, lo único que cambia
    es que aquí se calcula la autocorrelación. Similar a la función
    anterior, se implementa una try-except de tipo Keyerror para a-
    trapar la excepción de tipo Keyerror.

    Parameters
    ----------
    temp_2 : lee el csv ordenado.
    filtered_data : selecciona la columna Month y el recurso del
    sector.
    auto_value : calcula la media de los datos selccionados.
    Returns
    -------
    auto_value : la autocorrelación de los datos especificados.
    """
    try:
        temp_2 = pd.read_csv("orden_datos.csv")
        filtered_data = temp_2.loc[
            temp_2["Month"].str.startswith(period), [source_electric]
        ]
        auto_value = filtered_data[source_electric].autocorr()
        return auto_value
    except KeyError:
        print('El año o el recurso de generación no existen en el csv.')
        return None


def stats3_energy(period, source_electric):
    """
    Esto es una función similar a la anterior, lo único que cambia
    es que aquí se calcula la desviación estándar. Similar a la función
    anterior, se implementa una try-except de tipo Keyerror para a-
    trapar la excepción de tipo Keyerror.

    Parameters
    ----------
    temp_2 : lee el csv ordenado.
    filtered_data : selecciona la columna Month y el recurso del
    sector.
    std_value : calcula la media de los datos selccionados.
    Returns
    -------
    std_value : la desviación estándar de los datos especificados.
    """
    try:
        temp_2 = pd.read_csv("orden_datos.csv")
        filtered_data = temp_2.loc[
            temp_2["Month"].str.startswith(period), [source_electric]
        ]
        std_value = filtered_data[source_electric].std()
        return std_value
    except KeyError:
        print('El año o el recurso de generación no existen en el csv.')
        return None


def exp_analysis():
    """
    Esta función toma 3 periodos de años 75, 90 y 2000
    para mostrar la tendencia que tienen estos datos una
    vez que se les aplique la función anterior, es decir,
    la obtención de la media. Por este motivo es que primero
    se definen los periodos, y en un arreglo se van guardando
    por medio de un ciclo for y el uso de append. Luego, se com-
    binan todos los datos (periodos y medias) para obtener una-
    tendencia general del comportamiento por medio de un gráfico
    de barras.
    Parameters
    -----------
    period_seventy : años setentas.
    period_ninety : años noventas.
    period_twothou : segundo milenio.
    values_seventy : lista que guarda las medias de los años
    setentas.
    values_ninety : lista que guarda las medias de los años
    noventas.
    values_twothou : lista que guarda las medias de los añosß
    dos mil.
    Returns
    --------
    Las medias de todos los años seleccionados y un gráfico de
    barras con su tendencia.
    """
    period_seventy = ["1973", "1974", "1975", "1976", "1977", "1978"]
    period_ninety = ["1990", "1991", "1992", "1993", "1994", "1995"]
    period_twothou = ["2000", "2001", "2002", "2003", "2004", "2005"]
    values_seventy = []
    values_ninety = []
    values_twothou = []

    for i in period_seventy:
        mean_value = stats_energy(
            i, "Electricity Net Generation From Natural Gas, All Sectors"
        )
        values_seventy.append(mean_value)

    for j in period_ninety:
        mean_value = stats_energy(
            j, "Electricity Net Generation From Natural Gas, All Sectors"
        )
        values_ninety.append(mean_value)

    for k in period_twothou:
        mean_value = stats_energy(
            k, "Electricity Net Generation From Natural Gas, All Sectors"
        )
        values_twothou.append(mean_value)
    periods = period_seventy + period_ninety + period_twothou
    values = values_seventy + values_ninety + values_twothou
    poly_general = np.polyfit(range(len(periods)), values, 2)
    plt.bar(period_seventy, values_seventy, label="1973-1978", color="cyan")
    plt.bar(period_ninety, values_ninety, label="1990-1995", color="peru")
    plt.bar(period_twothou, values_twothou, label="2000-2005", color="lime")
    plt.plot(
        np.arange(len(periods)),
        np.polyval(poly_general, np.arange(len(periods))),
        color="red",
        linestyle="dashdot",
    )
    plt.xlabel("Years")
    plt.ylabel("Means")
    plt.title("Electricity Net Generation From Natural Gas, All Sectors")
    plt.legend()
    plt.show()
    return 0


def pearson_val(source_elec_1, source_elec_2):
    """
    Esta función se encarga de calcular el coeficiente de correlación
    de Pearson.Se trabaja diferente con respecto a los cálculos
    anteriores, por eso primero se lee el csv ordenado, luego por
    medio de una variable se toma el año y con el comando corr, se
    selecciona el recurso del sector a estudiar. Y de esa manera se
    logra obtener el coeficiente. Ahora, revisando los datos del csv
    ordenado se observó que hay datos en las columnas con el nombre:
    Not Available, por lo que no será posible hacer un análisis de
    esos valores, por tanto, esto genera una excepción, así, hace uso
    del try-except para atrapar esta excepción correctamente.
    Parameters
    ----------
    temp_2 : lee el csv ordenadpo.
    pearson_coefficient : calcula el coeficiente de todo un año para
    cierto sector.
    Returns
    -------
    El coeficiente de Pearson de un año con base a cierto sector
    carbón, solar, viento, etc.
    """
    try:
        temp_2 = pd.read_csv("orden_datos.csv")
        pearson_coeficient = temp_2[source_elec_1].corr(temp_2[source_elec_2])
        print("Coeficiente de Pearson es:", pearson_coeficient)
        return pearson_coeficient
    except TypeError as error:
        print("No se puede calcular el coeficiente, hay datos incompatibles.")
        print("Tipo de error:", error)
        return None


def pie_analysis():
    """
    En esta función se realiza un diagrama tipo pastel.
    Similar a las funciones anteriores, se define un periodo,
    luego unas listas que por medio de un ciclo for se va guar-
    dando los valores de las desviaciones estandar de cada uno
    de estos valores. Después se realizan las configuraciones
    o más bien se agregan los detalles del diagrama, en ese sen-
    tido, etiquetas, tamaños, color, y otra opción que se llama
    explode, aquí es para destacar cierto valor de interés. Fina-
    lmente con un subplots se logra dibujar los dos diagramas en
    una sola figura, donde se realizará el respectivo análisis.
    Parameters
    ----------
    period_eighty : periodo de los 80's.
    period_twothou : periodo de los 20's.
    values_eighty : lista que guarda las desviaciones de los
    80's.
    values_twothou : lista que guarda las desviaciones de los
    20's.
    Returns
    --------
    Dos diagramas de pastel que contienen las desviaciones estandar
    de cierto periodo de estudio.
    """
    period_eighty = ["1983", "1984", "1985", "1986", "1987"]
    period_twothou = ["2003", "2004", "2005", "2006", "2007"]
    values_eighty = []
    values_twothou = []

    for i in period_eighty:
        std_value = stats3_energy(
            i, "Electricity Net Generation From Coal, All Sectors"
        )
        values_eighty.append(std_value)
    for j in period_twothou:
        std_value = stats3_energy(
            j, "Electricity Net Generation From Coal, All Sectors"
        )
        values_twothou.append(std_value)

    labels = ["1983", "1984", "1985", "1986", "1987"]
    sizes = np.array(values_eighty)
    colors = ["gold", "yellowgreen", "sienna", "pink", "navy"]
    explode = (0.1, 0, 0, 0, 0)  # explode 1st slice

    labels_2 = ["2003", "2004", "2005", "2006", "2007"]
    sizes_2 = np.array(values_twothou)
    colors_2 = ["purple", "lime", "cyan", "firebrick", "springgreen"]
    explode_2 = (0.1, 0, 0, 0, 0)  # explode 1st slice
    fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(10, 5))

    # Gráfico de pastel 1
    ax1.pie(
        sizes,
        explode=explode,
        labels=labels,
        colors=colors,
        autopct="%1.1f%%",
        shadow=True,
        startangle=140,
    )
    ax1.set_title("Periodo 1980")

    # Gráfico de pastel 2
    ax2.pie(
        sizes_2,
        explode=explode_2,
        labels=labels_2,
        colors=colors_2,
        autopct="%1.1f%%",
        shadow=True,
        startangle=140,
    )
    ax2.set_title("Periodo 2000")

    plt.axis("equal")
    plt.tight_layout()
    plt.show()
    return 0


def scatter_analysis():
    """
    En esta función se implementa un diagrama de dispersión
    con base a la autocorrelación de los años 2011-2021 en un
    periodo de 10 años. Así, con un loop for se recorren los años
    seleccionados y se guardan en una lista para luego graficarlos.
    Parameters
    ----------
    period_twothousands : periodo de años.
    values_twothousands : lista que guarda las autocorrelaciones de
    cada año.
    Returns
    --------
    Diagrama de dispersión con las autocorrelaciones de los años
    en estudio.
    """
    period_twothousands = [
        "2011",
        "2012",
        "2013",
        "2014",
        "2015",
        "2016",
        "2017",
        "2018",
        "2019",
        "2020",
        "2021",
        "2022",
    ]
    values_twothousands = []
    for i in period_twothousands:
        auto_value = stats2_energy(
            i,
            "Electricity Net Generation Total (including from sources not shown), All Sectors",
        )
        values_twothousands.append(auto_value)
    plt.scatter(period_twothousands, values_twothousands)
    plt.xlabel("Years")
    plt.ylabel("Autocorrelation")
    plt.show()
    return 0

