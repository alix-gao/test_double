#pragma once

#include <vector>

class Call {
private:
    std::vector<int> inputs;

public:
    Call(std::initializer_list<int> inputs) : inputs(inputs) {}

    std::vector<int> getParameters() const {
        return inputs;
    }
};

