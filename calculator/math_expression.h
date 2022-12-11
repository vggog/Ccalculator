#ifndef MATH_EXPRESSION_DEFINE
#define MATH_EXPRESSION_DEFINE
struct char_of_raw_math_expression
{
    char value;
    int index;
    struct char_of_raw_math_expression *next;
    struct char_of_raw_math_expression *before;
};

struct raw_math_expression
{
    int len;
    struct char_of_raw_math_expression *head;
    struct char_of_raw_math_expression *end;
};

struct raw_math_expression* create_raw_math_expression ();
void print_raw_math_expression (struct raw_math_expression* math_expression);

#endif
