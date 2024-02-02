compile:
	g++ $(file) -o run.out -Wall -Wextra -pedantic -I../myProfiler -O5 && ./run.out

test:
	g++ $(file) -o run.out -Wall -Wextra -pedantic -O5 && ./run.out << $(test) > output.txt

time:
	g++ $(file) -o run.out -Wall -Wextra -pedantic -O5 && time ./run.out

clean:
	rm *.out
