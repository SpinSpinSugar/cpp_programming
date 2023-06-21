CMP = clang++-15

release:
	$(CMP) -O3 --std=c++2b -Wall -Wextra -Wshadow TaskDistributor.cpp -o TaskDistributor.out
debug:
	$(CMP) -O0 --std=c++2b -fsanitize=thread -g -Wall -Wextra -Wshadow TaskDistributor.cpp -o TaskDistributor.out
ubsanitizer:
	$(CMP) -O0 --std=c++2b -fsanitize=undefined -g -Wall -Wextra -Wshadow TaskDistributor.cpp -o TaskDistributor.out
clean:
	rm TaskDistributor.out
threadsanitizer:
		$(CMP) -O3 --std=c++2b -fsanitize=thread -g -Wall -Wextra -Wshadow TaskDistributor.cpp -o TaskDistributor.out
