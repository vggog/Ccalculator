#include <stdio.h>
#include <stdlib.h>
#include "calc.h"
#include "math_expression.h"


int main () 
{
    struct raw_math_expression* raw_math_expression = create_raw_math_expression();
    save_user_input(raw_math_expression);
    
    int validate_status = validate_math_expression(raw_math_expression);

    if (validate_status == -2)
    {
        print_raw_math_expression(raw_math_expression);
        printf("Error:\nWrong input.\n");
    }
    else if (validate_status != -1)
    {
        print_input_error(raw_math_expression, validate_status);
    }
    
    return 0;
}
