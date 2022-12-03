#include <stdio.h>
#include <stdlib.h>
#include "calc.h"
#include "math_expression.h"


int main () 
{
    struct math_expression* math_expression = create_math_expression();
    save_user_input(math_expression);
    
    printf("Len: %d\n", math_expression->len);
    if (validate_math_expression(math_expression) == -1)
    {
        printf("Good!\n");
    }
    else
    {
        printf("Baad\n");
    }
    print_math_expression(math_expression);

    return 0;
}
