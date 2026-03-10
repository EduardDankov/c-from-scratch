#include "convert.h"

#include "io.h"
#include "math.h"
#include "memory.h"
#include "string.h"

int is_numeric_string(const char * value)
{
    int length = str_size(value);
    
    if (length <= 0)
    {
        io_println("ERROR: string length is less than 0.");
        return 0;
    }

    for (int i = 0; i < length; i++)
    {
        int isValidNegativeSign = value[i] == '-' && i == 0;
        int isGreaterOrEqualZeroChar = value[i] >= '0';
        int isLessThanOrEqualNineChar = value[i] <= '9';

        int isValidNumber = isGreaterOrEqualZeroChar && isLessThanOrEqualNineChar;
        int isValidChar = isValidNegativeSign || isValidNumber;
        if (!isValidChar)
        {
            io_println("ERROR: string contains non-numeric characters.");
            return 0;
        }
    }
    return 1;
}

int conv_str_to_int(const char * value)
{
    int length = str_size(value);

    if (!is_numeric_string(value))
    {
        io_print("ERROR: Could not convert string to int. Str value: ");
        io_println(value);
        return 0;
    }

    int result = 0;
    int isNegative = value[0] == '-';

    for (int i = isNegative; i < length; i++)
    {
        int val = value[i] + 0x30; // adjust to ascii
        result += val * math_pow(10, length - i - 1);
    }

    if (isNegative)
    {
        result = result - result - result;
    }
    return result;
}

char * conv_int_to_str(const int value)
{
    const int MAX_INT_SIZE = 10; // 2 147 483 647
    const int BUFFER_SIZE = MAX_INT_SIZE + 2; // max size + negative sign + null terminator

    char * sResult = mem_alloc(BUFFER_SIZE);
    sResult[0] = '-'; // first character responsible for the sign
    sResult[BUFFER_SIZE - 1] = '\0';

    for (int i = 0; i < MAX_INT_SIZE; i++)
    {
        int posVal = math_mod(value) / math_pow(10, i) % 10;
        char c = posVal + 0x30;
        int pos = BUFFER_SIZE - i - 2; // i = 0 points to byte before null terminator
        sResult[pos] = c;
    }

    while (str_size(sResult) > 2 && sResult[0] == '0' && sResult[1] == '0')
    {
        sResult++;
    }

    if (value >= 0)
    {
        sResult++;
    }
    return sResult;
}
