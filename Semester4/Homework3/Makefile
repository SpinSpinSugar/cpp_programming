CMP = clang++-15

release:
	$(CMP) -O3 --std=c++2b -march=athlon64 -Wall -Wextra -Wshadow packaged_task.cpp -o packaged_task.out
debug:
	$(CMP) -O0 --std=c++2b  -g -Wall -Wextra -Wshadow packaged_task.cpp -o packaged_task.out
ubsanitizer:
	$(CMP) -O0 --std=c++2b -fsanitize=undefined -g -Wall -Wextra -Wshadow packaged_task.cpp -o packaged_task.out
clean:
	rm packaged_task.out
threadsanitizer:
	make release
	valgrind --tool=helgrind ./packaged_task.out
	