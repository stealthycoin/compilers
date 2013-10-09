executable = oc
objects = main.o
all: $(objects)
	g++ -o $(executable) $(objects)

main.o: main.cpp
	g++ -c main.cpp

.PHONY: clean
clean:
	rm *~ $(objects) $(executable)

.PHONY: spotless
spotless: clean
	rm $(executable)
