#ifndef MATH_EXPRESSION_DEFINE
#define MATH_EXPRESSION_DEFINE
struct char_of_math_expression
{
    char value;
    int index;
    struct char_of_math_expression *next;
};

struct math_expression
{
    int len;
    struct char_of_math_expression *head;
    struct char_of_math_expression *end;
};

struct math_expression* create_math_expression ();
void print_math_expression (struct math_expression* math_expression);

#endif
