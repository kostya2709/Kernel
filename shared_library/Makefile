LIBNAME=libprint
FNAME=main

build: $(LIBNAME).o $(LIBNAME).so linker_name sym_ref

$(LIBNAME).o:
	@gcc -fPIC -Wall -g -c $(LIBNAME).c

$(LIBNAME).so:
	@gcc -g -shared -Wl,-soname,$(LIBNAME).so.0 -o $(LIBNAME).so.0.0 $(LIBNAME).o -lc

linker_name:
	@ldconfig -v -n


sym_ref:
	@ln -sf $(LIBNAME).so.0 $(LIBNAME).so

all: compile export

compile:
	@gcc $(FNAME).c -o $(FNAME) -lprint -L.

export:
	@export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:.


run:
	@gcc dynamic_main.c -o dynamic_main -ldl