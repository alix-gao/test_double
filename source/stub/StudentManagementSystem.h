#pragma once

#include "Student.h"

class StudentManagementSystem {
public:
    bool ifCET4Pass(const Student& student) const {
        return student.getCET4TotalScore() > 425;
    }
};

