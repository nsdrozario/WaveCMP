# In my opinion this project doesn't even need a makefile
# this script assumes you are in the root directory of this repository

g++ src/wavecmp.cpp -c -o func.o -Iinclude/
g++ src/func.cpp -c -o wavecmp.o -Iinclude/
g++ wavecmp.o func.o -o wavecmp.exe