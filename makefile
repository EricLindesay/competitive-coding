compile:
	g++ $(file).cpp -o run.out -Wall -Wextra -pedantic && ./run.out

clean:
	rm *.out
