#include<stdio.h>
#define SIZE 100
int stack[SIZE],top1=-1,top2=SIZE;
void push(int stackNo,int data)
{
    if(stackNo==1)
    {
        if(top1==top2-1) printf("\nError : Stack Overflow");
        else stack[++top1] = data;
    }
    else if(stackNo==2)
    {
        if(top2==top1+1) printf("\nError : Stack Overflow");
        else stack[--top2] = data;
    }
}
void pop(int stackNo)
{
    if(stackNo==1)
    {
        if(top1==-1) printf("\nError : Stack Empty");
        else
        {
            top1--;
            printf("\nPopped : %d",stack[top1+1]);
        }
    }
    else if(stackNo==2)
    {
        if(top2==SIZE) printf("\nError : Stack Empty");
        else
        {
            top2++;
            printf("\nPopped : %d",stack[top2-1]);
        }
    }
}
void display(int stackNo)
{
    if(stackNo==1)
    {
        if(top1==-1) printf("\nError : Stack Empty");
        else
        {
            printf("\nStack-1\n");
            for(int i=0;i<=top1;i++) printf("%d ",stack[i]);
        }
    }
    else if(stackNo==2)
    {
        if(top2==SIZE) printf("\nError : Stack Empty");
        else
        {
            printf("\nStack-2\n");
            for(int i=SIZE-1;i>=top2;i--) printf("%d ",stack[i]);
        }
    }
}
void peek(int stackNo)
{
    if(stackNo==1)
    {
        if(top1==-1) printf("\nError : Stack Empty");
        else printf("\n%d ",stack[top1]);
    }
    else if(stackNo==2)
    {
        if(top2==SIZE) printf("\nError : Stack Empty");
        else printf("\n%d ",stack[top2]);
    }
}
void main()
{
    int stackNo,choice,data;
    do
    {
        printf("\nChoose an operation : \n");
        printf("\n1.Push\n");
        printf("\n2.Pop\n");
        printf("\n3.Peek\n");
        printf("\n4.Display\n");
        printf("\n5.Exit\n");
        printf("\nEnter an option : \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter Stack Number :");
                scanf("%d",&stackNo);
                printf("\nEnter the element to push :\n");
                scanf("%d",&data);
                push(stackNo,data);
                break;
            case 2:
                printf("\nEnter Stack Number :");
                scanf("%d",&stackNo);
                pop(stackNo);
                break;
            case 3:
                printf("\nEnter Stack Number :");
                scanf("%d",&stackNo);
                peek(stackNo);
                break;
            case 4:
                printf("\nEnter Stack Number :");
                scanf("%d",&stackNo);
                display(stackNo);
                break;
            case 5:
                break;
        }
    }
    while(choice<=4);
}
