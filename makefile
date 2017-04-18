IDIR = hdr
DIR = src
ODIR = src
CC = g++
CPPFLAGS = -std=c++11 -O2 -Wall -I$(IDIR)

LIBS=-lm

_DEPS = domains.hpp entities.hpp
DEPS = $(patsubst %,$(DIR)/%,$(_DEPS))

_OBJ = main.o domains.o entities.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

# TODO: make this echo works
$(ODIR)/%.o: $*.cpp $(DEPS)
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
