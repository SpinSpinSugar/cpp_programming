all:
	g++ --std=c++20 -O3 myVector.cpp -o myVector
debug:
	g++ --std=c++20 -g -Wall -O0 myVector.cpp -o myVector
memcheck:
	valgrind --leak-check=full --track-origins=yes ./myVector
clean:
	rm ./myVector