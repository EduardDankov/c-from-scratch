include <unistd.h>

typedef struct mem_free_block
{
    int size;
    struct mem_free_block * next;
} mem_free_block;

static mem_free_block mem_free_block_list_head = {0, 0};
static const int overhead = sizeof(int);
static const int align_to = 16;

void * mem_alloc(int size)
{
    // Trick to round the size to the nearest multiple of align_to that is larger than size
    // Only works if align_to is a power of 2
    size = (size + sizeof(int) + (align_to - 1)) & - (align_to - 1);

    mem_free_block * block = mem_free_block_list_head.next;
    mem_free_block ** head = &(mem_free_block_list_head.next);

    while (block != 0)
    {
        if (block->size >= size)
        {
            *head = block->next;
            return ((char *)block) + sizeof(int);
        }
        head = &(block->next);
        block = block->next;
    }

    block = (mem_free_block *)sbrk(size);
    block->size = size;

    return ((char *)block) + sizeof(int);
}

void mem_free(void * ptr)
{
    mem_free_block * block = (mem_free_block *)(((char *)ptr) - sizeof(int));
    block->next = mem_free_block_list_head.next;
    mem_free_block_list_head.next = block;
}

const char * DEFAULT_APP_TITLE = "dkv";

int str_size(const char * str)
{
    int size = 0;
    while (*str != 0)
    {
        str++;
        size++;
    }
    return size;
}

void print_c(const char c)
{
    write(1, &c, 1);
}

void print_ln()
{
    print_c('\n');
}

void print_str_sz(const char * str, const int size)
{
    for (int i = 0; i < size; i++)
    {
        print_c(str[i]);
    }
}

void print_str_sz_ln(const char * str, const int size)
{
    print_str_sz(str, size);
    print_ln();
}

char * str_copy(char * dest, const char * src)
{
    char * tmp = dest;
    while ((*dest++ = *src++) != 0);
    return tmp;
}

void print_str(const char * str)
{
    print_str_sz(str, str_size(str));
}

void print_str_ln(const char * str)
{
    print_str_sz_ln(str, str_size(str));
}

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
            _exit(1);
        }
    }
 
    print_str_ln(title);

    mem_free(title);
    return 0;
}

