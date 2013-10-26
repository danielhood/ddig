CC=g++-4.8.2

CFLAGS=-static -std=c++11

INCS=-I. -I/usr/local

OBJ=ddig.o fatheader.o

#LIBS=~/boost/stage/lib/libboost_filesystem.a ~/boost/stage/lib/libboost_iostreams.a
#LIBS=-L/home/dhood/boost/stage/lib -lboost_filesystem -lboost_iostreams

LIBS=-L/usr/local/boost/stage/lib -L/home/dhood/boost/stage/lib -lboost_filesystem -lboost_iostreams
#LIBS = /usr/local/boost/stage/lib/libboost_filesystem.a /usr/local/boost/stage/lib/libboost_iostreams.a

#.o: %.cc $(DEPS)
#	$(CC) $(INCS) -c -o $@ $< 

ddig: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

ddig.o: ddig.cc ddig.h fatheader.h
	$(CC) $(CFLAGS) $(INCS) -c -o $@ $<

fatheader.o: fatheader.cc fatheader.h
	$(CC) $(CFLAGS) $(INCS) -c -o $@ $<

clean:
	rm -f *.o ddig
