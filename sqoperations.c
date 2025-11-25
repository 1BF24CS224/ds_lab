#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

void push(struct Node **top, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
    printf("Pushed %d to stack\n", value);
}

int pop(struct Node **top)
{
    if (*top == NULL)
    {
        printf("Stack Underflow!\n");
        return -1;
    }
    struct Node *temp = *top;
    int value = temp->data;
    *top = temp->next;
    free(temp);
    printf("Popped %d from stack\n", value);
    return value;
}

void displayStack(struct Node *top)
{
    printf("Stack: ");
    while (top != NULL)
    {
        printf("%d -> ", top->data);
        top = top->next;
    }
    printf("NULL\n");
}

void enqueue(struct Node **front, struct Node **rear, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*rear == NULL)
    {
        *front = *rear = newNode;
    }
    else
    {
        (*rear)->next = newNode;
        *rear = newNode;
    }

    printf("Enqueued %d to queue\n", value);
}

int dequeue(struct Node **front, struct Node **rear)
{
    if (*front == NULL)
    {
        printf("Queue Underflow!\n");
        return -1;
    }
    struct Node *temp = *front;
    int value = temp->data;

    *front = (*front)->next;

    if (*front == NULL)
        *rear = NULL;

    free(temp);
    printf("Dequeued %d from queue\n", value);
    return value;
}

void displayQueue(struct Node *front)
{
    printf("Queue: ");
    while (front != NULL)
    {
        printf("%d -> ", front->data);
        front = front->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *stackTop = NULL;
    struct Node *queueFront = NULL, *queueRear = NULL;

    int choice, value;

    while (1)
    {
        printf("\n----- MENU -----\n");
        printf("1. Push (Stack)\n");
        printf("2. Pop (Stack)\n");
        printf("3. Display Stack\n");
        printf("4. Enqueue (Queue)\n");
        printf("5. Dequeue (Queue)\n");
        printf("6. Display Queue\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            push(&stackTop, value);
            break;

        case 2:
            pop(&stackTop);
            break;

        case 3:
            displayStack(stackTop);
            break;

        case 4:
            printf("Enter value: ");
            scanf("%d", &value);
            enqueue(&queueFront, &queueRear, value);
            break;

        case 5:
            dequeue(&queueFront, &queueRear);
            break;

        case 6:
            displayQueue(queueFront);
            break;

        case 7:
            exit(0);

        default:
            printf("Invalid Choice!\n");
        }
    }

    return 0;
}
