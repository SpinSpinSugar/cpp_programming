CMP = clang++-15
release:
	$(CMP) -std=c++20 -O3 -Wall -Wextra check.cpp -o check.out
debug:
	$(CMP) -std=c++20 -fsanitize=thread -O0 -g -Wall -Wextra check.cpp -o check.out
clean:
	rm check.out