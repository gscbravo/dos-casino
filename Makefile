all: build

build:
	gcc -o casino casino.c -Wall -lncursesw

