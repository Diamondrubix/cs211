program5: main.o arrayListMine.o myfunc.o
	g++ -o program5 main.cpp arrayListMine.o myfunc.o

main.o: main.cpp myfunc.h
	g++ -c main.cpp

arrayListMine.o: arrayListMine.cpp arrayListMine.h
	g++ -c arrayListMine.cpp

myfunc.o: myfunc.cpp myfunc.h
	g++ -c myfunc.cpp

clean:
	rm myfunc.o arrayListMine.o program5

