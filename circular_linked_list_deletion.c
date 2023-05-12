#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
void display(struct node *head)
{
    if (head != NULL)
    {
        while (head != NULL)
        {
            printf("\t%d\t\n", head->data);
            head = head->next;
        }
    }
    else
        printf("The Linked List is Empty\n\n");
}
struct node *deletionm(struct node *head, int index)
{
    int x = 0;
    struct node *ptr, *avik;
    if (head != NULL)
    {
        ptr = head;
        while (x != index - 1)
        {
            ptr = ptr->next;
            x++;
        }
        avik = ptr->next;
        ptr->next = avik->next;
        free(avik);
        return head;
    }
    else
    {
        printf("The Linked list Is empty\n\n");
    }
}

struct node *deletion(struct node *head)
{
    if (head != NULL)
    {
        head = head->next;

        return head;
    }
    else
        printf("The Linked List Is Empty\n\n");
}
struct node *deletionend(struct node *head)
{
    struct node *ptr, *avi;
    avi = head;
    if (head != NULL)
    {
        ptr = avi->next;
        while (ptr->next != NULL)
        {
            avi = avi->next;
            ptr = ptr->next;
        }
        avi->next = NULL;
        free(ptr);
    }
    else
        printf("The Linked List Is Empty\n\n");

    return head;
}
struct node *insertion(struct node *head, int data)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = head;

    return ptr;
}
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