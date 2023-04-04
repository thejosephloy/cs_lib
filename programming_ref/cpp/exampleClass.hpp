// Header files should start with #ifndef and #define
#ifndef EXAMPLECLASS_H
#define EXAMPLECLASS_H

#include <string>

class exampleClass {
    // These are functions and variables that can be accessed from outside the class
    public:
        exampleClass();
        void setInt(int x);
        void setStr(std::string x);
        void printState();
    // These are functions and variables that can only be accessed from inside this class
    // and from other classes that inherit from this class
    private:
        int var1;
        std::string var2;
}; // Do not forget to put a semicolon after you

// Header files should end with #endif
#endif
