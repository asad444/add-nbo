#Makefile

add-nbo: add-nbo.o
	g++ -o add-nbo add-nbo.cpp

add-nbo.o: add-nbo.cpp

clean:
	rm add-nbo
	rm *.o
