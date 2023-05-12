#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next, *prev;
};

void traversal(struct node *head)
{
    struct node *p;
    p = head;
    while (p->next != NULL)
    {
        printf("\n%d\n", p->data);
        p = p->next;
    }
    printf("\n%d\n", p->data);
}
int main()
{
    struct node *head, *body, *tail;
    head = (struct node *)malloc(sizeof(struct node));
    body = (struct node *)malloc(sizeof(struct node));
    tail = (struct node *)malloc(sizeof(struct node));

    head->prev = NULL;
    head->data = 68;
    head->next = body;

    body->prev = head;
    body->data = 80;
    body->next = tail;

    tail->prev = body;
    tail->data = 81;
    tail->next = NULL;

    display(head);

    return 0;
}