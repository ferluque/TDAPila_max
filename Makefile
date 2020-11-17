BIN=bin
SRC=src
INC=inc
OBJ=obj

$(BIN)/usopilas: $(OBJ)/usopilas.o $(OBJ)/Pila_max_vector.o
	g++ -g -o $@

