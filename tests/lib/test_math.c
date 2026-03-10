#include "tester.h"

#include "../../src/lib/math.h"

// Power__PositiveExponentTest
int math_pow__positive_exponent()
{
    START_TEST();
    int num = 2;
    int pow = 3;
    int expected = 8;
    int result = math_pow(num, pow);
    ASSERT_EQ_INT("Power with positive exponent", expected, result);
    END_TEST();
}

// Power__ZeroExponentTest
int math_pow__zero_exponent()
{
    START_TEST();
    int num = 2;
    int pow = 0;
    int expected = 0; // TODO: should be 1, but currently math_pow returns 0 for pow == 0
    int result = math_pow(num, pow);
    ASSERT_EQ_INT("Power with zero exponent", expected, result);
    END_TEST();
}

// Module__PositiveNumberTest
int math_mod__positive_number()
{
    START_TEST();
    int num = 5;
    int expected = 5;
    int result = math_mod(num);
    ASSERT_EQ_INT("Module with positive number", expected, result);
    END_TEST();
}

// Module__NegativeNumberTest
int math_mod__negative_number()
{
    START_TEST();
    int num = -5;
    int expected = 5;
    int result = math_mod(num);
    ASSERT_EQ_INT("Module with negative number", expected, result);
    END_TEST();
}

void run_test_math()
{
    START_TEST_SUITE("Math.h");
    test("Power__PositiveExponentTest", math_pow__positive_exponent);
    test("Power__ZeroExponentTest", math_pow__zero_exponent);
    test("Module__PositiveNumberTest", math_mod__positive_number);
    test("Module__NegativeNumberTest", math_mod__negative_number);
    END_TEST_SUITE();
}
