#include <stdio.h>
#include <stdlib.h>
#include "calc.h"
#include "math_expression.h"


int _is_control_character(char symbol)
{
    /*
    control symbol is cpase " ", tabulation "\t" and line translation "\n"
    */
    if (symbol == ' ' || symbol == '\n' || symbol == '\t')
        return 1;

    return 0;
}


void save_user_input (struct raw_math_expression* math_expression)
{
    /*
    Saves user input to a struct math_expression.
    */
    int i = 0;
    char c;
    
    struct char_of_raw_math_expression *head = math_expression->head;

    printf("Input: ");
    
    while ((c=getchar()) != EOF && c != '\n')
    {
        if (_is_control_character(c))
            continue;
        
        append_char(&head, c, i);

        if (!math_expression->head)
            math_expression->head = head;

        i++;
    }
    
    math_expression->len = i;
}


void print_input_error(struct raw_math_expression* math_expression, int error_index)
{
    /*
    Print raw mathematic exception with showing position of error.  
    */ 
    int i;
    printf("Error:\n");
    print_raw_math_expression(math_expression);
    for (i = 0; i < math_expression->len; i++)
    {
        if (i == error_index)
        {
            printf("^");
            continue;
        }
        printf("~");
    }
    printf("\n");
}
