CMP = clang++

all:
	$(CMP) -O3 -Wpedantic -Wall -Wextra -Wconversion --std=c++20 shell.cpp -o shell.out

ptr_v:
	$(CMP) -O3 -Wpedantic -Wall -Wextra -Wconversion --std=c++20 shell2.cpp -o shell2.out

debug_ptr_san:
	$(CMP) -O0 -g -DDEBUG -fsanitize=leak -Wpedantic -Wall -Wextra -Wconversion --std=c++20 shell2.cpp -o shell2.out

debug_ptr:
	$(CMP) -O0 -g -DDEBUG -Wpedantic -Wall -Wextra -Wconversion --std=c++20 shell2.cpp -o shell2.out