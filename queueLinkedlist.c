// implementation of  linear queue using Linkedlist
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node *front = NULL;
struct node *rear = NULL;

int IsEmpty();
int Enqueue(int);
void Dequeue();
void peek();
void display();

int main()
{

    int choice, data;

    while (1)
    {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek \n");
        printf("4. Display queue\n");
        printf("5. Exit\n\n");

        printf("Select your preferred operation: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            Enqueue(data);
            break;

        case 2:
            Dequeue();
            break;

        case 3:
            peek();
            break;

        case 4:
            display();
            break;

        case 5:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice\n");
            break;
        }
    }
}

int IsEmpty()
{
    if (front == NULL)
        return 1;
    else
        return 0;
}

int Enqueue(int data)
{

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->info = data;
    temp->link = NULL;

    if (IsEmpty())
    {
        front = rear = temp;
    }
    else
    {
        rear->link = temp;
        rear = temp;
    }
}

void Dequeue()
{
    if (IsEmpty())
    {
        printf("queue is empty\n");
        return;
    }
    struct node *p = front->link;
    printf("Dequed element  =%d\n", front->info);
    front = p;

    if (front == NULL)
    {
        rear = NULL;
    }
}

void peek()
{
    if (IsEmpty())
    {
        printf("queue is empty\n");
        return;
    }
    printf("Front element = %d\n", front->info);
}

void display()
{
    if (IsEmpty())
    {
        printf("!!!! queue is empty !!!!\n");
        return;
    }

    struct node *p = front;
    while (p != NULL)
    {
        printf("%d\t", p->info);
        p = p->link;
    }
}
