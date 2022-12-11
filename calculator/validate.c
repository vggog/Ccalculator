#include <stdio.h>
#include "calc.h"


int _valide_char(char chapter)
{
    /*
    Valide char is a numbers(0-9) + - ( )
    */
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


int _is_this_number(char chapter)
{
    if (chapter >= '0' && chapter <= '9')
        return 1;
    return 0;
}


int _valide_before_brackets(char chapter, char before_chapter)
{
    /*
    Before left brackets must be operators, 
    but before ritght bracket must be numbers.
    */
    if (chapter == '(')
    {
        if (_is_this_number(before_chapter))
            return 0;
    }
    else if (chapter == ')')
    {
        if (!_is_this_number(before_chapter))
            return 0;
    }

    return 1;
}


int _validate_before_operators(char chapter, char before_chapter)
{
    /*
    Before operators must be numbers or left bracket.
    */
    if (chapter == '+' || chapter == '-' || chapter == '*' || chapter == '/')
    {
        if (!_is_this_number(before_chapter) && before_chapter != ')')
            return 0;
    }

    return 1;
}


int _validate_before_operations_and_brackets(struct char_of_raw_math_expression* struct_chapter)
{
    char chapter = struct_chapter->value;
    if (struct_chapter->index == 0)
    {
        if (_is_this_number(chapter) || chapter == '(')
            return 0;
        return 1;
    }
    
    struct char_of_raw_math_expression* before_struct_char = struct_chapter->before;
    char before_chapter = before_struct_char->value;

    if (!_valide_before_brackets(chapter, before_chapter))
        return struct_chapter->index;
    else if (!_validate_before_operators(chapter, before_chapter))
        return struct_chapter->index;

    if (struct_chapter->next == NULL)
    {
        if (!_is_this_number(chapter) && chapter != ')')
            return 1;
    }

    return 0;
}


int validate_math_expression(struct raw_math_expression* math_expression)
{
    /* 
    return -1 if validate success.
    return -2 if count of left math bracket not equal right math bracket.
    return positive number validate error.
        the number returned is the position of the error in the string. 
    */
    int left_bracket = 0; // (
    int right_bracket = 0; // )
    struct char_of_raw_math_expression* chapter = math_expression->head;
    
    while (chapter)
    {
        if (!_valide_char(chapter->value))
            return chapter->index;
        else if (_validate_before_operations_and_brackets(chapter))
            return chapter->index;
        
        if (chapter->value == '(')
            left_bracket++;
        else if (chapter->value == ')')
            right_bracket++;

        chapter = chapter->next;
    }

    if (!_is_equal_math_brackets(left_bracket, right_bracket))
        return -2;

    return -1;
}
