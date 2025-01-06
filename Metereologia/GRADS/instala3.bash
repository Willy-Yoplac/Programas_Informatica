#!/bin/bash
DIRT=`pwd` ; echo $DIRT # $HOME/grads-install
cd $HOME
if [ -d GRADS ]; then
echo "El directorio existe"
echo "renombre el directorio para instalar GrADS "
echo "exit" 
 exit 1;
else 
 mkdir GRADS
fi
cd $DIRT
cp -rf $DIRT/source/grads-2.0.2.oga.2-bundle-x86_64-unknown-linux-gnu.tar.gz $HOME/GRADS
##cp -rf $DIRT/source/opengrads-2.2.1.oga.1-bundle-x86_64-pc-linux-gnu-glibc_2.12.tar.gz  $HOME/GRADS
cp -rf $DIRT/source/wgrib2.tgz $HOME/GRADS
cd $HOME/GRADS 
tar xzvf grads-2.0.2.oga.2-bundle-x86_64-unknown-linux-gnu.tar.gz
##tar xzvf opengrads-2.2.1.oga.1-bundle-x86_64-pc-linux-gnu-glibc_2.12.tar.gz
tar xzvf wgrib2.tgz
mv  grads-2.0.2.oga.2  opengrads
##mv opengrads-2.2.1.oga.1 opengrads

cd $HOME/GRADS/grib2
# Instalar WGRIB2 en   Bash: https://www.cpc.ncep.noaa.gov/products/wesley/wgrib2/compile_questions.html
     export COMP_SYS=gnu_linux
     export CC=gcc
     export FC=gfortran
     make
     make lib   
# Instalar en CSH                     only if you want the ftn_api
#    Csh
#      setenv CC gcc
#      setenv FC gfortran
#      make
#      make lib                        only if you want the ftn_api
# See if wgrib2 was compiled
#     ./wgrib2/wgrib2 -config



cd $HOME
sed '/HOME\/GRADS/d' .bashrc >  tmp.bashrc
mv tmp.bashrc .bashrc
#echo  export HELP_DIR=/home/miguel/gg/GRADS >> .bashrc
echo 'export PATH=$PATH:$HOME/GRADS/opengrads/Contents' 		   	>> .bashrc 
echo 'export PATH=$PATH:$HOME/GRADS/opengrads/Contents/Resources/scripts'  	>> .bashrc
echo 'export PATH=$PATH:$HOME/GRADS/grib2/wgrib2'  				>> .bashrc





