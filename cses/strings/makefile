compile:
	g++ $(file) -o run.out -Wall -Wextra -pedantic && ./run.out

test:
	rm -rf tests && unzip -o tests.zip -d tests && tests.sh $(file)

clean:
	rm *.out
