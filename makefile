IDIR = hdr
DIR = src
CC = g++
CPPFLAGS = -std=c++11 -O2 -Wall -I$(IDIR)

ODIR=src

LIBS=-lm

_DEPS = domains.hpp entities.hpp
DEPS = $(patsubst %,$(DIR)/%,$(_DEPS))

_OBJ = entities.o domains.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $*.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CPPFLAGS)

blog: $(OBJ)
	$(CC) -o $@ $^ $(CPPFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm $(ODIR)/*.o *~ core $(INCDIR)/*~
