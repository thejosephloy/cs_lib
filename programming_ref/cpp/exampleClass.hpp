#ifndef EXAMPLECLASS_H
#define EXAMPLECLASS_H

#include <string>

class exampleClass {
    public:
        exampleClass();
        void setInt(int x);
        void setStr(std::string x);
        void printState();
    
    private:
        int var1;
        std::string var2;
};

#endif
