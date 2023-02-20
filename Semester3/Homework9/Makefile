CMP = clang++

all:
	$(CMP) -O3 -Wpedantic -Wall -Wextra -Wconversion --std=c++20 shell.cpp -o shell.out

debug_leak:
	$(CMP) -O0 -g -DDEBUG -fsanitize=leak -Wpedantic -Wall -Wextra -Wconversion --std=c++20 shell.cpp -o shell.out

debug:
	$(CMP) -O0 -g -DDEBUG -Wpedantic -Wall -Wextra -Wconversion --std=c++20 shell.cpp -o shell.out

# BUG OF CLANG
#debug_memory:
#       $(CMP) -O0 -g -DDEBUG -fsanitize=memory -Wpedantic -Wall -Wextra -Wconversion --std=c++20 shell.cpp -o shell.out

debug_memory_gcc:
	g++ -O0 -g -DDEBUG -fsanitize=address -Wpedantic -Wall -Wextra -Wconversion --std=c++20 shell.cpp -o shell.out