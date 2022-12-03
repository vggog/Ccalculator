#include <stdio.h>
#include <stdlib.h>
#include "calc.h"
#include "math_expression.h"


int _is_control_character(char symbol)
{
    if (symbol == ' ' || symbol == '\n' || symbol == '\t')
        return 1;

    return 0;
}


void save_user_input (struct math_expression* math_expression)
{
    /*
    Saves user input to a struct math_expression.
    */
    int i = 0;
    char c;
    
    struct char_of_math_expression *head = math_expression->head;

    printf("Input: ");
    
    while ((c=getchar()) != EOF && c != '\n')
    {
        if (_is_control_character(c))
            continue;
        
        append_char(&head, c);

        if (!math_expression->head)
            math_expression->head = head;

        i++;
    }
    
    math_expression->len = i;
}
