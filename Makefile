# Makefile for electrotest.
# all compiles the libraries and puts them in the lib directory, it also compiles
# the mainprogram with the shared libraries.
# lib builds the libraries.
# install will copy the files to /usr/bin and /usr/lib.

CC = gcc

all: lib


libresistance.o: src/libresistance/libresistance.c src/libresistance/libresistance.h
	$(CC) -c -fpic src/libresistance/libresistance.c -o libresistance.o -lm

libpower.o: src/libpower/libpower.c src/libpower/libpower.h
	$(CC) -c -fpic src/libpower/libpower.c -o libpower.o -lm

libcomponent.o: src/libcomponent/libcomponent.c src/libcomponent/libcomponent.h
	$(CC) -c -fpic src/libcomponent/libcomponent.c -o libcomponent.o -lm

lib: libresistance.o libpower.o libcomponent.o
	$(CC) libresistance.o -shared -o libresistance.so -lm
	$(CC) libpower.o -shared -o libpower.so -lm
	$(CC) libcomponent.o -shared -o libcomponent.so -lm

install: lib
	mkdir -p $(DESTDIR)/usr/bin
	install libresistance.so libpower.so libcomponent.so $(DESTDIR)/usr/bin
	

clean:
	rm -rf *.o *.so
	rm -rf src/lib

uninstall:
	rm /usr/bin/libresistance.so /usr/bin/libpower.so /usr/bin/libcomponent.so
