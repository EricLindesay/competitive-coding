compile:
	g++ $(file) -o run.out -Wall -Wextra -pedantic && ./run.out

clean:
	rm *.out
