from rich.console import Console
from rich.table import Table
from rich.align import Align
from math import sin,cos,pi
import matplotlib.pyplot as plt
plt.style.use('dark_background')

console = Console()

Altitud = [22,1000,1500,2000,2500,3000,4000,5000,6000,7000,8000,9000,10000]
Direccion = [90,110,127,144,122,102,51,91,104,124,138,149,161]
Velocidad = [7,12,10,9,12,10,6,7,8,16,21,21,13]
Direccion_meteorologica = [round(i+180,2) for i in Direccion]
Zonal = list(map(lambda V,angulo : round(V*sin(angulo*pi/180),2),Velocidad,Direccion_meteorologica))
Meridional = list(map(lambda V,angulo : round(V*cos(angulo*pi/180),2),Velocidad,Direccion_meteorologica))

table = Table(title='\n[green]Cuadro 2: Componentes zonal y meridional del viento 📝')
table.add_column('Altitud (m)', justify='center', vertical='middle')
table.add_column('Dirección (°)', justify='center')
table.add_column('Velocidad (m/s)', justify='center', vertical='middle')
table.add_column('Dirección meteorológica (°)', justify='center')
table.add_column('[purple]Componente zonal (u)', style='purple bold', justify='center')
table.add_column('[cyan]Componente meridional (v)', style='cyan bold', justify='center')
for i in range(len(Altitud)):
    table.add_row(str(Altitud[i]),str(Direccion[i]), str(Velocidad[i]), str(Direccion_meteorologica[i]),str(Zonal[i]), 
                  str(Meridional[i]), end_section=True)
table = Align.center(table,vertical='middle')
console.print(table)
print('')

fig, (ax1,ax2) = plt.subplots(1,2)
fig.set_size_inches(12,8)

ax1.plot(Zonal, Altitud, marker='o', markerfacecolor = 'white', color = 'b')
ax1.set_title('PERFIL VERTICAL\nDE LA COMPONENTE ZONAL\nDE LA VELOCIDAD DEL VIENTO', loc = "Center", fontdict = {'fontsize':12, 'fontweight':'bold', 'color':'tab:blue'})
ax1.set_xlabel('Velocidad (m/s)', fontdict = {'fontsize':11, 'fontweight':'bold', 'color':'tab:blue'})
ax1.set_ylabel('Altitud (m)', fontdict = {'fontsize':11, 'fontweight':'bold', 'color':'tab:blue'})
ax1.grid(color='c', linestyle='-', linewidth=0.2)

ax2.plot(Meridional, Altitud, marker='o', markerfacecolor = 'white', color = 'r')
ax2.set_title('PERFIL VERTICAL\nDE LA COMPONENTE MERIDIONAL\nDE LA VELOCIDAD DEL VIENTO', loc = "Center", fontdict = {'fontsize':12, 'fontweight':'bold', 'color':'tab:blue'})
ax2.set_xlabel('Velocidad (m/s)', fontdict = {'fontsize':11, 'fontweight':'bold', 'color':'tab:blue'})
ax2.set_ylabel('Altitud (m)', fontdict = {'fontsize':11, 'fontweight':'bold', 'color':'tab:blue'})
ax2.grid(color='c', linestyle='-', linewidth=0.2)

plt.show()