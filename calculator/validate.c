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


int _is_equal_math_brackets(int count_left_bracket, int count_right_bracket)
{
    return count_left_bracket == count_right_bracket;
}


int validate_math_expression(struct math_expression* math_expression)
{
    /* 
    return -1 if validate success.
    return -2 if count of left math bracket not equal right math bracket.
    return positive number validate error.
        the number returned is the position of the error in the string. 
    */
    int left_bracket = 0; // (
    int right_bracket = 0; // )
    struct char_of_math_expression* char_math_expression = math_expression->head;
    
    while (char_math_expression)
    {
        char element = char_math_expression->value;
        if (!_validate_char(element))
            return char_math_expression->index;

        if (element == '(')
            left_bracket++;
        else if (element == ')')
            right_bracket++;

        char_math_expression = char_math_expression->next;
    }

    if (!_is_equal_math_brackets(left_bracket, right_bracket))
        return -2;

    return -1;
}
