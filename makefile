all: testegera.c gera.c
	gcc -Wall -Wa,--execstack -o testegera testegera.c gera.c
	./testegera

teste: teste.c
	gcc -c teste.c
	objdump -d teste.o
