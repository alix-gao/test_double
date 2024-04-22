#pragma once

#include <vector>
#include <spy/Calculator.h>

class Call {
private:
    std::vector<int> inputs;

public:
    Call(std::initializer_list<int> inputs) : inputs(inputs) {}

    std::vector<int> getParameters() const {
        return inputs;
    }
};

class SpyCalculator : public Calculator {
private:
    std::vector<Call> callList;

public:
    int add(std::initializer_list<int> inputs) override {
        log(inputs);
        return Calculator::add(inputs);
    }

    int callTimes() const {
        return callList.size();
    }

    std::vector<Call> getCallList() const {
        return callList;
    }

private:
    void log(std::initializer_list<int> inputs) {
        callList.push_back(Call(inputs));
    }
};

