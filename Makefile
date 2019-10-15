# Makefile for electrotest.
# all compiles the libraries and puts them in the lib directory, it also compiles
# the mainprogram with the shared libraries.
# lib builds the libraries.
# install will copy the files to /usr/bin and /usr/lib.

CC = gcc

all: electrotest

electrotest: electrotest.o
	$(CC) electrotest.o -o electrotest -L/usr/bin -lresistance -lpower -lcomponent -Wl,-R/usr/bin -lm

electrotest.o: src/electrotest.c src/libresistance/libresistance.h src/libpower/libpower.h src/libcomponent/libcomponent.h
	$(CC) -c src/electrotest.c -o electrotest.o -lm

library: libcomponent.o libresistance.o libpower.o
	mkdir lib
	$(CC) libresistance.o -shared -o lib/libresistance.so -lm
	$(CC) libpower.o -shared -o lib/libpower.so -lm
	$(CC) libcomponent.o -shared -o lib/libcomponent.so -lm

libresistance.o: src/libresistance/libresistance.c src/libresistance/libresistance.h
	$(CC) -c -fpic src/libresistance/libresistance.c -o libresistance.o

libpower.o: src/libpower/libpower.c src/libpower/libpower.h
	$(CC) -c -fpic src/libpower/libpower.c -o libpower.o -lm

libcomponent.o: src/libcomponent/libcomponent.c src/libcomponent/libcomponent.h
	$(CC) -c -fpic src/libcomponent/libcomponent.c -o libcomponent.o -lm

lib: libresistance.o libpower.o libcomponent.o
	$(CC) libresistance.o -shared -o libresistance.so -lm
	$(CC) libpower.o -shared -o libpower.so -lm
	$(CC) libcomponent.o -shared -o libcomponent.so -lm

install: electrotest
	mkdir -p $(DESTDIR)/usr/bin
	install electrotest $(DESTDIR)/usr/bin
	

clean:
	rm -rf *.o *.so

uninstall:
	rm -f $(DESTDIR)/usr/bin/electrotest
