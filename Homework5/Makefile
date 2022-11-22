CMP = clang++
all:
	$(CMP) -Wpedantic -Wall -Wextra -Wconversion --std=c++20 -O3 myVector.cpp -o myVector
debug:
	$(CMP) -g -O0 -Wpedantic -Wall -Wextra -Wconversion --std=c++20 -O0 myVector.cpp -o myVector	
memcheck:
	make debug
	valgrind --leak-check=full --track-origins=yes ./myVector
clean:
	rm ./myVector