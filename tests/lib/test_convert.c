#include "tester.h"

#include "../../src/lib/convert.h"

// StrToInt__ValidPositiveIntegerTest
int conv_str_to_int__valid_positive_integer()
{
    START_TEST();
    const char * value = "12345";
    int expected = 12345;
    int result = conv_str_to_int(value);
    ASSERT_EQ_INT("Positive integers are equal", expected, result);
    END_TEST();
}

// StrToInt__ValidNegativeIntegerTest
int conv_str_to_int__valid_negative_integer()
{
    START_TEST();
    const char * value = "-12345";
    int expected = -12345;
    int result = conv_str_to_int(value);
    ASSERT_EQ_INT("Negative integers are equal", expected, result);
    END_TEST();
}

// IntToStr__ValidPositiveIntegerTest
int conv_int_to_str__valid_positive_integer()
{
    START_TEST();
    int value = 12345;
    const char * expected = "12345";
    char * result = conv_int_to_str(value);
    ASSERT_EQ_STR("Positive integer strings are equal", expected, result);
    END_TEST();
}

// IntToStr__ValidNegativeIntegerTest
int conv_int_to_str__valid_negative_integer()
{
    START_TEST();
    int value = -12345;
    const char * expected = "-12345";
    char * result = conv_int_to_str(value);
    ASSERT_EQ_STR("Negative integer strings are equal", expected, result);
    END_TEST();
}

// IntToStr__ZeroIntegerTest
int conv_int_to_str__zero_integer()
{
    START_TEST();
    int value = 0;
    const char * expected = "0";
    char * result = conv_int_to_str(value);
    ASSERT_EQ_STR("Zero integer string is equal", expected, result);
    END_TEST();
}

void run_test_convert()
{
    START_TEST_SUITE("Convert.h");

    // conv_str_to_int tests
    test("StrToInt__ValidPositiveIntegerTest", conv_str_to_int__valid_positive_integer);
    test("StrToInt__ValidNegativeIntegerTest", conv_str_to_int__valid_negative_integer);

    // conv_int_to_str tests
    test("IntToStr__ValidPositiveIntegerTest", conv_int_to_str__valid_positive_integer);
    test("IntToStr__ValidNegativeIntegerTest", conv_int_to_str__valid_negative_integer);
    test("IntToStr__ZeroIntegerTest", conv_int_to_str__zero_integer);

    END_TEST_SUITE();
}
