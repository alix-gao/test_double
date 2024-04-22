#include <gtest/gtest.h>
#include <vector>
#include "SpyCalculator.h"

class CalculatorTest : public ::testing::Test {
protected:
    void SetUp() override {
        calculator = new SpyCalculator();
    }

    void TearDown() override {
        delete calculator;
    }

    SpyCalculator* calculator;
};

/*
 * 注意：本示例中，手动实现了 Spy 的部分工作原理，比如，记录传入参数，记录调用次数等。
 *      在真实的 Spy 实现中，会有更复杂的实现方式。
 *      例子中给出的是：一个计算器的加法实现。
 *      在本例中，想要做到的是，可以记录 Add 方法被调用的次数和传入的参数。在本例中有一个 Call 类，这里记录的是每次调用的参数，
 *      通过对于 CallList 的大小来确定被调用的次数。
 * */
TEST_F(CalculatorTest, should_return_correct_input_value_and_call_times_and_result) {
    int firstAddResult = calculator->add({2, 2, 2});
    int secondAddResult = calculator->add({3, 4});
    int finalResult = calculator->add({firstAddResult, secondAddResult});

    EXPECT_EQ(firstAddResult, 6);
    EXPECT_EQ(secondAddResult, 7);
    EXPECT_EQ(finalResult, 13);
    EXPECT_EQ(calculator->callTimes(), 3);

    auto callList = calculator->getCallList();
    EXPECT_EQ(callList[0].getParameters(), (std::vector<int>{2, 2, 2}));
    EXPECT_EQ(callList[1].getParameters(), (std::vector<int>{3, 4}));
    EXPECT_EQ(callList[2].getParameters(), (std::vector<int>{6, 7}));
}

