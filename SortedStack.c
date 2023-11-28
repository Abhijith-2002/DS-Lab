#include<stdio.h>
#define SIZE 100
int stack[SIZE],top=-1;
int stackEmpty()
{
    if(top==-1) return 1;

    else return 0;
}
int stackFull()
{
    if(top==SIZE-1) return 1;
    else return 0;
}
void stackOverflow()
{
    printf("Error : Stack Overflow\n");
}
void stackUnderflow()
{
    printf("Error : Stack Underflow\n");
}
void push(int data)
{
    if(stackFull()) stackOverflow();
    else if(stackEmpty()) stack[++top] = data;
    else
    {
        int tempStack[SIZE],tempTop = -1;
        while(data>stack[top] && !stackEmpty())
        {
            int del = stack[top--];
            tempStack[++tempTop] = del;
        }
        stack[++top] = data;
        while(tempTop>=0)
        {
            int del = tempStack[tempTop--];
            stack[++top] = del;
        }
    }
}
void pop()
{
    int del;
    if(stackEmpty()) stackUnderflow();
    else
    {
        del = stack[top--];
        printf("Deleted : %d",del);
    }
}
void display()
{
    if(stackEmpty(top)) stackUnderflow();
    else
    {
        for(int i=0;i<=top;i++)
        {
            printf("%d ",stack[i]);
        }
        printf("\n");
    }
}
void peek()
{
    if(stackEmpty(top)) stackUnderflow();
    else printf("\nTop : %d\n",stack[top]);
}
void main()
{
    int choice,data;
    do
    {
        printf("Choose an operation : \n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.Display\n");
        printf("5.Exit\n");
        printf("Enter an option : \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element to push :\n");
                scanf("%d",&data);
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
        }
    }
    while(choice<=4);
}