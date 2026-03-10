#include "tester.h"

#include "../../src/lib/convert.h"

// HappyPathTest
int test_happy_path()
{
    START_TEST();
    ASSERT_EQ_INT("Happy path test", 4, 2 + 2);
    END_TEST();
}

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

int conv_int_to_str__valid_negative_integer()
{
    START_TEST();
    int value = -12345;
    const char * expected = "-12345";
    char * result = conv_int_to_str(value);
    ASSERT_EQ_STR("Negative integer strings are equal", expected, result);
    END_TEST();
}

void run_test_convert()
{
    START_TEST_SUITE("Convert.h");
    test("HappyPathTest", test_happy_path);
    test("StrToInt__ValidPositiveIntegerTest", conv_str_to_int__valid_positive_integer);
    test("StrToInt__ValidNegativeIntegerTest", conv_str_to_int__valid_negative_integer);
    test("IntToStr__ValidPositiveIntegerTest", conv_int_to_str__valid_positive_integer);
    test("IntToStr__ValidNegativeIntegerTest", conv_int_to_str__valid_negative_integer);
    END_TEST_SUITE();
}
