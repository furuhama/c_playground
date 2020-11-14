CC=gcc
CFLAGS=-Wall -std=c11
TARGET=a.out

once: $(SRC)
	@$(CC) $(SRC) -o $(TARGET)
	@./$(TARGET) || true
	@make clean

.PHONY: clean
clean:
	@$(RM) -f $(TARGET) *.o

.PHONY: docker-build
docker-build:
	docker build -t c_playground .

.PHONY: docker-run
docker-run:
	docker run -v $(pwd):/usr/src --rm -it c_playground bash
