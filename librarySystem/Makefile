lib_search: Main.o Media.o Book.o Film.o Video.o Periodical.o SearchEngine.o
	g++ Main.o Media.o Book.o Film.o Video.o Periodical.o SearchEngine.o -o lib_search

Main.o: Main.cpp Media.h SearchEngine.h
	g++ -c Main.cpp

Media.o: Media.cpp Media.h
	g++ -c Media.cpp

Book.o: Book.cpp Book.h
	g++ -c Book.cpp
                                    
Film.o: Film.cpp Film.h
	g++ -c Film.cpp
                                                                 
Video.o: Video.cpp Video.h
	g++ -c Video.cpp

Periodical.o: Periodical.cpp Periodical.h
	g++ -c Periodical.cpp

SearchEngine.o: SearchEngine.cpp SearchEngine.h Media.h Book.h Film.h Video.h Periodical.h
	g++ -c SearchEngine.cpp
