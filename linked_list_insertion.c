#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
void traversal(struct node *);
struct node *insert_fi(struct node *, int);
struct node *insert_mid(struct node *, int, int);
struct node *insert_end(struct node *, int);

int main()
{
    int chs, index, ele;
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
        printf("*******Linked List Operation:\n\n\n");
        printf("1 For Insertion At First    :\n");
        printf("2 For Insertion At Middle   :\n");
        printf("3 For Insertion At End      :\n");
        printf("4 For Insertion At Traversal:\n");
        printf("5 For Insertion At Exit     :\n");

        printf("Enter An Option:");
        scanf("%d", &chs);

        switch (chs)
        {
        case 1:
            printf("Enter Element:");
            scanf("%d", &ele);
            head = insert_fi(head, ele);
            break;

        case 2:
            printf("Enter Element:");
            scanf("%d", &ele);
            printf("Enter Index:");
            scanf("%d", &index);
            head = insert_mid(head, index, ele);
            break;

        case 3:
            printf("Enter Element:");
            scanf("%d", &ele);
            head = insert_end(head, ele);
            break;

        case 4:
            traversal(head);
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid Option:\n\n");
        }
    }
    return 0;
}

struct node *insert_fi(struct node *head, int data)
{
    struct node *avik;
    avik = (struct node *)malloc(sizeof(struct node));
    avik->data = data;
    avik->next = head;
    return avik;
}
void traversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("\n%d\n", ptr->data);
        ptr = ptr->next;
    }
}
struct node *insert_end(struct node *head, int data)
{
    struct node *finder, *avisu;
    avisu = (struct node *)malloc(sizeof(struct node));
    finder = head;
    while (finder->next != NULL)
    {
        finder = finder->next;
    }
    finder->next = avisu;
    avisu->data = data;
    avisu->next = NULL;
    return head;
}
struct node *insert_mid(struct node *head, int index, int data)
{
    struct node *avisu, *finder;
    int x;
    x = 0;
    finder = head;
    avisu = (struct node *)malloc(sizeof(struct node));

    while (x != index - 1)
    {
        finder = finder->next;
        x++;
    }
    avisu->data = data;
    avisu->next = finder->next;
    finder->next = avisu;
    return head;
}