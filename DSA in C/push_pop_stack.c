#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int size;
    int top;
    int *arr;
};

int stack_is_empty (struct Stack *ptr){
    if (ptr->top == -1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

int stack_is_full (struct Stack *ptr)
{
    if (ptr->top == ptr->size - 1){
        return 1;
    }
    else{
        return 0;
    }
}

void display(struct Stack *ptr)
{
    if (stack_is_empty(ptr)){
        printf("The stack is empty\n");
    }
    else{
        for (int i = ptr->top; i >= 0; i--){
            printf("%d\n", ptr->arr[i]);
        }
        
    }    
}

void push (struct Stack *ptr, int data)
{
    if (stack_is_full(ptr)) {
        printf("Stack Overflow\n");
    }
    else {
        ptr->top++;
        ptr->arr[ptr->top] = data;
    }
}

int pop (struct Stack *ptr){
    if (stack_is_empty(ptr)){
        printf("Cannot pop from the stack\n");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int main ()
{
    struct Stack *s = (struct Stack *) malloc(sizeof(struct Stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    printf("Before pushing: %d\n", stack_is_empty(s));
    printf("Before pushing: %d\n", stack_is_full(s));

    push(s, 11);
    push(s, 22);
    push(s, 33);
    push(s, 44);
    push(s, 55);
    display(s);

    printf("After pushing: %d\n", stack_is_empty(s));
    printf("After pushing: %d\n", stack_is_full(s));

    return 0;
}