#include <stdio.h>

#include "lib/tester.h"

#include "lib/test_convert.h"
#include "lib/test_math.h"

int main()
{
    printf("Starting test execution.\n");
    run_test_convert();
    run_test_math();

    printf("\n=== TEST REPORT ===\n\n");
    print_report();

    if (failedTestCount > 0)
    {
        printf(COLOR_FAILED"%d/%d TESTS FAILED!\n"COLOR_RESET, failedTestCount, testCount);
        return 1;
    }
    printf(COLOR_PASSED"%d/%d TESTS PASSED!\n"COLOR_RESET, passedTestCount, testCount);
    return 0;
}
