#include<stdio.h>
#define SIZE 100
int stack[SIZE],top=-1;
int auxStack[SIZE],auxTop=-1;
int stackEmpty(int top)
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
    else
    {
        stack[++top] = data;
        if(stackEmpty(auxTop)) auxStack[++auxTop] = data;
        else
        {
            if(data<=auxStack[auxTop]) auxStack[++auxTop] = data;
        }
    }
}
void pop()
{
    int del;
    if(stackEmpty(top)) stackUnderflow();
    else
    {
        del = stack[top--];
        if(del==auxStack[auxTop]) auxTop--;
        printf("\nDeleted : %d",del);
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
void getMin()
{
    if(stackEmpty(auxTop)) stackUnderflow();
    else printf("\nMinimum element : %d",auxStack[auxTop]);
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
        printf("5.Display Minimum Element\n");
        printf("6.Exit\n");
        printf("Enter an option : \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter the element to push :\n");
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
            case 5:
                getMin();
                break;
            case 6:
                break;
        }
    }
    while(choice<=5);
}
