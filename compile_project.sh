# help me please

g++ src/wavecmp.cpp -c -o wavecmp.o -Iinclude/ `pkg-config gtkmm-3.0 --cflags --libs`
g++ src/func.cpp -c -o func.o -Iinclude/
g++ wavecmp.o func.o wavecmp `pkg-conifg gtkmm-3.0 --cflags --libs`

