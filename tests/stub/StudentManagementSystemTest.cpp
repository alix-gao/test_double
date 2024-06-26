#include "gtest/gtest.h"
#include "stub/Student.h"
#include "StubStudent.h"
#include "stub/StudentManagementSystem.h"

class StudentManagementSystemTest : public ::testing::Test {
protected:
    void SetUp() override {
        score = 430;
        stubStudent = new StubStudent(score);
        system = new StudentManagementSystem();
    }

    void TearDown() override {
        delete stubStudent;
        delete system;
    }

    int score;
    Student* stubStudent;
    StudentManagementSystem* system;
};

/*
 * 注意：这是一个关于 Stub 用法的演示，只是一个示例，在实际的代码中，逻辑不会是这个样子的。
 *      假设，我们现在想要通过一个学生管理系统查看一个学生的英语四级成绩过没过。
 *      但是，因为我们现在在写的是单元测试，所以我们不希望连接数据库，
 *      那么，我们可以通过用 Stub 的方式来模拟返回值。
 *
 *      在 CashRegister 例子中，我们会详细的看到。
 * */
TEST_F(StudentManagementSystemTest, should_pass_CET4_if_score_is_over_425) {
    bool ifCET4Pass = system->ifCET4Pass(*stubStudent);

    ASSERT_TRUE(ifCET4Pass);
}

