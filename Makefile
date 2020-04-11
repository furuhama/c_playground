CC = gcc
TARGET = a.out

# USAGE:
#   make once SRC=sample.c
#   make once SRC=another.c CC=clang
once: $(SRC)
	@$(CC) $(SRC) -o $(TARGET)
	@./$(TARGET)
	@make clean

.PHONY: clean
clean:
	@$(RM) -f $(TARGET) *.o
