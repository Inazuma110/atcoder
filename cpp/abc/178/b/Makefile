run: 14
14:
	# g++ -std=c++14 main.cpp -g -Wall -fsanitize=undefined -D_LIBCPP_DEBUG=0
	g++ -std=c++17 -g -Wall -fsanitize=undefined -Wno-deprecated -Wno-unneeded-internal-declaration main.cpp
	cat input
	cat input | ./a.out
11:
	g++ -std=c++11 main.cpp -Wall -g -fsanitize=undefined -D_GLIBCXX_DEBUG
	cat input | ./a.out

