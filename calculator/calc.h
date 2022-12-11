#include "math_expression.h"


void save_user_input (struct raw_math_expression* math_expression);
int validate_math_expression(struct raw_math_expression* math_expression);
void append_char (struct char_of_raw_math_expression** element, char value, int index);
void print_input_error(struct raw_math_expression* math_expression, int error_index);
