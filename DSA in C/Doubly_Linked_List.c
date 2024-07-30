#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* prev;
    struct Node* next;
};

void traversal (struct Node* head)
{
    struct Node* p = head;
    while (p != NULL)
    {
        printf("The element is: %d\n", p->data);
        p = p->next;
    }
}

int main ()
{
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));
    struct Node* fourth = (struct Node*)malloc(sizeof(struct Node));
    struct Node* fifth = (struct Node*)malloc(sizeof(struct Node));

    head->data = 11;
    head->prev = NULL;
    head->next = second;
    second->data = 22;
    second->prev = head;
    second->next = third;
    third->data = 33;
    third->prev = second;
    third->next = fourth;
    fourth->data = 44;
    fourth->prev = third;
    fourth->next = fifth;
    fifth->data = 55;
    fifth->prev = fourth;
    fifth->next = NULL;

    traversal(head);

    return 0;
}