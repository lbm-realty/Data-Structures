#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int size;
    int rear;
    int front;
    int* arr;
};

int isFull(struct Queue* ptr){
    if (ptr->front == ptr->size - 1)
        return 1;
    return 0;
}

int isEmpty(struct Queue* ptr){
    if (ptr->rear == -1)
        return 1;
    return 0;
}

void display(struct Queue* ptr){
    int i = ptr->front++;
    while(i != ptr->rear + 1){
        printf("The value is: %d\n", ptr->arr[i]);
        i++;
    }
}

void enqueue(struct Queue* ptr, int value){
    if (isFull(ptr))
        printf("The Queue is full\n");
    else {
        ptr->rear++;
        ptr->arr[ptr->rear] = value;
    }
}

int dequeue(struct Queue* ptr){
    if (isEmpty(ptr))
        printf("The queue is empty\n");
    else{
        ptr->front++;
        int n = ptr->arr[ptr->front];
        return n;
    }
}

int main() {
    struct Queue* q = (struct Queue *)malloc(sizeof(struct Queue));
    q->size = 100;
    q->front = q->rear = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

    enqueue(q, 11);
    enqueue(q, 22);
    enqueue(q, 33);
    enqueue(q, 44);
    enqueue(q, 55);

    dequeue(q);

    display(q);

    return 0;
}