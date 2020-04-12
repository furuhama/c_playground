CC = gcc
TARGET = a.out

once: $(SRC)
	@$(CC) $(SRC) -o $(TARGET)
	@./$(TARGET) || true
	@make clean

.PHONY: clean
clean:
	@$(RM) -f $(TARGET) *.o
