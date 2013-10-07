executable = 
objects = program.o
all: $(objects)
	cc -o $(executable) $(objects)

program.o:
	cc -c main.cpp

clean:
	rm *~  $(objects)

spotless: clean
	rm $(executable)
