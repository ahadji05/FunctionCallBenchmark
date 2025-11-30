#include "foo.hpp"
#include <random>

Foo::Foo() : gen(std::random_device{}()), dist(0, 1000000) {}

int Foo::foo() {
    return dist( gen );
}