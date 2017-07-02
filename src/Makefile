IDIR=.
CC=$(CROSS_COMPILE)gcc
CFLAGS=-I$(IDIR) -Wall -Wwrite-strings -Wpointer-arith -Winline -Wcast-qual -fno-strict-aliasing -Wshadow -Wnested-externs -Wmissing-declarations -Waggregate-return
ODIR=.
LDIR=.

LIBS=

_DEPS = include.h

DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o bitwise.o sorting.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

cractice: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f cractice $(ODIR)/*.o *~ core $(INCDIR)/*~ 
