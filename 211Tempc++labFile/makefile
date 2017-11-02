program4: main.o interactions.o myImplementedCode.o
	gcc -o program4 main.o interactions.o myImplementedCode.o

main.o: main.c program4Header.h
	gcc -c main.c

interactions.o: interactions.c program4Header.h
	gcc -c interactions.c

myImplementedCode.o: myImplementedCode.c program4Header.h
	gcc -c myImplementedCode.c

clean:
	rm main.o interactions.o myImplementedCode.o program4
