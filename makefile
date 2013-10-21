CC=g++
CFLAGS=-I.
DEPS = ddig.h fatheader.h

OBJ = ddig.o fatheader.o

LIBS=-lboost_filesystem -lboost_iostreams

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

ddig: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

clean:
	rm -f *.o ddig
