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


int validate_user_input(struct user_input* head)
{
    /* 
    return -1 if validate success.
    return positive number validate error.
        the number returned is the position of the error in the string. 
    */

    while (head)
    {
        char element = head->value;
        if (!_validate_char(element))
            return 0;

        head = head->next;
    }

    return -1;
}
