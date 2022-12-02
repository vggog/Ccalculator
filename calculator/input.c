#include <stdio.h>
#include <stdlib.h>
#include "calc.h"


struct user_input* _new_node (char key)
{
    struct user_input* node = (struct user_input*)malloc(sizeof(struct user_input));
    node->value = key;
    node->next = NULL;

    return node;
}


void _append (struct user_input** head, char value)
{
    struct user_input* current = *head;
    struct user_input* node = _new_node(value);

    if (current == NULL) 
        *head = node;

    else 
    {
        while (current->next != NULL) 
            current = current->next;

        current->next = node;
    }
}


struct user_input* get_user_input (struct user_input *head)
{
    char c;
    struct user_input *first_element = head;

    printf("Input: ");

    while ((c=getchar()) != EOF && c != '\n')
    {
        if (c == ' ' && c == '\n' && c == '\t')
            continue;
        
        _append(&head, c);

        if (!first_element)
            first_element = head;
    }
    
    return first_element;
}
