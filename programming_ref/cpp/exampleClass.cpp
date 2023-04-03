#include <iostream>
#include "exampleClass.hpp"

void exampleClass::setup(int x) {
    var1 = x;
    std::cout << "test var 1 is " << var1 << std::endl;
    std::cout << "test var 2 is " << testVar2 << std::endl;
}

int exampleClass::addN(int N) {
	var1 += N;
    return var1;
}
