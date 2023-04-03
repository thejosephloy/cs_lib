#include <stdio.h>

void testFunc() {
    printf("Testing");
}

int addN(int* x, int n) {
    printf("x was %d", *x);
    (*x) = (*x) + n;
    printf("x is %d", *x);
    return *x;
}
