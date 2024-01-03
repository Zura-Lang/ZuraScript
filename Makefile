exec = program.out
sources = $(wildcard src/*.c)
objects = $(sources:.c=.o)
flags = -g

$(exec): $(objects)
	gcc $(objects) $(flags) -o $(exec)

%.o: %.c include/%.h
	gcc -c $(flags) $< -o $@

install:
	make
	cp ./program.out /usr/local/bin/ZuraScript

clean:
	-rm *.out
	-rm *.objects
	-rm src/*.o