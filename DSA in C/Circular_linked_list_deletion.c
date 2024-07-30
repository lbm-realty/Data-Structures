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

struct Node* deleting_the_head (struct Node* head)
{
    struct Node* p = head;
    struct Node* q = head->next;

    while (q != head)
    {
        p = p->next;
        q = q->next;      
    }

    p->next = q->next;
    free(q);

    return p;
}

struct Node* deleting_an_index (struct Node* head, int index)
{
    struct Node* p = head; 

    int i = 0;
    while (i != (index - 1))
    {
        p = p->next;
        i++;
    }

    struct Node* q = p->next;
    p->next = q->next;
    free(q);

    return head;
}

// Deleting the last node in my opinion is not really a thing as 
// in a cicular linked last there's no last node usnless you yourself know it
struct Node* deleting_last_node (struct Node* head)
{
    struct Node* p = head;
    struct Node* q = head->next;

    while (q->next != head)
    {
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q);

    return head;
}

struct Node* deleting_a_value (struct Node* head, int value)
{
    struct Node* p = head;
    struct Node* q = head->next;

    while (q->data != value)
    {
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q);

    return head;
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
    printf("This is the list after modification: \n");
    head = deleting_an_index(head, 4);
    // head = deleting_the_head(head);
    // head = deleting_last_node(head);
    // head = deleting_a_value(head, 44);
    traversal(head);

    return 0;
}