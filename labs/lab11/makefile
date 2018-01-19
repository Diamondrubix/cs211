lab11: lab11.o Point2d.o
	g++ -o lab11 lab11.o Point2d.o

lab11.o: lab11.cpp Point2d.h
	g++ -c lab11.cpp

Point2d.o: Point2d.cpp Point2d.h
	g++ -c Point2d.cpp

clean:
	rm lab11.o Point2d.o lab11
