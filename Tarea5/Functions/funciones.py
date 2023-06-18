import pandas as pd
import requests


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


def mean_Energy(period, source_Electric):
    temp_2 = pd.read_csv('orden_datos.csv')
    # Filtrar por cualquier año y la columna específica
    filtered_data = temp_2.loc[temp_2['Month'].str.startswith(period), [source_Electric]]

    # Calcular la media de los datos.
    mean_value = filtered_data[source_Electric].mean()

    return mean_value
