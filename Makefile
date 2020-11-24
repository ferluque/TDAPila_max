BIN=bin
SRC=src
INC=inc
OBJ=obj
GCCFLAGS=-DCUAL_COMPILA=2

$(BIN)/usopilas: $(OBJ)/usopilas_max.o
	g++ -g -o $@ $^ -I./$(INC)/ -I./$(SRC)/ $(GCCFLAGS)

$(OBJ)/usopilas_max.o: $(SRC)/usopilas_max.cpp
	g++ -g -c -o $@ $< -I./$(INC)/ -I./$(SRC) $(GCCFLAGS)

all: clean $(BIN)/usopilas

clean:
	-rm -rf $(BIN)/* $(OBJ)/*

