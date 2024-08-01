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

struct Node* inserting_in_the_beg (struct Node* head, int data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = head;

    int i = 0;
    while (p->next != head)
    {
        p = p->next;
        i++;
    }

    new_node->next = head;
    new_node->data = data;
    p->next = new_node;

    return new_node; 
}

struct Node* inserting_in_the_middle (struct Node* head, int index, int data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = head;

    int i = 0;
    while (i != (index - 1))
    {
        p = p->next;
        i++;
    }

    new_node->data = data;
    new_node->next = p->next;
    p->next = new_node;

    return head;
}

struct Node* inserting_at_the_end (struct Node* head, int data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = head;

    while (p->next != head)
    {
        p = p->next;
    }

    p->next = new_node;
    new_node->data = data;
    new_node->next = head;

    return head;
}

struct Node* inserting_after_node (struct Node* head, int index, int data)
{   
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = head;

    int i = 0;
    while (i != index)
    {
        p = p->next;
        i++;
    }

    new_node->data = data;
    new_node->next = p->next;
    p->next = new_node;

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
    // head = inserting_in_the_beg(head, 66);
    // head = inserting_in_the_middle(head, 2, 77);
    // head = inserting_at_the_end(head, 88);
    head = inserting_after_node(head, 2, 99);
    printf("This is the list after modification: \n");
    traversal(head);
    return 0;
}