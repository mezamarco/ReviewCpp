all: mainexe ioexe

mainexe: main.cpp
	g++ main.cpp -o executable

ioexe: ioexamples.cpp
	g++ ioexamples.cpp -o ioexecutable  


clean: 
	rm executable ioexecutable

