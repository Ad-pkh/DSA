// implementation of  linear queue using an array
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int queue[MAX];
int front=-1, rare = -1;

void Enqueue(int);
int Dequeue();
int peek();
void display();
int isfull();
int isempty();

int main()
{
    int choice, data;

    while (1)
    {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
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
            printf("Dequeued element :%d \n", Dequeue());
            break;

        case 3:
            printf("front element :%d \n", peek());
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
    return 0;
}

void Enqueue(int data)
{
    if (front==-1)
    {
        front =0;
    }

    if (isfull())
    {
        printf("queue is full \n");
        return;
    }

    rare += 1;
    queue[rare] = data;
}

int Dequeue()
{
    if (isempty())
    {
        printf("queue is empty\n");
        return 0;
    }

    return queue[front++];
}

int peek()
{
    if (isempty())
    {
        printf(" queue khali xa");
        return 0;
    }
    return queue[front];
}

int isfull()
{
    if (rare == MAX - 1)
        return 1;

    else
        return 0;
}

int isempty()
{
    if (front == -1 || front == rare + 1)
        return 1;

    else
        return 0;
}

void display()
{
    int i;
    if (isempty())
    {
        printf("Queue is empty ");
        return;
    }
    printf("Displaying queue...\n");
    for (i = front; i <= rare; i++)
    {
        printf("%d\t", queue[i]);
    }
}