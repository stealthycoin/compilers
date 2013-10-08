executable = oc
objects = main.o
all: $(objects)
	g++ -o $(executable) $(objects)

main.o:
	g++ -c main.cpp

.PHONY: clean
clean:
	rm *~ $(objects)

.PHONY: spotless
spotless: clean
	rm $(executable)
