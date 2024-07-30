#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *arr;
};

int stack_is_empty (struct Stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int stack_is_full (struct Stack *ptr)
{
    if (ptr->top == ptr->size-1)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

int main ()
{
    struct Stack *s;
    s->size = 80;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    s->arr[0] = 11;
    s->top++;

    if (stack_is_empty(s))
    {
        printf("The stack is empty");
    }
    else
    {
        printf("The stack is not empty");
    }

    return 0;
}