GPP = g++ -g -O0 -Wall -Wextra -std=c++11
executable = oc
objects = main.o auxlib.o stringset.o
all: $(objects)
	$(GPP) $(options) -o $(executable) $(objects)

main.o: main.cc
	$(GPP) -c main.cc

auxlib.o: auxlib.cc auxlib.h
	$(GPP) -c auxlib.cc

stringset.o: stringset.h stringset.cc
	$(GPP) -c stringset.cc

.PHONY: clean
clean:
	- rm *~ $(objects) $(executable)

.PHONY: spotless
spotless: clean
	- rm $(executable)
