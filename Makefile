CC=gcc
TARGET=libautomata.so
OBJ=automata.o func_common.o func_fa.o init.o
CFLAGS= -Wall -O3 -fPIC

ALL: $(TARGET)
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -shared -o $(TARGET) $(OBJ)
automata.o: automata.c automata.h _automata.h
	$(CC) $(CFLAGS) -c automata.c
func_common.o: func_common.c func_common.h _automata.h
	$(CC) $(CFLAGS) -c func_common.c
func_fa.o: func_fa.c func_common.h _automata.h
	$(CC) $(CFLAGS) -c func_fa.c 
init.o: init.c func_common.h _automata.h
	$(CC) $(CFLAGS) -c init.c
.PHONY: clean
clean:
	rm -f $(OBJ) $(TARGET)
