executable = oc
objects = main.o auxlib.o
all: $(objects)
	gcc -o $(executable) $(objects)

main.o: main.cpp
	gcc -c main.cpp

auxlib.o: auxlib.cc auxlib.h
	gcc -c auxlib.cc

.PHONY: clean
clean:
	rm *~ $(objects) $(executable)

.PHONY: spotless
spotless: clean
	rm $(executable)
