// Must include libraries that are being used in the file
#include <iostream>
#include <string>

// Note that you must include the header file of your class
// in order to use it in other files
#include "exampleClass.hpp"

// Constructor method
// className::className(args) {
// ...
// }
// Notice there is no return type for the constructor
exampleClass::exampleClass() {
    std::cout << "Class has been created" << std::endl;
}

// Member functions
// Notice that member functions require return types
// as well as namespace declarations before function names
// returnType className::functionName(args) {
// ...
// }

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
