#ifndef TESTER_H
#define TESTER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLOR_FAILED    "\x1b[31m"
#define COLOR_PASSED    "\x1b[32m"
#define COLOR_RESET     "\x1b[0m"

#define MAX_STRING_SIZE 2048

extern int testCount;
extern int failedTestCount;
extern int passedTestCount;

typedef enum {
    TYPE_INT,
    TYPE_STRING
} TestDataType;

typedef enum {
    TEST_PASSED,
    TEST_FAILED
} TestStatus;

typedef struct {
    TestStatus result;
    TestDataType type;
    union {
        int intExpected;
        const char * strExpected;
    } expected;
    union {
        int intActual;
        const char * strActual;
    } actual;
} TestResult;

void test(const char * testName, int (*testFunc)());
void print_report();

TestResult assert_equal_int(int expected, int actual);
TestResult assert_equal_str(const char * expected, const char * actual);

#define START_TEST() TestResult * test_result = malloc(sizeof(TestResult));
#define END_TEST() free(test_result); return 1;

#define START_TEST_SUITE(title) printf("\n=== %s TEST SUITE ===\n\n", title);
#define END_TEST_SUITE() printf("\n=== END OF TEST SUITE ===\n\n");

#define ASSERT_EQ_INT(title, expectedValue, actualValue) { \
    *test_result = assert_equal_int(expectedValue, actualValue); \
    if (test_result->result == TEST_FAILED) { \
        printf("Assertion failed (%s): expected %d, got %d\n", title, test_result->expected.intExpected, test_result->actual.intActual); \
        free(test_result); \
        return 0; \
    } \
}

#define ASSERT_EQ_STR(title, expectedValue, actualValue) { \
    *test_result = assert_equal_str(expectedValue, actualValue); \
    if (test_result->result == TEST_FAILED) { \
        printf("Assertion failed (%s): expected \"%s\", got \"%s\"\n", title, test_result->expected.strExpected, test_result->actual.strActual); \
        free(test_result); \
        return 0; \
    } \
}

#endif // TESTER_H