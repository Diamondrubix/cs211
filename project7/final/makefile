GridMain:  GridMain.cpp GridDisplay.o creature.o doodlebug.o ant.o dynamicList.h
	g++ -o GridMain GridMain.cpp GridDisplay.o creature.o doodlebug.o ant.o


GridDisplay.o: GridDisplay.cpp GridDisplay.h
	g++ -c GridDisplay.cpp

creature.o: creature.cpp creature.h
	g++ -c creature.cpp

doodlebug.o: doodlebug.cpp doodlebug.h
	g++ -c doodlebug.cpp

ant.o: ant.cpp ant.h
	g++ -c ant.cpp


clean:
	rm -f *.o GridMain
