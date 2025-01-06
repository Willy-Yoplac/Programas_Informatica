'open model.ctl'
'set display color white'
'c'
'set grads off'; 'set grid off'
*lowres mres hires
'set mpdset lowres'; 'set map 1 1 1'
** Define colores *****
'define_colors.gs'
********
'set gxout shaded'; 
'set clevs -5  0 5 10 15 18 20 25 30 35'                      
'set ccols 36 37 38 39 41 42 43 44 45 46 47'
'd tsfc -273'
** contornos *********
'set gxout contour'; 'set clab masked'; 'set ccolor 0'
'set clevs -5  0 5 10 15 18 20 25 30 35'                      
'd tsfc -273'

'cbarn'
'printim color1.png'
'!display color1.png &'

**********
