build:
	gcc -Wall -g tribulle.c -o tribulle

test: build
	./tribulle

clean:
	rm tribulle
