INSTALL_DIR=/usr/bin # you can change this to your liking

CXX=g++
CXXFLAGS=-Wall -Werror -Iinclude/ `pkg-config gtkmm-3.0 --cflags --libs`

all: wavecmp

.PHONY: clean
clean:
	rm -rf *.o
	rm -rf *.exe
	rm -rf wavecmp
  
wavecmp: src/wavecmp.cpp src/func.cpp
	$(CXX) src/wavecmp.cpp -c -o wavecmp.o $(CXXFLAGS)
	$(CXX) src/func.cpp -c -o func.o $(CXXFLAGS)
	$(CXX) wavecmp.o func.o -o wavecmp $(CXXFLAGS)
  
install: wavecmp
	cp wavecmp $(INSTALL_DIR)/wavecmp
