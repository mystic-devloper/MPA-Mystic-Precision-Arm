#include "gtest/gtest.h" // The Google Test framework
#include "mpa/round.h"   // Rounding function declarations
#include "mpa/types.h"   // For f32, f64 types

// A small tolerance for floating-point comparisons
// Use different epsilons for float and double, as float has less precision
const mpa::f32 FLOAT_EPSILON = 1e-6f;
const mpa::f64 DOUBLE_EPSILON = 1e-12;

// --- Test Cases for mpa::round::nearest ---
TEST(RoundTest, NearestF32) {
    ASSERT_FLOAT_EQ(mpa::round::nearest(2.0f), 2.0f);
    ASSERT_FLOAT_EQ(mpa::round::nearest(2.1f), 2.0f);
    ASSERT_FLOAT_EQ(mpa::round::nearest(2.5f), 3.0f); // Rounds away from zero
    ASSERT_FLOAT_EQ(mpa::round::nearest(2.9f), 3.0f);
    ASSERT_FLOAT_EQ(mpa::round::nearest(-2.0f), -2.0f);
    ASSERT_FLOAT_EQ(mpa::round::nearest(-2.1f), -2.0f);
    ASSERT_FLOAT_EQ(mpa::round::nearest(-2.5f), -3.0f); // Rounds away from zero
    ASSERT_FLOAT_EQ(mpa::round::nearest(-2.9f), -3.0f);
    ASSERT_FLOAT_EQ(mpa::round::nearest(0.0f), 0.0f);
    ASSERT_FLOAT_EQ(mpa::round::nearest(0.5f), 1.0f);
    ASSERT_FLOAT_EQ(mpa::round::nearest(-0.5f), -1.0f);
}

TEST(RoundTest, NearestF64) {
    ASSERT_DOUBLE_EQ(mpa::round::nearest(2.0), 2.0);
    ASSERT_DOUBLE_EQ(mpa::round::nearest(2.1), 2.0);
    ASSERT_DOUBLE_EQ(mpa::round::nearest(2.5), 3.0);
    ASSERT_DOUBLE_EQ(mpa::round::nearest(-2.5), -3.0);
    ASSERT_DOUBLE_EQ(mpa::round::nearest(0.5), 1.0);
    ASSERT_DOUBLE_EQ(mpa::round::nearest(-0.5), -1.0);
}

// --- Test Cases for mpa::round::towards_zero ---
TEST(RoundTest, TowardsZeroF32) {
    ASSERT_FLOAT_EQ(mpa::round::towards_zero(2.9f), 2.0f);
    ASSERT_FLOAT_EQ(mpa::round::towards_zero(2.0f), 2.0f);
    ASSERT_FLOAT_EQ(mpa::round::towards_zero(0.5f), 0.0f);
    ASSERT_FLOAT_EQ(mpa::round::towards_zero(-2.9f), -2.0f);
    ASSERT_FLOAT_EQ(mpa::round::towards_zero(-0.5f), -0.0f); // -0.0 is technically correct for float
}

TEST(RoundTest, TowardsZeroF64) {
    ASSERT_DOUBLE_EQ(mpa::round::towards_zero(3.9), 3.0);
    ASSERT_DOUBLE_EQ(mpa::round::towards_zero(-3.9), -3.0);
    ASSERT_DOUBLE_EQ(mpa::round::towards_zero(0.1), 0.0);
}

// --- Test Cases for mpa::round::away_from_zero ---
TEST(RoundTest, AwayFromZeroF32) {
    ASSERT_FLOAT_EQ(mpa::round::away_from_zero(2.1f), 3.0f);
    ASSERT_FLOAT_EQ(mpa::round::away_from_zero(2.0f), 2.0f);
    ASSERT_FLOAT_EQ(mpa::round::away_from_zero(0.0f), 0.0f);
    ASSERT_FLOAT_EQ(mpa::round::away_from_zero(-2.1f), -3.0f);
    ASSERT_FLOAT_EQ(mpa::round::away_from_zero(-2.0f), -2.0f);
    ASSERT_FLOAT_EQ(mpa::round::away_from_zero(0.5f), 1.0f);
    ASSERT_FLOAT_EQ(mpa::round::away_from_zero(-0.5f), -1.0f);
}

TEST(RoundTest, AwayFromZeroF64) {
    ASSERT_DOUBLE_EQ(mpa::round::away_from_zero(3.1), 4.0);
    ASSERT_DOUBLE_EQ(mpa::round::away_from_zero(-3.1), -4.0);
    ASSERT_DOUBLE_EQ(mpa::round::away_from_zero(0.0), 0.0);
}

