#include <iostream>
#include "exampleClass.hpp"

void exampleClass::exampleFunction() {
    std::cout << "test var 1 is " << testVar1 << std::endl;
	std::cout << "test var 2 is " << testVar2 << std::endl;
}

void addN(int N) {
	testVar1 += N;
}
