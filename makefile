hepsi: derle calistir

derle:
	gcc -I ./include/ -o ./lib/Canli.o -c ./src/Canli.c
	gcc -I ./include/ -o ./lib/bitki.o -c ./src/bitki.c
	gcc -I ./include/ -o ./lib/bocek.o -c ./src/bocek.c
	gcc -I ./include/ -o ./lib/pire.o -c ./src/pire.c
	gcc -I ./include/ -o ./lib/sinek.o -c ./src/sinek.c
	gcc -I ./include/ -o ./lib/CanliQueue.o -c ./src/CanliQueue.c
	gcc -I ./include/ -o ./bin/Test ./lib/bitki.o ./lib/bocek.o ./lib/pire.o ./lib/sinek.o ./lib/CanliQueue.o ./lib/Canli.o ./src/Test.c

calistir:
	./bin/Test





	
	