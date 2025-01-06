import pandas as pd
import numpy as np
import matplotlib.cm as cm
from matplotlib import pyplot as plt
from windrose import WindroseAxes

df_0 = pd.read_excel('Data_CORPAC_0.xlsx')
print('\nLa data cargada original de la Estación CORPAC tiene ' + str(df_0.shape[0]) + ' registros:\n')
print(df_0)

df = pd.read_excel('Data_CORPAC.xlsx')
print('\nLa data cargada depurada de la Estación CORPAC tiene ' + str(df.shape[0]) + ' registros:\n')
print(df)

ax = WindroseAxes.from_ax()
ax.set_title('ROSA DE VIENTOS 1 - HISTOGRAMA APILADO NORMADO EN %\nESTACIÓN CORPAC: Enero, febrero y marzo de 2006 - Velocidad en nudos',
             loc = "Center", fontdict = {'fontsize':12, 'fontweight':'bold', 'color':'tab:blue'})
ax.bar(df.DIRECCION, df.VELOCIDAD, normed=True, opening=0.8, edgecolor='white')
ax.set_legend()

ax = WindroseAxes.from_ax()
ax.set_title('ROSA DE VIENTOS 2 - HISTOGRAMA APILADO NO NORMADO CON RANGOS\nESTACIÓN CORPAC: Enero, febrero y marzo de 2006 - Velocidad en nudos',
             loc = "Center", fontdict = {'fontsize':12, 'fontweight':'bold', 'color':'tab:blue'})
ax.box(df.DIRECCION, df.VELOCIDAD, bins=np.arange(0, 8, 1))
ax.set_legend()

ax = WindroseAxes.from_ax()
ax.set_title('ROSA DE VIENTOS 3 - CON RELLENO Y LÍNEAS DE CONTORNO\nESTACIÓN CORPAC: Enero, febrero y marzo de 2006 - Velocidad en nudos',
             loc = "Center", fontdict = {'fontsize':12, 'fontweight':'bold', 'color':'tab:blue'})
ax.contourf(df.DIRECCION, df.VELOCIDAD, bins=np.arange(0, 8, 1), cmap=cm.hot)
ax.contour(df.DIRECCION, df.VELOCIDAD, bins=np.arange(0, 8, 1), colors='black')
ax.set_legend()

plt.show()