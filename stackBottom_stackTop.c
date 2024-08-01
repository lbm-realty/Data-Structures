#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int size;
    int top;
    int *arr;
};

int stack_is_empty (struct Stack *ptr) {
    if (ptr->top == -1)
        return 1;
    else
        return 0;
}

int stack_is_full (struct Stack *ptr) {
    if (ptr->top == ptr->size-1)
        return 1;
    else 
        return 0;
}

void display(struct Stack *ptr) {
    if (stack_is_empty(ptr))
        printf("The stack is empty\n");
    else {
        for (int i = ptr->top; i >= 0; i--){
            printf("%d\n", ptr->arr[i]);
        }
    }    
}

int stackTop (struct Stack *ptr){
    return ptr->arr[ptr->top];
}

int stackBottom (struct Stack *ptr){
    return ptr->arr[0];
}

int main () {
    struct Stack *s;
    s->size = 80;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    s->arr[0] = 11;
    s->top++;
    s->arr[1] = 22;
    s->top++;
    s->arr[2] = 33;
    s->top++;
    s->arr[3] = 44;
    s->top++;

    display(s);
    printf("%d\n", stackTop(s));
    printf("%d\n", stackBottom(s));

    return 0;
}