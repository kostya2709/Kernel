FNAME=test_1
LFLAGS= -o
CFLAGS= -c -Wall -g

all: $(FNAME)

$(FNAME): $(FNAME).o
	@g++ $(LFLAGS) $(FNAME) $(FNAME).o
	#@./$(FNAME)

$(FNAME).o:
	@g++ $(CFLAGS)  $(FNAME).cpp

clean:
	@rm -rf $(FNAME) *.o core