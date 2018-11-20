
all: release

release:
	gcc main.c programa.c lecturaArchivo.c -o main

run:
	./main
