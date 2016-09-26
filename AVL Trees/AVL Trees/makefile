Driver : Driver.bc AVLTree.bc
	clang++ -std=c++14 Driver.bc AVLTree.bc Queue.bc -o Driver
Driver.bc : Driver.cpp AVLTree.bc
	clang++ -std=c++14 -Wall -O0 -g3 -S -emit-llvm Driver.cpp -o Driver.bc
AVLTree.bc : AVLTree.cpp AVLTree.hpp Queue.bc
	clang++ -std=c++14 -Wall -O0 -g3 -S -emit-llvm AVLTree.cpp -o AVLTree.bc
Queue.bc : Queue.cpp Queue.hpp
	clang++ -std=c++14 -Wall -O0 -g3 -S -emit-llvm Queue.cpp -o Queue.bc
