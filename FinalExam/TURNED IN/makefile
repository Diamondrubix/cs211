aarato2exam2: main.o dynamicList.o
	g++ -o aarato2exam2 main.o dynamicList.o

main.o: main.cpp dynamicList.h
	g++ -c main.cpp

dynamicList.o: dynamicList.cpp dynamicList.h
	gcc -c dynamicList.cpp

clean:
	rm -f *.o aarato2exam2
