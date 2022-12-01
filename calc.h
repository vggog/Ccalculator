struct user_input
{
    char value;
    struct user_input *next;
};

struct user_input * get_user_input (struct user_input *head);
