#pragma once

#include <stdexcept>

class Student {
public:
    virtual int getCET4TotalScore() const {
        throw std::runtime_error("Cannot connect to Database.");
    }
};

