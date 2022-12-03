#include <stdio.h>
#include "calc.h"


int _validate_char(char chapter)
{
    switch (chapter)
    {
    case '0': case '1': case '2': case '3':
    case '4': case '5': case '6': case '7':
    case '8': case '9':
    case '+': case '-': case '*': case '/':
    case '(': case ')':
        return 1;
    }
    return 0;
}


int validate_math_expression(struct math_expression* math_expression)
{
    /* 
    return -1 if validate success.
    return positive number validate error.
        the number returned is the position of the error in the string. 
    */
    struct char_of_math_expression* char_math_expression = math_expression->head;
    
    while (char_math_expression)
    {
        char element = char_math_expression->value;
        if (!_validate_char(element))
            return 0;

        char_math_expression = char_math_expression->next;
    }

    return -1;
}
