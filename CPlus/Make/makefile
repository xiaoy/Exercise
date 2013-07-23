all : Zoo

Zoo : Zoo.o Cat.o
	gcc -o $@ $^

Zoo.o : Zoo.c
	gcc -c $^ 
Cat.o : Cat.c
	gcc -c Cat.c
	
clean:
	rm Zoo.o Cat.o
