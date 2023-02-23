bin/main: bin/main.o bin/quicksort.o bin/helperADT.o
    gcc -o bin/main bin/main.o bin/quicksort.o bin/helperADT.o
bin/main.o: main.c quicksort.h
    gcc -c main.c -o bin/main.o
bin/quicksort.o: quicksort.c quicksort.h helper.h
    gcc -c quicksort.c -o bin/quicksort.o
bin/helperADT.o: helperADT.c helper.h
    gcc -c helperADT.c -o bin/helperADT.o

