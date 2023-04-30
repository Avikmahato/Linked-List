#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *insertion(struct node *head, int ele)
{
    struct node *avik;
    avik = (struct node *)malloc(sizeof(struct node));
    avik->data = ele;
    avik->next = head;

    return avik;
}
struct node *deletion(struct node *head)
{
    struct node *avik;
    avik = head;

    if (head != NULL)
        head = head->next;
    else
        printf("Linked List Is Empty\n\n");

    free(avik);
    return head;
}
void traversal(struct node *head)
{
    if (head != NULL)
        while (head != NULL)
        {
            printf("\n%d\n", head->data);
            head = head->next;
        }
    else
        printf("Linked List Is Empty\n\n");
}
void high(struct node *head)
{
    int max;
    max = head->data;
    while (head != NULL)
    {
        if (head->data > max)
            max = head->data;

        head = head->next;
    }
    printf("The Max Element In The Linked List Is : %d\n\n", max);
}
void low(struct node *head)
{
    int min;
    min = head->data;
    while (head != NULL)
    {
        if (head->data < min)
            min = head->data;

        head = head->next;
    }
    printf("The Max Element In The Linked List Is : %d\n\n", min);
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
    body->data = 80;
    body->next = tail;
    tail->data = 81;
    tail->next = NULL;
    while (7)
    {
        printf("**********Linked List Operation***********\n\n\n");
        printf("1 For Insertion Element:\n");
        printf("2 For Deletion Element :\n");
        printf("3 For Traversal Element:\n");
        printf("4 For Higest  Element  :\n");
        printf("5 For Lowest  Element  :\n");
        printf("6 Exit                 :\n");
        printf("Enter An Option:");
        scanf("%d", &chs);
        switch (chs)
        {
        case 1:
            printf("Enter An Element:");
            scanf("%d", &ele);
            head = insertion(head, ele);
            break;

        case 2:
            head = deletion(head);
            break;

        case 3:
            traversal(head);
            break;
        case 4:
            high(head);
            break;

        case 5:
            low(head);
            break;

        case 6:
            exit(0);

        default:
            printf("Invalid Option\n\n");
        }
    }

    return 0;
}