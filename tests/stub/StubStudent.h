#pragma once

#include "stub/Student.h"

class StubStudent : public Student {
private:
    int score;

public:
    StubStudent(int score) : score(score) {}

    int getCET4TotalScore() const override {
        return score;
    }
};

