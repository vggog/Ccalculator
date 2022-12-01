#include <stdio.h>
#include <stdlib.h>
#include "calc.h"


void print_linced_list (struct user_input *head)
{
    while (head)
    {
    	printf("%c ", head->value);
    	head = head -> next;
    }
    printf("\n");
}


int main () 
{
    struct user_input *head = NULL;

    struct user_input *head_user_input = get_user_input(head);
    print_linced_list(head_user_input);

    return 0;
}