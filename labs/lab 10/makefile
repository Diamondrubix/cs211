lab10: lab10Main.o lab10List.o
	g++ -o lab10 lab10Main.o lab10List.o

lab10Main.o: lab10Main.cpp lab10List.h
	g++ -c lab10Main.cpp

lab10List.o: lab10List.cpp lab10List.h
	g++ -c lab10List.cpp

clean:
	rm lab10*.o lab10
