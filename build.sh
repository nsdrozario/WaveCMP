# can't figure out autotools so this is the solution for the time being

g++ -c src/wavecmp.cpp -o wavecmp.o -Iinclude/ `pkg-config gtkmm-3.0 --cflags --libs`
g++ -c src/func.cpp -o func.o -Iinclude/
g++ wavecmp.o func.o `pkg-config gtkmm-3.0 --cflags --libs`