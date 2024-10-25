
#include "../include/mystring.h"
#include <math.h>
char* mystrcpy( char *target_string,
                char *source_string,
                unsigned int target_string_length,
                unsigned int source_string_length,
                char *off_set)
{

    char *ptr1 = off_set;
    char *ptr2 = source_string;
    if(source_string_length > target_string_length)
        return ptr1;
    while(*ptr2 != '\0')
    {
        *ptr1 = *ptr2;
        ptr1++;
        ptr2++;
        if((unsigned int)(ptr1 - target_string) > target_string_length)
            return ptr1;
    }
    *ptr1 = '\0';
    return ptr1;
}

unsigned int string_to_unsigned(char *s, unsigned int len)
{
    unsigned int temp = 0;
    for(unsigned int i=0;i<len;i++)
        temp += (s[i]-'0')*pow(10, len - i - 1);
    return temp;
}
