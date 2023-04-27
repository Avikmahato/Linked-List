#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *deletion(struct node *head)
{
    if (head != NULL)
        head = head->next;
    else
        printf("The List Empty\n\n");
    return head;
}
struct node *insertion(struct node *head, int data)
{
    struct node *finder, *avisu;
    avisu = (struct node *)malloc(sizeof(struct node));
    if (head != NULL)
    {

        avisu->data = data;
        finder = head;
        while (finder->next != NULL)
        {
            finder = finder->next;
        }
        finder->next = avisu;
        avisu->next = NULL;
    }
    else
    {
        avisu->data = data;
        avisu->next = NULL;
        head = avisu;
    }
    return head;
}
void traversal(struct node *ptr)
{
    if (ptr != NULL)
    {

        while (ptr != NULL)
        {
            printf("\n%d\n", ptr->data);
            ptr = ptr->next;
        }
    }
    else
        printf("The List Is Empty\n\n");
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
        printf("Deletion Of Linked List:\n\n");
        printf("1 For Insertion :\n\n");
        printf("2 For Deletion  :\n\n");
        printf("3 For Traversal :\n\n");
        printf("4 For Exit      :\n\n");
        printf("Enter An Option:");
        scanf("%d", &chs);
        switch (chs)
        {
        case 1:
            printf("Enter an Element:");
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
            exit(0);

        default:
            printf("Invalid Option\n\n");
        }
    }
    return 0;
}