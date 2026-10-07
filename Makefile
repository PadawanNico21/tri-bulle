build: tribulle.o app.o 
	gcc -Wall tribulle.o app.o -o tribulle

tribulle.o: tribulle.c
	gcc -c tribulle.c

app.o: app.c
	gcc -c app.c

test.o: test.c
	gcc -c test.c

test-bin: tribulle.o test.o
	gcc test.o tribulle.o -o test

test: test-bin
	./test

install: build
	strip ./tribulle
	mkdir -p ${PREFIX}/usr/bin
	cp ./tribulle ${PREFIX}/usr/bin/tribulle

clean:
	rm tribulle *.o
