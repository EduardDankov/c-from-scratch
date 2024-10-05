#include <unistd.h>

#include "lib/memory.h"
#include "lib/string.h"
#include "lib/output.h"

const char * DEFAULT_APP_TITLE = "dkv";
const char * WRONG_ARGUMENT_COUNT = "Error: Wrong argument count.";

int main(int argc, char ** argv)
{
    char * title;
    char title_size;

    switch (argc)
    {
        case 1:
        {
            title_size = str_size(DEFAULT_APP_TITLE);
            title = mem_alloc(title_size * sizeof(char) + 1);
            str_copy(title, DEFAULT_APP_TITLE);
            break;
        }
        case 2:
        {
            title_size = str_size(argv[1]);
            title = mem_alloc(title_size * sizeof(char) + 1);
            str_copy(title, argv[1]);
            break;
        }
        default:
        {
            print_str_ln(WRONG_ARGUMENT_COUNT);
            _exit(1);
        }
    }
 
    print_str_ln(title);

    mem_free(title);
    return 0;
}

