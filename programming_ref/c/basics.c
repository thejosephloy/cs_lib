#include <stdio.h>
#include <stdbool.h>

int main(int argc, char* argv[]) {
    // variables
    int x = 1;
    char* oldstr = "whats up pahtnuh\n";
    bool swayHasTheAnswers = false;
    
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
    return 0;
}
