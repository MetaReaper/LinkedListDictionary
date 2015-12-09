Main: LinkListDictionary.o main.o
	g++ LinkListDictionary.o main.o -o main

LinkListDictionary.o: LinkListDictionary.cpp LinkListDictionary.h
	g++ -g -c LinkListDictionary.cpp

main.o: main.cpp LinkListDictionary.h
	g++ -g -c main.cpp

Clear: rm *.o
