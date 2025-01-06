'set display color white'
'c'
'set grads off'
'set map 0 1 8'
'set lat -90 90'
'set lon -180 180'
'set mproj robinson'
'set gxout shaded'
'd tsfc -273'
*cbarn ancho inclinacion xi yi
*horizontal 0 ; vertical 1
'cbarn 2 0 5.5 0.5'
*'cbarc 10 7 0'
*'cbarc 10 7 0'
*'xcbar.gs 1 8 2 3 -dir h'
'printim robinson.png'
'!display robinson.png &'


