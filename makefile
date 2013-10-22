CC=g++-4.8.2
CFLAGS=-I.
DEPS = ddig.h fatheader.h

OBJ = ddig.o fatheader.o

#LIBS=~/boost/stage/lib/libboost_filesystem.a ~/boost/stage/lib/libboost_iostreams.a
LIBS=-L/home/dhood/boost/stage/lib -lboost_filesystem -lboost_iostreams -static

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

ddig: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

clean:
	rm -f *.o ddig
