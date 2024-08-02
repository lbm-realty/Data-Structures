#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
    int size;
    int top;
    char *arr;
};

int stackTop (struct Stack* ptr) {
    return ptr->arr[ptr->top];
}

int isEmpty(struct Stack* ptr) {
    return ptr->top == -1;
}

int isFull(struct Stack* ptr) {
    return ptr->top == ptr->size - 1;
}

void push(struct Stack* ptr, int value) {
    if(isFull(ptr))
        printf("Stack Overflow\n");
    else {
        ptr->top++;
        ptr->arr[ptr->top] = value;  
    }
}

char pop(struct Stack* ptr) {
    if(isEmpty(ptr)) {
        printf("Stack Underflow\n");
        return '\0';  
    } else {
        char value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}

int precedence(char ch) {
    if (ch == '*' || ch == '/') {
        return 3;
    } else if (ch == '+' || ch == '-') {
        return 2;
    } else {
        return 0;
    }
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

char* infixToPostfix(char* infix) {
    struct Stack* p = (struct Stack *)malloc(sizeof(struct Stack));
    p->size = 10;
    p->top = -1;
    p->arr = (char *)malloc(p->size * sizeof(char));
    char* postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0;
    int j = 0;

    while (infix[i] != '\0') {
        if (!isOperator(infix[i])) {
            postfix[j] = infix[i];
            i++;
            j++;
        } else {
            while (!isEmpty(p) && precedence(infix[i]) <= precedence(stackTop(p))) {
                postfix[j] = pop(p);
                j++;
            }
            push(p, infix[i]);
            i++;
        }
    }

    while (!isEmpty(p)) {
        postfix[j] = pop(p);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main() {
    char* infix = "a-b+t/6";
    printf("Postfix: %s\n", infixToPostfix(infix));
    return 0;
}
