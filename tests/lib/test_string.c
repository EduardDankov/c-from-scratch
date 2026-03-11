#include "tester.h"

#include "../../src/lib/string.h"

// StrSize__ValidString
int str_size__valid_string()
{
    START_TEST();
    const char * sString = "Hello, world!";
    int expected = 13;
    int result = str_size(sString);
    ASSERT_EQ_INT("String sizes are equal", expected, result);
    END_TEST();
}

// StrSize__EmptyString
int str_size__empty_string()
{
    START_TEST();
    const char * sString = "";
    int expected = 0;
    int result = str_size(sString);
    ASSERT_EQ_INT("String sizes are equal", expected, result);
    END_TEST();
}

// StrSize__NullString
int str_size__null_string()
{
    START_TEST();
    const char * sString = NULL;
    int expected = 0;
    int result = str_size(sString);
    ASSERT_EQ_INT("String sizes are equal", expected, result);
    END_TEST();
}

// StrCopy__ValidValues
int str_copy__valid_values()
{
    START_TEST();
    const char * sSrc = "source";
    char * sDest = "dest";
    const char * sExpected = "destsource";
    const char * sResult = str_copy(sDest, sSrc);
    ASSERT_EQ_STR("Concatenated string is correct", sExpected, sResult);
    END_TEST();
}

void run_test_string()
{
    START_TEST_SUITE("String.h");

    // str_size tests
    test("StrSize__ValidString", str_size__valid_string);
    test("StrSize__EmptyString", str_size__empty_string);
    test("StrSize__NullString", str_size__null_string);

    // str_copy tests
    test("StrCopy__ValidValues", str_copy__valid_values);

    END_TEST_SUITE();
}

