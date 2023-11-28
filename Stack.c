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
    else stack[++top]=data;
}
void pop()
{
    if(stackEmpty()) stackUnderflow();
    else printf("Popped : %d\n",stack[top--]);
}
void peek()
{
    if(stackEmpty()) stackUnderflow();
    else printf("Top : %d\n",stack[top]);
}
void display()
{
    if(stackEmpty()) stackUnderflow();
    else
    {
        for(int i=0;i<=top;i++)
        {
            printf("%d ",stack[i]);
        }
        printf("\n");
    }
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