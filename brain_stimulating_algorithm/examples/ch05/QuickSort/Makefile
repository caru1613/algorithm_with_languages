.SUFFIXES : .c .o
CC = gcc
CFLAGS = -g -Wall -ansi
 all: test

OBJS = QuickSort.o
SRCS = $(OBJS:.o=.c)

test: $(OBJS)
	$(CC) -o QuickSort $(OBJS) 

clean: 
	rm -rf $(OBJS)
distclean: 
	rm -rf $(OBJS) QuickSort test
