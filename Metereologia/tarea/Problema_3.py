from scipy.interpolate import lagrange

z = [0.5,1.0,2.0,5.0]
u = [2.1,2.4,2.7,3.0]

p = lagrange(z,u)

print('\n(a) La velocidad del viento a una altura de z = 0 m es u_0 = ' + str(round(p(0),4)) + '.')
print('(b) La velocidad del viento a una altura de z = 3 m es u_3 = ' + str(round(p(3),4)) + '.')
print('(c) La velocidad del viento a una altura de z = 10 m es u_10 = ' + str(round(p(10),4)) + '.\n')