FNAME=thread
LFLAGS= -o
CFLAGS= -c -Wall
ARGUMENTS= 15 27

all: $(FNAME)

$(FNAME): $(FNAME).o
	@g++ $(LFLAGS) $(FNAME) main.o -lpthread
	@./$(FNAME) $(ARGUMENTS)

$(FNAME).o:
	@g++ $(CFLAGS)  main.c

clean:
	@rm -rf $(FNAME) *.o