CMP = clang++

all:
	$(CMP) -Wpedantic -Wall -Wextra -Wconversion --std=c++20 Output.cpp -o Output.out
	$(CMP) -Wpedantic -Wall -Wextra -Wconversion --std=c++20 Input.cpp -o Input.out

input:
	$(CMP) -Wpedantic -Wall -Wextra -Wconversion --std=c++20 Input.cpp -o Input.out

output:
	$(CMP) -Wpedantic -Wall -Wextra -Wconversion --std=c++20 Output.cpp -o Output.out

clear:
	> data
	> test
	rm Input.out
	rm Output.out

example:
	g++ Another_Example.cpp -o Another_Example.out