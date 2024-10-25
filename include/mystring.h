#ifndef MYSTRING_H_INCLUDED
#define MYSTRING_H_INCLUDED

/**
*   @Param target_string: target string;
*   @Param source_string: source string;
*   @Param target_string_length: target string length;
*   @Param source_string_length: source string length;
*   @Param off_set: the index point for target string;
*   function : copy source_string to string1;
*   return   : return the current last element point;
*   attention: Content that has already been copied will not be overwritten.
**/

char* mystrcpy( char *target_string,
                char *source_string,
                unsigned int target_string_length,
                unsigned int source_string_length,
                char *off_set);

unsigned int string_to_unsigned(char *s, unsigned int len);

#endif // MYSTRING_H_INCLUDED
