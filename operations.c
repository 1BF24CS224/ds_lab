#include<stdio.h>
#define MAXSIZE 10
int stack[MAXSIZE];
int top=-1;

void push()
{
   int val;
    if(top==MAXSIZE-1)
    printf("overflow");
    else
   {
    printf("Enter value:");
    scanf("%d",&val);
    stack[++top]=val;
   }
}
void pop()
{
    if (top==-1)
    printf("Stack underflow");
    else
    printf("Popped:\n",&stack[top--]);

}
void display()
{
    if (top==-1)
    printf("Stack is empty");
    else
    {
        printf("Stack:");
    for(int i=top; i>=0; i--)
    printf("%d",stack[i]);
    printf("\n");
    }
}
void main()
{
    while(1)
    {
        int choice;
    printf("Welcome to stack program");
    printf("Enter your choice:- 1.PUSH, 2.POP, 3.DISPLAY, 4.EXIT");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        {
            push();
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
        {
            printf("EXIT");
            break;
        }
        default:
        {
            printf("invalid input");
            break;
    }

        }
    }

}
