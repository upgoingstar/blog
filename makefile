CC = g++
CPPFLAGS = -std=c++11 -O2 -Wall -g
LIBS=-lm

%.o: %.cpp domains.hpp entity.hpp model.hpp view.hpp stubs.hpp controller.hpp
	@echo Compilando arquivo objeto: $@
	@$(CC) -c -o $@ $< $(CPPFLAGS)

blog: domains.o entity.o model.o view.o stubs.o controller.o main.o
	@echo Compilando todos os arquivos objetos...
	@$(CC) -o $@ $^ $(CPPFLAGS) $(LIBS)

all: blog clean

.PHONY: clean

clean:
	@echo Cleaning directory...
	@rm *.o
