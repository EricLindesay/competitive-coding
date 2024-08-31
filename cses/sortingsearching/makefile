SHELL := /bin/bash

define runtests =

endef

compile:
	g++ $(file) -o run.out -Wall -Wextra -pedantic && ./run.out

test:
	tests.sh $(file)

clean:
	rm *.out
