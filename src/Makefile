obj=commodity.o test.o
all:${obj}
	gcc $^ -o commodity
	mv commodity  ../bin/
	rm *.o
commodity.o:commodity.c
	gcc -c $< -o $@
test.o:test.c  
	gcc -c $< -o $@
	
	


