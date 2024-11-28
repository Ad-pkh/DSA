// implementation of stack using an array
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int stackarr[MAX];
int top = -1;

void push(int data);
int pop();
int peek();
void display();
int isfull();
int isempty();

int main()
{
    int choice, data;

    while (1)
    {
        printf("\n1. Push\n");
        printf("2. Pop\n");
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
            push(data);
            break;

        case 2:
           printf("Popped element :%d \n", pop());
            break;

        case 3:
           printf("Top element :%d \n", peek());
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

void push(int data)
{
    if (isfull())
    {
        printf("stack overflow\n");
        return;
    }
    top = top + 1;
    stackarr[top] = data;
}

int pop()
{
    if (isempty()){
        printf("Stack is empty\n");
        return 0;
    }
    
    return stackarr[top--];
}

int peek()
{
    if (isempty())
    {
        printf(" stack khali xa");
        return 0;
    }
    return stackarr[top];
}

int isfull()
{
    if (top == MAX - 1)
        return 1;

    else
        return 0;
}

int isempty()
{
    if (top == -1)
        return 1;

    else
        return 0;
}

void display()
{
    int i;
    if (isempty())
    {
        printf("Error");
    }
    printf("Displaying Stack...\n");
    for (i = top; i >= 0; i--)
    {
        printf("%d\n", stackarr[i]);
    }
}