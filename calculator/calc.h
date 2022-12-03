#include "math_expression.h"


void save_user_input (struct math_expression* math_expression);
int validate_math_expression(struct math_expression* math_expression);
void append_char (struct char_of_math_expression** head, char value, int index);
void print_input_error(struct math_expression* math_expression, int error_index);
