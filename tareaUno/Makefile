CAMPUS_SRC = campus.cpp
FINCA_SRC = finca.cpp
EDIFICIO_SRC = edificio.cpp
MAIN_SRC = main.cpp

TARGET = exe
all: $(CAMPUS_SRC) $(FINCA_SRC) $(EDIFICIO_SRC) $(MAIN_SRC)
	g++ $(CAMPUS_SRC) $(FINCA_SRC) $(EDIFICIO_SRC) $(MAIN_SRC) -o $(TARGET)

run: all
	./$(TARGET)
