compile:
	g++ $(file) -o run.out -Wall -Wextra -pedantic && ./run.out

test:
	g++ $(file) -o run.out -Wall -Wextra -pedantic && ./run.out << $(test)

clean:
	rm *.out
