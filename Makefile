.PHONY : build rebuild clean

default :
	@echo "======================================="
	@echo "Use 'make clean' to clean all."
	@echo "Use 'make demo' to test Qsort demo."
	@echo "Use 'make build' to build dynamic linke library."
	@echo "======================================="

CC = cc

RM = rm

build:
	$(CC) -o qsort.so qsort.c -O3 -Wall -fPIC --shared

demo:
	$(CC) -o demo demo.c qsort.c -O3 -Wall

clean:
	$(RM) -rf demo qsort.so

