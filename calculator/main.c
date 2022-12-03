#include <stdio.h>
#include <stdlib.h>
#include "calc.h"
#include "math_expression.h"


int main () 
{
    struct math_expression* math_expression = create_math_expression();
    save_user_input(math_expression);
    
    int validate_status = validate_math_expression(math_expression);

    if (validate_status == -2)
    {
        print_math_expression(math_expression);
        printf("Error:\nWrong input.\n");
    }
    else if (validate_status != -1)
    {
        print_input_error(math_expression, validate_status);
    }
    
    return 0;
}
