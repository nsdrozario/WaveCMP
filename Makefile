INSTALL_DIR=/usr/bin # you can change this to your liking

.PHONY: clean
CXX=g++
CXXFLAGS=-Wall -Werror -Iinclude `pkg-config gtkmm-3.0 --cflags`
LIBS=`gtkm--3.0 --libs`

clean:
  rm -rf *.o
  rm -rf *.exe
  rm -rf wavecmp
  
wavecmp: src/wavecmp.cpp src/func.cpp
  $(CXX) src/wavecmp.cpp -c -o wavecmp.o $(CXXFLAGS)
  $(CXX) src/func.cpp -c -o func.o $(CXXFLAGS)
  $(CXX) wavecmp.o func.o $(LIBS) -o wavecmp
  
install: wavecmp
  cp wavecmp $(INSTALL_DIR)/wavecmp
