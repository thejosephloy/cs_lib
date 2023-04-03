#include "foo.hpp"
#include <iostream>

Foo::Foo(int x) : x(x) {

}

int Foo::getX() {
    std::cout << "x is " << x << std::endl;
    return x;
}
