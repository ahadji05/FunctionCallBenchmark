#include "fooVirtual.hpp"
#include <random>

FooVirtual::FooVirtual() : gen(std::random_device{}()), dist(0, 1000000) {
    this->imlp = 1;
}

int FooVirtual::foo() {
    return ( this->imlp == 1 ) ? dist(gen) : 0;
}

FooVirtual2::FooVirtual2() : gen(std::random_device{}()), dist(0, 1000000) {
    this->imlp = 2;
}

int FooVirtual2::foo() {
    return ( this->imlp == 2 ) ? dist(gen) : 0;
}