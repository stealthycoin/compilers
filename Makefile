#This assignment completed with pair programming
# Name: John Carlyle Username: jcarlyle@ucsc.edu
# Name: Morgan McDermott Username: moamcder@ucsc.edu

GPP = g++ -g -O0 -Wall -Wextra -std=gnu++0x
executable = oc
objects = main.o auxlib.o stringset.o
SUBMITS = main.cc auxlib.cc auxlib.h stringset.cc \
    stringset.h Makefile README PARTNER
PROJECT = cmps104a-wm.f13 asg1

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

submit: ${SUBMITS}
	submit ${PROJECT} ${SUBMITS}

.PHONY: spotless
spotless: clean
	- rm $(executable)
