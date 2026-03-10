#include <unistd.h>

#include "lib/memory.h"
#include "lib/string.h"
#include "lib/io.h"

const char * DEFAULT_APP_TITLE = "dkv";
const char * WRONG_ARGUMENT_COUNT = "Error: Wrong argument count.";

int main(int argc, char ** argv)
{
    char * title;
    int titleSize;

    switch (argc)
    {
        case 1:
        {
            titleSize = str_size(DEFAULT_APP_TITLE);
            title = mem_alloc(titleSize * sizeof(char) + 1);
            str_copy(title, DEFAULT_APP_TITLE);
            break;
        }
        case 2:
        {
            titleSize = str_size(argv[1]);
            title = mem_alloc(titleSize * sizeof(char) + 1);
            str_copy(title, argv[1]);
            break;
        }
        default:
        {
            io_println(WRONG_ARGUMENT_COUNT);
            _exit(1);
        }
    }
 
    io_println(title);

    mem_free(title);
    return 0;
}

