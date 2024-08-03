#include <stdio.h>
#include <stdlib.h>

struct QNode *front = NULL;
struct QNode *rear = NULL;

struct QNode {
    int data;
    struct node* next;
};

void display(struct QNode *ptr)
{
    while (ptr != NULL){
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void enqueue(int value){
    struct QNode* n = (struct QNode *)malloc(sizeof(struct QNode));
    if (n == NULL)
        printf("The Queue is full\n");
    else {
        n->data = value;
        n->next = NULL;
        if (front == NULL){
            front = rear = n;
        } else {
            rear->next = n;
            rear = n;
        }
    }
}

int dequeue(){
    int value = -1;
    struct QNode* ptr = front;
    if (front == NULL)
        printf("The Queue is empty\n");
    else {
        front = front->next;
        value = ptr->data;
        free(ptr);
        return value;
    }
}

int main () {
    enqueue(11);
    enqueue(22);
    enqueue(33);
    enqueue(44);
    enqueue(55);

    dequeue();
    
    display(front);

    return 0;
}