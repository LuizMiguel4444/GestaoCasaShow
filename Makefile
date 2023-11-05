run: all
	./GestaoCasaShow

all:
	gcc -c -Wall atraction/atraction.c; 
	gcc -c -Wall aux/aux.c;
	gcc -c -Wall buy/buy.c;
	gcc -c -Wall client/client.c;
	gcc -c -Wall report/report.c;
	gcc -c -Wall show/show.c;
	gcc -c -Wall util/util.c;
	gcc -c -Wall main.c;
	gcc -o GestaoCasaShow *.o;

clean:
	rm *.o
	rm GestaoCasaShow
	rm atraction/*.dat
	rm buy/*.dat
	rm show/*.dat