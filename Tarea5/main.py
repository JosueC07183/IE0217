from Functions import funciones

# Análisis de datos con generación neta: Gas natural
mostrar_Info = funciones.llamado_datos()
orden_Info = funciones.orden_Datos()
bars = funciones.exp_analysis()
CoefPearson = funciones.pearson_Val('Electricity Net Generation From Natural Gas, All Sectors', 'Electricity Net Generation From Geothermal, All Sectors')

# Análisis de datos con generación neta: Carbón.
mostrar_Info_2 = funciones.pie_Analysis()
