#pragma once

#include <vector>

class Calculator {
public:
    virtual int add(std::initializer_list<int> inputs) {
        int result = 0;

        for (int input : inputs) {
            result += input;
        }

        return result;
    }
};