// --- Test Cases for mpa::round::towards_even ---
TEST(RoundTest, TowardsEvenF32) {
    ASSERT_FLOAT_EQ(mpa::round::towards_even(2.0f), 2.0f);
    ASSERT_FLOAT_EQ(mpa::round::towards_even(2.1f), 2.0f);
    ASSERT_FLOAT_EQ(mpa::round::towards_even(2.5f), 2.0f); // Rounds to even
    ASSERT_FLOAT_EQ(mpa::round::towards_even(3.5f), 4.0f); // Rounds to even
    ASSERT_FLOAT_EQ(mpa::round::towards_even(2.9f), 3.0f);
    ASSERT_FLOAT_EQ(mpa::round::towards_even(-2.5f), -2.0f); // Rounds to even
    ASSERT_FLOAT_EQ(mpa::round::towards_even(-3.5f), -4.0f); // Rounds to even
    ASSERT_FLOAT_EQ(mpa::round::towards_even(0.5f), 0.0f);   // Rounds to even
    ASSERT_FLOAT_EQ(mpa::round::towards_even(-0.5f), -0.0f); // Rounds to even
}

TEST(RoundTest, TowardsEvenF64) {
    ASSERT_DOUBLE_EQ(mpa::round::towards_even(2.5), 2.0);
    ASSERT_DOUBLE_EQ(mpa::round::towards_even(3.5), 4.0);
    ASSERT_DOUBLE_EQ(mpa::round::towards_even(-2.5), -2.0);
    ASSERT_DOUBLE_EQ(mpa::round::towards_even(-3.5), -4.0);
    ASSERT_DOUBLE_EQ(mpa::round::towards_even(0.5), 0.0);
}

// --- Test Cases for mpa::round::towards_odd ---
TEST(RoundTest, TowardsOddF32) {
    ASSERT_FLOAT_EQ(mpa::round::towards_odd(2.0f), 2.0f);
    ASSERT_FLOAT_EQ(mpa::round::towards_odd(2.1f), 2.0f);
    ASSERT_FLOAT_EQ(mpa::round::towards_odd(2.5f), 3.0f); // Rounds to odd
    ASSERT_FLOAT_EQ(mpa::round::towards_odd(3.5f), 3.0f); // Already odd, no change
    ASSERT_FLOAT_EQ(mpa::round::towards_odd(2.9f), 3.0f);
    ASSERT_FLOAT_EQ(mpa::round::towards_odd(-2.5f), -3.0f); // Rounds to odd
    ASSERT_FLOAT_EQ(mpa::round::towards_odd(-3.5f), -3.0f); // Already odd, no change
    ASSERT_FLOAT_EQ(mpa::round::towards_odd(0.5f), 1.0f);   // Rounds to odd
    ASSERT_FLOAT_EQ(mpa::round::towards_odd(-0.5f), -1.0f); // Rounds to odd
}

TEST(RoundTest, TowardsOddF64) {
    ASSERT_DOUBLE_EQ(mpa::round::towards_odd(2.5), 3.0);
    ASSERT_DOUBLE_EQ(mpa::round::towards_odd(3.5), 3.0);
    ASSERT_DOUBLE_EQ(mpa::round::towards_odd(-2.5), -3.0);
    ASSERT_DOUBLE_EQ(mpa::round::towards_odd(-3.5), -3.0);
    ASSERT_DOUBLE_EQ(mpa::round::towards_odd(0.5), 1.0);
}

// --- Test Cases for mpa::round::ceil ---
TEST(RoundTest, CeilF32) {
    ASSERT_FLOAT_EQ(mpa::round::ceil(2.1f), 3.0f);
    ASSERT_FLOAT_EQ(mpa::round::ceil(2.0f), 2.0f);
    ASSERT_FLOAT_EQ(mpa::round::ceil(-2.1f), -2.0f);
    ASSERT_FLOAT_EQ(mpa::round::ceil(-2.0f), -2.0f);
    ASSERT_FLOAT_EQ(mpa::round::ceil(0.0f), 0.0f);
    ASSERT_FLOAT_EQ(mpa::round::ceil(0.0000001f), 1.0f);
    ASSERT_FLOAT_EQ(mpa::round::ceil(-0.0000001f), -0.0f);
}

TEST(RoundTest, CeilF64) {
    ASSERT_DOUBLE_EQ(mpa::round::ceil(3.1), 4.0);
    ASSERT_DOUBLE_EQ(mpa::round::ceil(-3.1), -3.0);
    ASSERT_DOUBLE_EQ(mpa::round::ceil(0.0), 0.0);
}

// --- Test Cases for mpa::round::floor ---
TEST(RoundTest, FloorF32) {
    ASSERT_FLOAT_EQ(mpa::round::floor(2.1f), 2.0f);
    ASSERT_FLOAT_EQ(mpa::round::floor(2.0f), 2.0f);
    ASSERT_FLOAT_EQ(mpa::round::floor(-2.1f), -3.0f);
    ASSERT_FLOAT_EQ(mpa::round::floor(-2.0f), -2.0f);
    ASSERT_FLOAT_EQ(mpa::round::floor(0.0f), 0.0f);
    ASSERT_FLOAT_EQ(mpa::round::floor(0.999999f), 0.0f);
    ASSERT_FLOAT_EQ(mpa::round::floor(-0.0000001f), -1.0f);
}

TEST(RoundTest, FloorF64) {
    ASSERT_DOUBLE_EQ(mpa::round::floor(3.9), 3.0);
    ASSERT_DOUBLE_EQ(mpa::round::floor(-3.9), -4.0);
    ASSERT_DOUBLE_EQ(mpa::round::floor(0.0), 0.0);
}

// Main function to run all tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
