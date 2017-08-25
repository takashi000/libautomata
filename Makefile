CC=cc
TARGET=libautomata.so
OBJ=automata.o func_common.o func_fa.o
CFLAGS= -O3 -fPIC

ALL: $(TARGET)
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -shared -o $(TARGET) $(OBJ)
automata.o: _automata.h func_common.h
func_common.o: func_common.h
func_fa.o: func_common.h

.PHONY: clean
clean:
	rm -f $(OBJ) $(TARGET)
