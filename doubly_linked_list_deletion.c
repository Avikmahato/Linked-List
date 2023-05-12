#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next, *prev;
};
void display(struct node *head)
{
    if (head != NULL)
        while (head != NULL)
        {
            printf("\n%d\n", head->data);
            head = head->next;
        }
    else
        printf("The Linked List Is Empty\n\n");
}
struct node *deletion(struct node *head)
{
    struct node *ptr;
    if (head != NULL)
    {
        ptr = head->next;
        ptr->prev = NULL;
        return ptr;
        if (ptr == NULL)
            head=NULL;
    }
    else
        printf("The Linked List Is Empty\n\n");
}
struct node *deletionm(struct node *head, int index)
{
    int x = 0;
    struct node *avik, *bapi;
    avik = head;

    if (head != NULL)
    {
        while (x != index - 1)
        {
            avik = avik->next;
            x++;
        }
        bapi = avik->next;
        avik->next = bapi->next;
        return head;
    }
    else
        printf("The Linked List Is Empty\n\n");
}
struct node *deletionend(struct node *head)
{
    struct node *avik = head, *bapi;
        while (avik->next != NULL)
        {
            avik = avik->next;
        }
        bapi = avik->prev;
        bapi->next = NULL;
        return head;
    
    
}
struct node *insertion(struct node *head, int data)
{
    struct node *avik;
    avik = (struct node *)malloc(sizeof(struct node));
    avik->data = data;
    avik->next = head;
    avik->prev = NULL;
    return avik;
}
int main()
{
    int chs, index, ele;
    struct node *head, *body, *tail;
    head = (struct node *)malloc(sizeof(struct node));
    body = (struct node *)malloc(sizeof(struct node));
    tail = (struct node *)malloc(sizeof(struct node));

    head->data = 68;
    head->prev = NULL;
    head->next = body;

    body->data = 80;
    body->prev = head;
    body->next = tail;

    tail->data = 81;
    tail->prev = body;
    tail->next = NULL;
    while (7)
    {
        printf("Doubly Linked List Deletion*********\n\n\n");
        printf("1 For Traversal        :\n");
        printf("2 For Deletion At First:\n");
        printf("3 For Deletion At Mid  :\n");
        printf("4 For Deletion At End  :\n");
        printf("5 For Insertion        :\n");
        printf("6 For Exit             :\n");
        printf("Enter An Option:");
        scanf("%d", &chs);
        switch (chs)
        {
        case 1:
            display(head);
            break;

        case 2:
            head = deletion(head);
            break;

        case 3:
            printf("Enter Index:");
            scanf("%d", &index);
            head = deletionm(head, index);
            break;

        case 4:
            head = deletionend(head);
            break;

        case 5:
            printf("Enter An Element:");
            scanf("%d", &ele);
            head = insertion(head, ele);
            break;

        case 6:
            exit(0);

        default:
            printf("Invalid Option\n\n");
        }
    }
    return 0;
}