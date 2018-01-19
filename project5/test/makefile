max: max1.o max2.o
	g++ -o max max1.o max2.o

max1.o: max1.cpp max.h
	g++ -c max1.cpp

max2.o: max2.cpp max.h
	g++ -c max2.cpp

clean:
	rm max1.o max2.o  max
