// include statements for built in libraries use <>
#include <stdio.h>
// include statements for user files use ""
#include "example.h"

// Function declarations
// returnType functionName(args) {
// ...
// }
void testFunc() {
    printf("Testing");
}

int addN(int* x, int n) {
    printf("x was %d\n", *x);
    (*x) = (*x) + n;
    printf("x is %d\n", *x);
    return *x;
}
