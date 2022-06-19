BIN=trabalho05

#pega todos os .c e .h
C_SOURCE=$(wildcard *.c)
H_SOURCE=$(wildcard *.h)

#Arquivos 
OBJ=$(C_SOURCE:.c=.o)

CC=gcc

#Flags para compilador
CC_FLAGS=-c -Wall -pedantic-errors

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) -o $@ $^

%.o: %.c %.h
	$(CC) -o $@ $< $(CC_FLAGS)

clean:
	rm -rf *.o $(BIN) *~
	
run:
	./trabalho05
