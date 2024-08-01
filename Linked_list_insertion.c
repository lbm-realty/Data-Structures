#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void linked_list_traversal (struct Node* ptr)
{
    while (ptr != NULL)
    {
        printf("The element is: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// CASE - 1:
struct Node* insert_in_the_beginning (struct Node* head, int data)
{
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

// CASE - 2:
struct Node* insert_at_index (struct Node* head, int data, int index)
{
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = head;
    int i = 0;
    while (i != (index - 1))
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

// CASE - 3:
struct Node* insert_at_end (struct Node* head, int data)
{
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node* p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

// CASE - 4:
// In the exmaple below, head isn't absolutely necessary, we're taking it for simplicity purposes.
// Taking the head doesn't really matter as we already know the node after which we want to insert our new node.

struct Node* insert_after_node (struct Node* head, struct Node* prev_node, int data) 
{
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prev_node->next;
    prev_node->next = ptr;

    return head;
}

int main ()
{
    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;

    head = (struct Node*)malloc(sizeof(struct Node)); 
    second = (struct Node*)malloc(sizeof(struct Node)); 
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));

    head->data = 11;
    head->next = second;

    second->data = 22;
    second->next = third;

    third->data = 33;
    third->next = fourth;

    fourth->data = 44;
    fourth->next = NULL;

    linked_list_traversal(head);
    // head = insert_in_the_beginning(head, 00);
    // head = insert_at_index(head, 88, 2);
    // head = insert_at_end(head, 99);
    head = insert_after_node(head, third, 99);
    printf("This is the new linked list: \n");
    linked_list_traversal(head);
    return 0;
}