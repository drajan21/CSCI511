all: stamp

stamp: stamp.o stampbuf.o stampstream.o
	g++ stamp.o stampbuf.o stampstream.o -o stamp

stamp.o: stamp.cpp stamp.h
	g++ -c stamp.cpp stamp.h

stampbuf.o: stampbuf.cpp stampbuf.h
	g++ -c stampbuf.cpp stampbuf.h

stampstream.o: stampstream.cpp
	g++ -c stampstream.cpp
	  
clean:
	rm *.o stamp
