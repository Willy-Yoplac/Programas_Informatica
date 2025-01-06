from rich.console import Console
from rich.table import Table
from rich.align import Align
from math import sin,cos,pi

console = Console()

Velocidad = [4,8,12,16,20,30,12,16,20,30]
Direccion = [0,45,90,145,180,210,270,330,-60,-120]
Direccion_meteorologica = [round(i+180,2) for i in Direccion]
Zonal = list(map(lambda V,angulo : round(V*sin(angulo*pi/180),2),Velocidad,Direccion_meteorologica))
Meridional = list(map(lambda V,angulo : round(V*cos(angulo*pi/180),2),Velocidad,Direccion_meteorologica))

table = Table(title='\n[green]Cuadro 1: Componentes zonal y meridional del viento 📝')
table.add_column('Velocidad (kt)', justify='center', vertical='middle')
table.add_column('Dirección (°)', justify='center')
table.add_column('Dirección meteorológica (°)', justify='center')
table.add_column('[purple]Componente zonal (u)', style='purple bold', justify='center')
table.add_column('[cyan]Componente meridional (v)', style='cyan bold', justify='center')
for i in range(len(Velocidad)):
    table.add_row(str(Velocidad[i]), str(Direccion[i]), str(Direccion_meteorologica[i]),str(Zonal[i]), 
                  str(Meridional[i]), end_section=True)
table = Align.center(table,vertical='middle')
console.print(table)