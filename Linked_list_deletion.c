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

struct Node* delete_head (struct Node* head)
{
    struct Node* p = head;
    head = head->next;
    free(p);
    return head;
}

struct Node* delete_index (struct Node* head, int index)
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

struct Node* delete_last_node (struct Node* head)
{
    struct Node* p = head; 
    struct Node* q = head->next;

    int i = 0;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    
    p->next = NULL;
    free(q);
    return head;
}

struct Node* delete_given_value (struct Node* head, int value)
{
    struct Node* p = head;
    struct Node* q = head->next;

    int i = 0;
    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
        i++;
    }

    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }
    return head;
}

int main ()
{
    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;
    struct Node* fifth;

    head = (struct Node*)malloc(sizeof(struct Node)); 
    second = (struct Node*)malloc(sizeof(struct Node)); 
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));
    fifth = (struct Node*)malloc(sizeof(struct Node));

    head->data = 11;
    head->next = second;

    second->data = 22;
    second->next = third;

    third->data = 33;
    third->next = fourth;

    fourth->data = 44;
    fourth->next = fifth;

    fifth->data = 55;
    fifth->next = NULL;


    linked_list_traversal(head);
    // head = delete_head(head);
    // head = delete_index(head, 2);
    // head = delete_last_node(head);
    head = delete_given_value(head, 44);
    printf("This is the new linked list: \n");
    linked_list_traversal(head);
    return 0;
}