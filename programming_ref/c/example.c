#include <stdio.h>
#include "example.h"

void testFunc() {
    printf("Testing");
}

int addN(int* x, int n) {
    printf("x was %d\n", *x);
    (*x) = (*x) + n;
    printf("x is %d\n", *x);
    return *x;
}
