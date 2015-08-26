SRCDIR=src
HPPDIR=include
SRCS=$(SRCDIR)/*.cpp main.cpp

CPP=g++
CPPFLAGS=--std=c++11
OUTPUT=sudoku

all: build run clean

build:
	$(CPP) -I$(HPPDIR) $(CPPFLAGS) $(SRCS) -o $(OUTPUT) 

run:
	./$(OUTPUT)

clean:
	rm $(OUTPUT)

