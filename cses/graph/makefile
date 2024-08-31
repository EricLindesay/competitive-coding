compile:
	g++ $(file) -o run.out -Wall -Wextra -pedantic && ./run.out

test:
	unzip -o tests.zip -d tests && tests.sh $(file)

test1:
	unzip -o tests.zip -d tests && testOne.sh $(file)

clean:
	rm *.out
