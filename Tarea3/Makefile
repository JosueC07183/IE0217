EXECUTABLE = exe

all: doxygen build run

doxygen:
	doxygen -g
	doxygen

build:
	g++ funciones.cpp main.cpp -o $(EXECUTABLE)

run:
	open html/index.html
	
	./$(EXECUTABLE)