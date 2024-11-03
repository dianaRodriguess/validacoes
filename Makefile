all:
	gcc -Wall -c C/validation.c
	gcc -o valida *.o

run_test:
	gcc -Wall -c C/test_validation.c
	gcc -o test *.o
	./test

clean:
	rm -f *.o valida