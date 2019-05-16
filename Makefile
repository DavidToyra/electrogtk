#Makefile for electrotestgtk
all:	electrotestgtk

electrotestgtk:	electrogui.o coupling_box.o calculate_box.o voltage_box.o
	gcc electrogui.o calculate_box.o voltage_box.o coupling_box.o -o electrotestgtk -L/usr/local/lib -lresistance -lpower -lcomponent -Wl,-R/usr/local/lib -lm `pkg-config --cflags --libs gtk+-2.0`

electrogui.o:	electrogui.c electrogui.h
	gcc -c electrogui.c -o electrogui.o `pkg-config --cflags --libs gtk+-2.0`

coupling_box.o:	coupling_box.c coupling_box.h
	gcc -c coupling_box.c -o coupling_box.o `pkg-config --cflags --libs gtk+-2.0`

voltage_box.o:	voltage_box.c voltage_box.h
	gcc -c voltage_box.c -o voltage_box.o `pkg-config --cflags --libs gtk+-2.0`

calculate_box.o:	calculate_box.c calculate_box.h
	gcc -c calculate_box.c -o calculate_box.o `pkg-config --cflags --libs gtk+-2.0`
