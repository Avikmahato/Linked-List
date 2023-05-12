#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
void display(struct node *head)
{
    struct node *avik;
    avik = head;
    while (avik->next != head)
    {
        printf("\n%d\n", avik->data);
        avik = avik->next;
    }
    printf("\n%d\n", avik->data);
}
struct node *insert(struct node *head, int data)
{
    struct node *avik,*p;
    avik = (struct node *)malloc(sizeof(struct node));
    p=head;
    avik->data = data;
    avik->next = head;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next=avik;

    return avik;
}
struct node *deletefi(struct node *head)
{
    struct node *avik;
    avik = head;
    if (head->next != NULL)
    {
        while (avik->next != head)
        {
            avik = avik->next;
        }
        avik->next = head->next;
    }
    else
        printf("The Linked  List Is Empty\n\n");
}
int max(struct node *head)
{
    int max = head->data;
    struct node *avik;
    avik = head;
    while (avik->next != head)
    {
        if (max < avik->data)
        {
            max = avik->data;
        }
        avik = avik->next;
    }
    return max;
}
int min(struct node *head)
{
    int min = head->data;
    struct node *avik;
    avik = head;
    while (avik->next != head)
    {
        if (min > avik->data)
        {
            min = avik->data;
        }
        avik = avik->next;
    }
    return min;
}
int main()
{
    int chs, ele;
    struct node *head, *body, *tail;
    head = (struct node *)malloc(sizeof(struct node));
    body = (struct node *)malloc(sizeof(struct node));
    tail = (struct node *)malloc(sizeof(struct node));

    head->data = 68;
    head->next = body;
    body->data = 81;
    body->next = tail;
    tail->data = 78;
    tail->next = head;

    while (7)
    {
        printf("\tCircular Linked List Operattioon\n\n");
        printf("1 For Insertion:\n");
        printf("2 For Deletion :\n");
        printf("3 For Find MAX :\n");
        printf("4 For Find MIN :\n");
        printf("5 For Display  :\n");
        printf("6 For Exit     :\n");
        printf("Enter An Option:");
        scanf("%d", &chs);
        switch (chs)
        {
        case 1:
            printf("Enter An Element:");
            scanf("%d", &ele);
            head = insert(head, ele);
            break;

        case 2:
            head = deletefi(head);
            break;

        case 3:
            printf("The Largest Element IS : %d", max(head));
            break;

        case 4:
            printf("The Smallest Element Is : %d", min(head));
            break;

        case 5:
            display(head);
            break;

        case 6:
            exit(0);

        default:
            printf("Invalid Option\n\n");
        }
    }

    return 0;
}