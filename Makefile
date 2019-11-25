
OBJS	= main.o Sudoku.o
SOURCE	= main.cpp Sudoku.cpp
HEADER	= 
OUT	= tp3
CC	 = g++
FLAGS	 = -g -c -Wall 
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp 

Sudoku.o: Sudoku.cpp
	$(CC) $(FLAGS) Sudoku.cpp 

clean:
	rm -f $(OBJS) $(OUT)