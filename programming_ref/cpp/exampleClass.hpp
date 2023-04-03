#ifndef exampleClass_hpp
#define exampleClass_hpp

#include <string>

class exampleClass {
    
    // Member variable declarations
    private:
        int var1;
        std::string testVar2 = "test\n";
    
    // Public function declarations
    public:
        exampleClass();
        void setup(int x);
        int addN(int N);
};

#endif
