############################# Makefile ##########################
CC=gcc
CFLAGS=-Wall -ansi -pedantic
DEPS = menu.h ui.h agenda.h
OBJ = main.o menu.o ui.o agenda.o

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

agenda_dinamica: $(OBJ)
	gcc $(CFLAGS) -o $@ $^

clean:
	rm -rf *.o
	rm -rf agenda_dinamica