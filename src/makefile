IDIR = ../hdr
DIR = ../src
ODIR = obj
CC = g++
CPPFLAGS = -std=c++11 -O2 -Wall -I$(IDIR)

LIBS=-lm

_DEPS = domains.hpp entities.hpp test_domains.hpp test_entities.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o domains.o entities.o test_domains.o test_entities.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	@echo Compilando arquivo objeto: $@
	@$(CC) -c -o $@ $< $(CPPFLAGS)

blog: $(OBJ)
	@echo Compilando todos os arquivos objetos...
	@$(CC) -o $@ $^ $(CPPFLAGS) $(LIBS)

all: blog clean

.PHONY: clean

clean:
	@echo Cleaning directory...
	@rm $(ODIR)/*.o
