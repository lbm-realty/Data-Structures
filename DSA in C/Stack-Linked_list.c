#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void linked_list_traversal (struct Node* ptr) {
    while (ptr != NULL)
    {
        printf("The element is: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int is_full(struct Node *top){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    if (ptr == NULL)
        return 1;
    else
        return 0;
}

int is_empty(struct Node *top){
    if (top == NULL)
        return 1;
    else
        return 0;
}

struct Node *push(struct Node *top, int value){
    if (is_full(top))
        printf("Stack Overflow\n");
    else{
        struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
        ptr->data = value;
        ptr->next = top;
        top = ptr;
        return top;
    }      
}

int pop(struct Node** top){
    if (is_empty(*top))
        printf("Stack Underflow\n");
    else {
        struct Node* n = *top;
        *top = (*top)->next;
        int x = n->data;
        free(n);
        return x;
    }
}

int peek (struct Node* top){
    return top->data;
}

int main() {
    struct Node* top = NULL;
    top = push(top, 11);
    top = push(top, 22);
    top = push(top, 33);
    top = push(top, 44);

    int element = pop(&top);
    printf("The popped element is: %d\n", element);
    printf("This is the peek element: %d\n", peek(top));
    linked_list_traversal(top);

    return 0;
}