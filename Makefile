executable = oc
objects = main.o auxlib.o
all: $(objects)
	gcc -o $(executable) $(objects)

<<<<<<< HEAD
main.o: main.cpp
	gcc -c main.cpp

auxlib.o: auxlib.cc auxlib.h
	gcc -c auxlib.cc
=======
main.o: main.c
	g++ -c main.c

auxlib.o: auxlib.h auxlib.cc
	g++ -c auxlib.cc
>>>>>>> popen

.PHONY: clean
clean:
	- rm *~ $(objects) $(executable)

.PHONY: spotless
spotless: clean
	- rm $(executable)
