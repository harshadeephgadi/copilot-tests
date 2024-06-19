//Write a google test for my_uart_drv1 function in test_h2.cpp
//Mock the function my_dep1
//The test should check for the following conditions:
//1. If my_dep1 returns a positive value, my_uart_drv1 should return 1
//2. If my_dep1 returns a negative value, my_uart_drv1 should return -1
//3. If my_dep1 returns 0, my_uart_drv1 should return 0

#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <h2.hpp>

using namespace testing;
class my_dep1_mock {
public:MOCK_METHOD1(my_dep1, int(int));
};

my_dep1_mock mock;

//define my_dep1 function by mapping it to the mock function
int my_dep1(int a) {
	return mock.my_dep1(a);
}

//define object of structure s and pass it to the function
TEST(my_uart_drv1, test2) {
	s s1;
	s1.a = 10;
	EXPECT_CALL(mock, my_dep1(10)).WillOnce(Return(10));
	EXPECT_EQ(1, my_uart_drv1(s1));
}

//DEfine another test case where the return value of my_dep1 is negative
TEST(my_uart_drv1, test3) {
	s s1;
	s1.a = 10;
	EXPECT_CALL(mock, my_dep1(10)).WillOnce(Return(-10));
	EXPECT_EQ(-1, my_uart_drv1(s1));
}

//Define another test case where input to my_uart_drv1 is negative and
// my_dep1 returns negative number
TEST(my_uart_drv1, test4) {
	s s1;
	s1.a = -10;
	EXPECT_CALL(mock, my_dep1(-10)).WillOnce(Return(-10));
	EXPECT_EQ(-1, my_uart_drv1(s1));
}

// Define test cases for all following conditions
// input to my_uart_drv1 is negative and my_dep1 returns positive number
// input to	my_uart_drv1 is negative and my_dep1 returns 0
// input to my_uart_drv1 is 0 and my_dep1 returns positive number
// input to my_uart_drv1 is 0 and my_dep1 returns negative number
// input to my_uart_drv1 is 0 and my_dep1 returns 0
// input to my_uart_drv1 is positive and my_dep1 returns 0
// input to my_uart_drv1 is positive and my_dep1 returns negative number
// input to my_uart_drv1 is positive and my_dep1 returns positive number


int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

