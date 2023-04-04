#include <iostream>
#include <string>
#include "exampleClass.hpp"

exampleClass::exampleClass() {
    std::cout << "Class has been created" << std::endl;
}

void exampleClass::setInt(int x) {
    var1 = x;
}

void exampleClass::setStr(std::string x) {
    var2 = x;
}

void exampleClass::printState() {
    std::cout << "var 1 is " << var1 << std::endl;
    std::cout << "var 2 is " << var2 << std::endl;
}
