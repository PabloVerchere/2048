# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -Wall

# Default target
all: bin/Txt



obj/empty_txt.o: src/tile/txt/empty_txt.cpp src/tile/txt/empty_txt.h
	g++ -fPIE -c -o obj/empty_txt.o src/tile/txt/empty_txt.cpp

obj/number_txt.o: src/tile/txt/number_txt.cpp src/tile/txt/number_txt.h
	g++ -fPIE -c -o obj/number_txt.o src/tile/txt/number_txt.cpp

obj/grid_txt.o: src/grid/txt/grid_txt.cpp src/grid/txt/grid_txt.h src/tile/txt/empty_txt.h
	g++ -fPIE -c -o obj/grid_txt.o src/grid/txt/grid_txt.cpp


obj/empty.o: src/tile/empty.cpp src/tile/empty.h
	g++ -fPIE -c -o obj/empty.o src/tile/empty.cpp

obj/number.o: src/tile/number.cpp src/tile/number.h
	g++ -fPIE -c -o obj/number.o src/tile/number.cpp

obj/tile.o: src/tile/tile.cpp src/tile/tile.h
	g++ -fPIE -c -o obj/tile.o src/tile/tile.cpp

obj/grid.o: src/grid/grid.cpp src/grid/grid.h src/tile/number.h
	g++ -fPIE -c -o obj/grid.o src/grid/grid.cpp


obj/main_txt.o: src/main_txt.cpp src/grid/txt/grid_txt.h
	g++ -fPIE -c -o obj/main_txt.o src/main_txt.cpp



bin/Txt: obj/empty_txt.o obj/number_txt.o obj/grid_txt.o obj/empty.o obj/number.o obj/tile.o obj/grid.o obj/main_txt.o
	g++ -pie -o bin/Txt obj/empty_txt.o obj/number_txt.o obj/grid_txt.o obj/empty.o obj/number.o obj/tile.o obj/grid.o obj/main_txt.o


# Clean up generated files
clean:
	rm -f obj/* bin/*

# Phony targets
.PHONY: all clean