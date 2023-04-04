// Include statements for the built in libraries
#include <stdio.h>
#include <stdbool.h>
// Include statements for user specified libraries
#include "example.h"

// The main function is the entry point for a program
// Each program must contain 1 main function,
// and no other function in the program can be named main
// argc and argv are user provided inputs that are specified before runtime
int main(int argc, char* argv[]) {
    // variables
    int x = 1;
    char* oldstr = "whats up pahtnuh\n";
    bool swayHasTheAnswers = false;
    
    // Conditional logic
    // If else
    if (swayHasTheAnswers == true) {
        printf("Ok im gonna chill now bro\n");
    } else {
        printf("I am Walt Disney\n");
    }
    
    // if else if else
    if (x > 0) {
        printf("X is positive\n");
    } else if (x < 0) {
        printf("X is negative\n");
    }
    else {
        printf("X is 0 bruh\n");
    }
    
    // Loops
    // for loops
    for (int i = 0; i < 3; i++) {
        printf("i is %d\n", i);
    }
    
    // while loops
    x = 3;
    while (x > 0) {
        printf("x is %d\n", x);
        x--;
    }
    
    // Calling functions / variables from other files
    x = 10;
    x = addN(&x, 1);
    return 0;
}
