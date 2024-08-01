#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};

void traversal (struct Node* head)
{
    struct Node* ptr = head;
    do 
    {
        printf("The element is: %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

int main ()
{
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));
    struct Node* fourth = (struct Node*)malloc(sizeof(struct Node));
    struct Node* fifth = (struct Node*)malloc(sizeof(struct Node));

    head->data = 11;
    head->next = second;
    second->data = 22;
    second->next = third;
    third->data = 33;
    third->next = fourth;
    fourth->data = 44;
    fourth->next = fifth;
    fifth->data = 55;
    fifth->next = head;

    traversal(head);
    return 0;
}