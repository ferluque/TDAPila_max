BIN=bin
SRC=src
INC=inc
OBJ=obj

$(BIN)/usopilas: $(OBJ)/usopilas_max.o
	g++ -g -o $@ $^ -I./$(INC)/ -I./$(SRC)/

$(OBJ)/usopilas_max.o: $(SRC)/usopilas_max.cpp
	g++ -g -c -o $@ $< -I./$(INC)/ -I./$(SRC)

all: clean $(BIN)/usopilas

clean:
	-rm -rf $(BIN)/* $(OBJ)/*

