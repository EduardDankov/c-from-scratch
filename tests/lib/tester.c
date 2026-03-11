#include "tester.h"

int testCount = 0;
int failedTestCount = 0;
int passedTestCount = 0;

void test(const char * testName, int (*testFunc)())
{
    testCount++;
    printf("Test %d: %s\n", testCount, testName);
    int result = testFunc();
    if (result)
    {
        passedTestCount++;
        printf(COLOR_PASSED"PASSED\n"COLOR_RESET);
    }
    else
    {
        failedTestCount++;
        printf(COLOR_FAILED"FAILED\n"COLOR_RESET);
    }
}

void print_report()
{
    printf("Total tests: %d\n", testCount);
    printf("Passed tests: %d\n", passedTestCount);
    printf("Failed tests: %d\n", failedTestCount);
}

TestResult assert_equal_int(int expected, int actual)
{
    TestStatus result = expected == actual ? TEST_PASSED : TEST_FAILED;

    return (TestResult){ 
        .result = result, 
        .type = TYPE_INT, 
        .expected = {.intExpected = expected}, 
        .actual = {.intActual = actual} 
    };
}

TestResult assert_equal_str(const char * expected, const char * actual)
{
    TestStatus result = actual != NULL && strcmp(expected, actual) == 0 ? TEST_PASSED : TEST_FAILED;

    return (TestResult){ 
        .result = result, 
        .type = TYPE_STRING, 
        .expected = {.strExpected = expected}, 
        .actual = {.strActual = actual} 
    };
}
