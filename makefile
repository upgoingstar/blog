IDIR = ../hdr
DIR = ../src
CC = g++
CFLAGS = -std=c++11 -O2 -Wall -Wc++11-extensions -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused

ODIR=src

LIBS=-lm

_DEPS = domains.hpp entities.hpp
DEPS = $(patsubst %,$(DIR)/%,$(_DEPS))

_OBJ = entities.o domains.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $*.cpp $(DEPS)
	echo "<<<<<<<<<<<<<"
	$(CC) -c -o $@ $< $(CFLAGS)

blog: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm $(ODIR)/*.o *~ core $(INCDIR)/*~
