#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *insertion(struct Node *head, int data)
{
    struct Node *ptr, *avik;
    avik = (struct Node *)malloc(sizeof(struct Node));
    avik->data = data;
    ptr = head;
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    avik->next = head;
    ptr->next = avik;

    return avik;
}
struct Node *deletion(struct Node *head)
{
    struct Node *avik;
    avik = head;
    if (head != NULL)
    {
        while (avik->next !=head)
        {
            avik = avik->next;
        }
        avik->next = head->next;
        return avik;
    }
    else
        printf("Linked List Is Empty\n");
}
void display(struct Node *head1)
{
    struct Node *head;
    head=head1;
    while (head->next != head1)
    {
        printf("\n%d\n", head->data);
        head = head->next;
    }
    printf("\n%d\n", head->data);
}
int main()
{
    struct Node *head, *body, *tail;
    int chs, ele;
    head = (struct Node *)malloc(sizeof(struct Node));
    body = (struct Node *)malloc(sizeof(struct Node));
    tail = (struct Node *)malloc(sizeof(struct Node));

    head->data = 78;
    head->next = body;
    body->data = 83;
    body->next = tail;
    tail->data = 27;
    tail->next = head;

    while (7)
    {
        printf("Linked List\n\n\n");
        printf("1 For Insertion\n");
        printf("2 For Deletion \n");
        printf("3 For Display  \n");
        printf("4 For Exit     \n");
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
            display(head);
            break;

        case 4:
            exit(0);

        default:
            printf("invalid Option\n\n");
        }
    }

    return 0;
}