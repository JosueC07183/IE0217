import pandas as pd
import requests
import matplotlib.pyplot as plt
import numpy as np


def llamado_datos():
    info_Datos = 'https://www.eia.gov/totalenergy/data/browser/xls.php?tbl=T07.02A'
    response = requests.get(info_Datos)
    df = pd.read_excel(response.content)
    df.to_csv('datos2.csv', index=False)


def orden_Datos():
    aux = pd.read_csv('datos2.csv')
    aux = aux.drop([0])
    aux.to_csv('datos.csv', index=False)
    temp = pd.read_csv('datos.csv', skiprows=range(9))
    # Con esto quito los Nan.
    temp = temp.dropna()
    # Se quita 00:00:00 a la columna Month.
    temp['Month'] = temp['Month'].str.replace(' 00:00:00', '')
    temp.to_csv('orden_datos.csv')


def stats_Energy(period, source_Electric):
    temp_2 = pd.read_csv('orden_datos.csv')
    # Filtrar por cualquier año y la columna específica
    filtered_data = temp_2.loc[temp_2['Month'].str.startswith(period), [source_Electric]]

    # Calcular la media de los datos.
    mean_value = filtered_data[source_Electric].mean()
    std_value = filtered_data[source_Electric].std()
    auto_value = filtered_data[source_Electric].autocorr()
    var = filtered_data[source_Electric].var()
    return mean_value
    # print("Media del año", period, "por", source_Electric, "es:", mean_value)
    # print("Desviación estándar del", period, "por", source_Electric, "es:", std_value)
    # print("Autocorrelación del", period, "por", source_Electric, "es:", auto_value)
    # print("Varianza del", period, "por", source_Electric, "es:", var)


def exp_analysis():
    period_seventy = ["1973", "1974", "1975", "1976", "1977", "1978"]
    period_ninety = ["1990", "1991", "1992", "1993", "1994", "1995"]
    period_twothou = ["2000", "2001", "2002", "2003", "2004", "2005"]
    values_seventy = []
    values_ninety = []
    values_twothou = []

    for i in period_seventy:
        mean_value = stats_Energy(i, "Electricity Net Generation From Natural Gas, All Sectors")
        values_seventy.append(mean_value)

    for j in period_ninety:
        mean_value = stats_Energy(j, "Electricity Net Generation From Natural Gas, All Sectors")
        values_ninety.append(mean_value)

    for k in period_twothou:
        mean_value = stats_Energy(k, "Electricity Net Generation From Natural Gas, All Sectors")
        values_twothou.append(mean_value)

    # Combinar todos los datos
    periods = period_seventy + period_ninety + period_twothou
    values = values_seventy + values_ninety + values_twothou

    # Calcular línea de tendencia general
    poly_general = np.polyfit(range(len(periods)), values, 2)

    # Graficar barras
    plt.bar(period_seventy, values_seventy, label='1973-1978', color='cyan')
    plt.bar(period_ninety, values_ninety, label='1990-1995', color='peru')
    plt.bar(period_twothou, values_twothou, label='2000-2005', color='lime')

    # Graficar línea de tendencia general
    plt.plot(np.arange(len(periods)), np.polyval(poly_general, np.arange(len(periods))), color='red', linestyle='dashdot')

    plt.xlabel('Years')
    plt.ylabel('Means')
    plt.title("Electricity Net Generation From Natural Gas, All Sectors")
    plt.legend()
    plt.show()


def pearson_Val(sourceElec_1, sourceElec_2):
    temp_2 = pd.read_csv('orden_datos.csv')
    pearson_coeficient = temp_2[sourceElec_1].corr(temp_2[sourceElec_2])

    print("Coeficiente de Pearson es:", pearson_coeficient)


def pie_Analysis():
    period_eighty = ["1983", "1984", "1985", "1986", "1987"]
    period_twothou = ["2003", "2004", "2005", "2006", "2007"]
    values_eighty = []
    values_twothou = []

    for i in period_eighty:
        mean_value = stats_Energy(i, "Electricity Net Generation From Coal, All Sectors")
        values_eighty.append(mean_value)
    for j in period_twothou:
        mean_value = stats_Energy(j, "Electricity Net Generation From Coal, All Sectors")
        values_twothou.append(mean_value)

    labels = ["1983", "1984", "1985", "1986", "1987"]
    sizes = np.array(values_eighty)
    colors = ['gold', 'yellowgreen', 'lightcoral', 'lightskyblue', 'green']
    explode = (0.1, 0, 0, 0, 0)  # explode 1st slice
    
    labels_2 = ["2003", "2004", "2005", "2006", "2007"]
    sizes_2 = np.array(values_twothou)
    colors_2 = ['purple', 'lime', 'cyan', 'blue', 'crimson']
    explode_2 = (0.1, 0, 0, 0, 0)  # explode 1st slice
    fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(10, 5))

    # Gráfico de pastel 1
    ax1.pie(sizes, explode=explode, labels=labels, colors=colors,
            autopct='%1.1f%%', shadow=True, startangle=140)
    ax1.set_title('Periodo 1980')

    # Gráfico de pastel 2
    ax2.pie(sizes_2, explode=explode_2, labels=labels_2, colors=colors_2,
            autopct='%1.1f%%', shadow=True, startangle=140)
    ax2.set_title('Periodo 2000')

    plt.axis('equal')
    plt.tight_layout()
    plt.show()



