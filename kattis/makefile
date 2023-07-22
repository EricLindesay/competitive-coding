compile:
	g++ $(file) -o run.out -Wall -Wextra -pedantic -O5 && ./run.out

test:
	g++ $(file) -o run.out -Wall -Wextra -pedantic -O5 && ./run.out << $(test) > output.txt

clean:
	rm *.out
