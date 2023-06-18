import pandas as pd
import requests

url = 'https://www.eia.gov/totalenergy/data/browser/xls.php?tbl=T07.02A'
response = requests.get(url)

# Crear un objeto de pandas DataFrame con los datos del archivo de Excel
df = pd.read_excel(response.content)
# Guardar el archivo.
df.to_csv('datos2.csv', index=False)
aux = pd.read_csv('datos2.csv')
aux = aux.drop([0])
aux.to_csv('datos.csv', index=False)
# Salto las líneas que no sirven para el análisis.
temp = pd.read_csv('datos.csv', skiprows=range(9))
# Con esto quito los Nan.
temp = temp.dropna()
# Se quita 00:00:00 a la columna Month.
temp['Month'] = temp['Month'].str.replace(' 00:00:00', '')