#	No spaces are allowed, only tabs
#	compiler
CC=gcc
#	compiler	flags
CFLAGS=-Wall	-ansi	-pedantic-errors
#	link/load	flags ex: "−lm" for math.h
LDFLAGS=
all	:	reminder	addtask
reminder:
	$(CC)	$(CFLAGS)	reminder.c	-o	reminder	$(LDFLAGS)
addtask:
	$(CC)	$(CFLAGS)	addtask.c	-o	addtask	$(LDFLAGS)
clean:
	rm	reminder
	rm	addtask
