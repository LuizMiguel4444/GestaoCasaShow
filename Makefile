run: all
	./GestaoCasaShow

all:
	gcc -c -Wall */*.c main.c;
	gcc -o GestaoCasaShow *.o;
	rm *.o

clean:
	rm GestaoCasaShow

rm:
	rm atraction/*.dat
	rm buy/*.dat
	rm show/*.dat