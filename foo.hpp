#pragma once
#include <random>

class Foo  {
    public:
        Foo();
        int foo();

    private:
        std::mt19937 gen;
        std::uniform_int_distribution<int> dist;
};