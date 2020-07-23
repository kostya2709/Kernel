FNAME=test
LFLAGS= -o
CFLAGS= -c -Wall

all: $(FNAME)

$(FNAME): $(FNAME).o
	@g++ $(LFLAGS) $(FNAME) main.o
	@./$(FNAME)

$(FNAME).o:
	@g++ $(CFLAGS)  main.c

clean:
	@rm -rf $(FNAME) *.o