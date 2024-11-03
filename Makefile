all: valida

valida: validation.o
	gcc -o valida validation.o
	./valida

validation.o: C/validation.c 
	gcc -Wall -c C/validation.c

run_test: test_validation.o validation.o
	gcc -o test test_validation.o validation.o
	./test

test_validation.o: C/test_validation.o
	gcc -Wall -c C/test_validation.c 

clean:
	rm -f *.o */*.o valida test