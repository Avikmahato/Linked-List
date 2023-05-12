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
    while (p != NULL)
    {
        printf("\n%d\n", p->data);
        p = p->next;
    }
}
struct node *insertionfi(struct node *head, int data)
{
    struct node *vik;
    vik = (struct node *)malloc(sizeof(struct node));
    vik->data = data;
    vik->next = head;
    vik->prev = NULL;
    return vik;
}
struct node *insertionmid(struct node *head, int data, int index)
{
    int x = 0;
    struct node *avik, *p = head;
    avik = (struct node *)malloc(sizeof(struct node));
    avik->data = data;
    while (x != index - 1)
    {
        p = p->next;
        x++;
    }
    avik->next = p->next;
    p->next = avik;
    avik->prev = p;

    return head;
}
struct node *insertionend(struct node *head, int data)
{
    struct node *avik, *p;
    avik = (struct node *)malloc(sizeof(struct node));
    p = head;
    avik->data = data;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = avik;
    avik->next = NULL;
    
    avik->prev = p;

    return head;
}
int main()
{
    struct node *head, *body, *tail;
    int chs, ele, index;
    head = (struct node *)malloc(sizeof(struct node));
    body = (struct node *)malloc(sizeof(struct node));
    tail = (struct node *)malloc(sizeof(struct node));

    head->data = 68;
    head->prev = NULL;
    head->next = body;

    body->data = 80;
    body->prev = body;
    body->next = tail;

    tail->data = 81;
    tail->prev = body;
    tail->next = NULL;
    while (7)
    {
        printf("****Doubly Linked List****\n\n\n");
        printf("1 For Display:\n");
        printf("2 For Insertion At First:\n");
        printf("3 For Insertion At Mid:\n");
        printf("4 For Insertion At Last:\n");
        printf("5 Exit:\n");
        printf("Enter An Option:");
        scanf("%d", &chs);
        switch (chs)
        {
        case 1:
            traversal(head);
            break;

        case 2:
            printf("Enter An Element:");
            scanf("%d", &ele);
            head = insertionfi(head, ele);
            break;

        case 3:
            printf("Enter An Element:");
            scanf("%d", &ele);
            printf("Enter Index:");
            scanf("%d", &index);
            head = insertionmid(head, ele, index);
            break;

        case 4:
            printf("Enter An Element:");
            scanf("%d", &ele);
            head = insertionend(head, ele);
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid Option\n");
        }
    }

    return 0;
}