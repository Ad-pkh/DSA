#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node *addatBeg(struct node *start, int data);
struct node *addatEnd(struct node *start, int data);
void display(struct node *start);
struct node *addatpos(struct node *start, int pos, int data);
struct node *del(struct node *start, int pos);

int main()
{
    struct node *start = NULL;
    int choice, data, pos;

    while (1)
    {
        printf("\n1. Add at Beginning\n");
        printf("2. Add at End\n");
        printf("3. Add at Position\n");
        printf("4. Display Linked List\n");
        printf("5. Delete Node at Position\n");
        printf("6. Exit\n\n");

        printf("Select your preferred operation: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            start = addatBeg(start, data);
            break;

        case 2:
            printf("Enter data: ");
            scanf("%d", &data);
            start = addatEnd(start, data);
            break;

        case 3:
            printf("Enter position and data: ");
            scanf("%d%d", &pos, &data);
            start = addatpos(start, pos, data);
            break;

        case 4:
            display(start);
            break;

        case 5:
            printf("Enter position: ");
            scanf("%d", &pos);
            start = del(start, pos);
            break;

        case 6:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice\n");
            break;
        }
    }
}

struct node *addatBeg(struct node *start, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->info = data;
    temp->link = start;
    return temp;
}

struct node *addatEnd(struct node *start, int data)
{
    struct node *temp, *p;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = data;
    temp->link = NULL;

    if (start == NULL)
    {
        return temp;
    }

    p = start;
    while (p->link != NULL)
    {
        p = p->link;
    }
    p->link = temp;
    return start;
}

void display(struct node *start)
{
    if (start == NULL)
    {
        printf("!!!! Linked list is empty !!!!\n");
        return;
    }

    struct node *p = start;
    while (p != NULL)
    {
        printf("%d\t", p->info);
        p = p->link;
    }
}

struct node *addatpos(struct node *start, int pos, int data)
{
    if (pos < 1)
    {
        printf("Invalid position\n");
        return start;
    }

    if (pos == 1)
    {
        return addatBeg(start, data);
    }

    struct node *temp, *p;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = data;

    p = start;
    for (int i = 1; i < pos - 1; i++)
    {
        if (p == NULL)
        {
            printf("Invalid position\n");
            free(temp);
            return start;
        }
        p = p->link;
    }

    temp->link = p->link;
    p->link = temp;
    return start;
}

struct node *del(struct node *start, int pos)
{
    if (start == NULL)
    {
        printf("!!!! Linked list is empty !!!!\n");
        return start;
    }

    if (pos < 1)
    {
        printf("Invalid position\n");
        return start;
    }

    struct node *temp;

    if (pos == 1)
    {
        temp = start;
        start = start->link;
        free(temp);
        return start;
    }

    struct node *p = start;
    for (int i = 1; i < pos - 1; i++)
    {
        if (p->link == NULL)
        {
            printf("Invalid position\n");
            return start;
        }
        p = p->link;
    }

    temp = p->link;
    if (temp == NULL)
    {
        printf("Invalid position\n");
        return start;
    }

    p->link = temp->link;
    free(temp);
    return start;
}
