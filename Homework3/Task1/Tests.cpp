#include "gtest/gtest.h"
#include "Task1.hpp"
TEST(QUAT, Operator_equals_test) {
    auto a = quaternion<double> {1, 1, 1, 1};
    auto b = quaternion<double> {1, 1, 1, 1};
    EXPECT_EQ(a, b);
}

TEST(QUAT, Operator_product_test) {
    auto p = quaternion<double> {1, 17, 29, -13} * quaternion<double> {-14, 93, -24, -48};
    auto ans = quaternion<double> {-1523, -1849, -823, -2971};
    EXPECT_EQ(p, ans);
}

TEST(QUAT, Method_conj_test) {
    auto p = quaternion<double> { -1325, 21935, -213, 8132 };
    auto ans = quaternion<double> { -1325, -21935, 213, -8132 };
    p.conj();
    EXPECT_EQ(p, ans);
}

TEST(QUAT, Operator_minus_test) {
    auto a = quaternion<double> { 135, -3150, 3250, 245 };
    auto b = quaternion<double> { 2346, 1223, -34102, 12435 };
    auto c = a - b;
    auto ans = quaternion<double> { -2211, -4373, 37352, -12190 };
    EXPECT_EQ(c, ans);
}

TEST(QUAT, Operator_division_test) {
    auto a = quaternion<double> { 1, -2, 3, -4 };
    auto b = quaternion<double> { 2, -4, 6, -8 };
    auto p = a / b;
    auto ans = quaternion<double> { 0.5, 0, 0, 0 };
    EXPECT_EQ(p, ans);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}