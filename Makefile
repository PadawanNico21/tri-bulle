build:
	gcc -Wall -g tribulle.c -o tribulle

test: default
	./tribulle

clean:
	rm tribulle
