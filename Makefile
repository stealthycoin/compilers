executable = oc
objects = main.o
all: $(objects)
	g++ -o $(executable) $(objects)

main.o:
	g++ -c main.cpp

clean:
	rm *~ $(objects)

spotless: clean
	rm $(executable)
