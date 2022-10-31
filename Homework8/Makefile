$COMP = g++

all:
	g++ --std=c++20 Output.cpp -o Output.out
	g++ --std=c++20 Input.cpp -o Input.out

input:
	g++ --std=c++20 Input.cpp -o Input.out

output:
	g++ --std=c++20 Output.cpp -o Output.out

clear:
	> data
	> test
	rm Input.out
	rm Output.out

example:
	g++ Another_Example.cpp -o Another_Example.out