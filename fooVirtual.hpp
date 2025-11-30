#pragma once
#include <random>

class FooVirtualBase {
    public:
        int imlp;
        virtual ~FooVirtualBase() = default;
        virtual int foo() = 0;
};

class FooVirtual : public FooVirtualBase {
    public:
        FooVirtual();
        int foo() override;
    private:
        std::mt19937 gen;
        std::uniform_int_distribution<int> dist;
};

class FooVirtual2 : public FooVirtualBase {
    public:
        FooVirtual2();
        int foo() override;
    private:
        std::mt19937 gen;
        std::uniform_int_distribution<int> dist;
};
