CMP = clang++-15 -L~/Tools/Libs/boost/boost_1_82_0 -I ~/Tools/Libs/boost/boost_1_82_0
release:
	$(CMP) -O3 --std=c++2b -latomic -pthread -Wall -Wextra -Wshadow -Wconversion -Wpedantic Bench.cpp -o Bench.out
debug:
	$(CMP) -O0 --std=c++2b -fsanitize=thread -pthread -latomic -g -Wall -Wextra -Wshadow -Wconversion -Wpedantic -Wshadow Bench.cpp -o Bench.out
ubsanitizer:
	$(CMP) -O0 --std=c++2b -fsanitize=undefined -latomic -g -Wall -Wextra -Wshadow -Wconversion -Wpedantic Bench.cpp -o Bench.out
clean:
	rm Bench.out
threadsanitizer:
	make debug
	valgrind --tool=helgrind ./Bench.out 1 3 3