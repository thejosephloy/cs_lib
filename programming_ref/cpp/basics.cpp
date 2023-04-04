// How to include built in libraries
#include <iostream>
#include <string>

// How to include user classes and functions
#include "exampleClass.hpp"

// function prototypes
// all functions outside of the main function
// require prototype declarations before they are usable
void testFunction();

// All runable programs must have a main file
// int argc and char* argv[] are optional, and specify
// user provided input argumnets
int main(int argc, char* argv[]) {
	// Variables
    // Variables are typed
    int x = 1;
    std::string oldstr = "whats up pahtnuh\n";
    bool swayHasTheAnswers = false;
    
    // Conditional Logic
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
    
    // Loops
    // for loop
    for (int i = 0; i < 4; i++) {
        std::cout << "i is " << i << std::endl;
    }
    // while loop
    x = 3;
    while (x > 0) {
        std::cout << "x is " << x << std::endl;
        x--;
    }
    
    // Classes
    // class instantiation
    exampleClass instance;
    
    // calling class function
    int intVar = 7;
    std::string strVar = "DATBOIJOE";
    instance.setInt(intVar);
    instance.setStr(strVar);
    instance.printState();
    
    // Functions
    // Calling helper functions in the same file
    testFunction();
    // main function returns 0 if it runs as expected,
    // returns non-zero if an error occurs
    return 0;
}

// Function declarations for helper functions are usually added after the
// main function
void testFunction() {
    std::cout << "Test function has been called" << std::endl;
}
