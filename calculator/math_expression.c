#include <stdio.h>
#include <stdlib.h>
#include "math_expression.h"


void print_math_expression (struct math_expression* math_expression)
{
    /*
    Outputs a mathematical expression to a string.
    */
    struct char_of_math_expression* element = math_expression->head;
    while (element)
    {
    	printf("%c", element->value);
    	element = element -> next;
    }
    printf("\n");
}


struct char_of_math_expression* _new_char (char key, int index)
{
    /*
    Create a new char_of_math_expression structure.
    */
    struct char_of_math_expression* node = (struct char_of_math_expression*)malloc(sizeof(struct char_of_math_expression));
    node->value = key;
    node->index = index;
    node->next = NULL;

    return node;
}


void append_char (struct char_of_math_expression** element, char value, int index)
{
    /*
    Add char to the math expression.
    */
    struct char_of_math_expression* current = *element;
    struct char_of_math_expression* node = _new_char(value, index);

    if (current == NULL) 
        *element = node;

    else 
    {
        while (current->next != NULL) 
            current = current->next;

        current->next = node;
    }
}


struct math_expression* create_math_expression ()
{
    /*
    Create empty math structure.
    */
    struct math_expression* expression = (struct math_expression*)malloc(sizeof(struct math_expression));
    expression->head = NULL;
    return expression;
}
