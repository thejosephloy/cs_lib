#include <iostream>
#include <string>
#include "exampleClass.hpp"

int main(int argc, char* argv[]) {
	// variables
    int x = 1;
    std::string oldstr = "whats up pahtnuh\n";
    bool swayHasTheAnswers = false;
    
    // If else
    if (swayHasTheAnswers) {
        std::cout << "Ok im gonna chill now bro" << std::endl;
    } else {
        std::cout << "I am Walt Disney" << std::endl;
    }
    
    // if else if else
    if (x > 0) {
        std::cout << "X is positive" << std::endl;
    } else if (x < 0) {
        std::cout << "X is negative" << std::endl;
    }
    else {
        std::cout << "X is 0 bruh" << std::endl;
    }
	return 0;
    
    // for loop
    for (int i = 0; i < 4; i++) {
        std::cout << "i is " << i << std::endl;
    }
    // while loop
    x = 3;
    while (x > 0) {
        std::cout << "x is " << x << std::endl;
    }
    
    int N = 5;
    //class instantiation
    exampleClass test;
    test.setup(x);
    std::cout << test.addN(N) << std::endl;
    //calling class function
    
    return 0;
}
