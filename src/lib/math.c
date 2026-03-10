#include "math.h"

int math_pow(const int num, const int pow)
{
    if (pow == 0)
    {
        return 0;
    }

    if (pow == 1)
    {
        return num;
    }

    if (pow < 0)
    {
        return 0; // TODO: implement
    }

    int result = num;

    for (int i = 1; i < pow; i++)
    {
        result *= num;
    }
    return result;
}

int math_mod(const int num)
{
    if (num >= 0)
    {
        return num;
    }
    
    return num - num - num;
}
