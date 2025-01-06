import matplotlib.pyplot as plt
plt.style.use('dark_background')

D = [90,110,127,144,122,102,51,91,104,124,138,149,161]
V = [7,12,10,9,12,10,6,7,8,16,21,21,13]
z = [22,1000,1500,2000,2500,3000,4000,5000,6000,7000,8000,9000,10000]

fig, (ax1,ax2) = plt.subplots(1,2)
fig.set_size_inches(12,8)

ax1.plot(D, z, marker='o', markerfacecolor = 'white', color = 'b')
ax1.set_title('PERFIL VERTICAL DE DIRECCIÓN\nDEL VIENTO', loc = "Center",
              fontdict = {'fontsize':12, 'fontweight':'bold', 'color':'tab:blue'})
ax1.set_xlabel('Dirección (°)', fontdict = {'fontsize':11, 'fontweight':'bold', 'color':'tab:blue'})
ax1.set_ylabel('Altitud (m)', fontdict = {'fontsize':11, 'fontweight':'bold', 'color':'tab:blue'})
ax1.grid(color='c', linestyle='-', linewidth=0.2)

ax2.plot(V, z, marker='o', markerfacecolor = 'white', color = 'r')
ax2.set_title('PERFIL VERTICAL DE VELOCIDAD\nDEL VIENTO', loc = "Center",
              fontdict = {'fontsize':12, 'fontweight':'bold', 'color':'tab:blue'})
ax2.set_xlabel('Velocidad (m/s)', fontdict = {'fontsize':11, 'fontweight':'bold', 'color':'tab:blue'})
ax2.set_ylabel('Altitud (m)', fontdict = {'fontsize':11, 'fontweight':'bold', 'color':'tab:blue'})
ax2.grid(color='c', linestyle='-', linewidth=0.2)

plt.show()