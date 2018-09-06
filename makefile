# comment

CC = gcc
CFLAGS = -Wall
LIBS =
SRC = main.h
TARGET = ass1
OBJ = main.o

ass1: $(OBJ)
	$(CC) $(CFLAGS) -o ass1 $(OBJ) $(LIBS)

main.o: main.c

clean:
	/bin/rm -f *.o $(TARGET)
