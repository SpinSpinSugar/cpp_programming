CMP = g++ -cpp=c++20

all:
	$(CMP) -O3 gen_tests.cpp -o par.out

NPAR:
	$(CMP) -DNPAR -O3 gen_tests.cpp -o npar.out