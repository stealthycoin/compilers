executable = oc
objects = main.o auxlib.o
all: $(objects)
	g++ -o $(executable) $(objects)

main.o: main.c
	g++ -c main.c

auxlib.o: auxlib.h auxlib.cc
	g++ -c auxlib.cc

.PHONY: clean
clean:
	- rm *~ $(objects) $(executable)

.PHONY: spotless
spotless: clean
	- rm $(executable)
