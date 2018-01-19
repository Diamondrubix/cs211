program6: main.o dynamicArray.o airport.o myNode.o
	g++ -o program6 main.cpp dynamicArray.o airport.o myNode.o

main.o: main.cpp airport.h
	g++ -c main.cpp

dynamicArray.o: dynamicArray.cpp dynamicArray.h
	g++ -c dynamicArray.cpp

airport.o: airport.cpp airport.h
	g++ -c airport.cpp

myNode.o: myNode.cpp airport.h
	g++ -c myNode.cpp

clean:
	rm myfunc.o dynamicArray.o program6
