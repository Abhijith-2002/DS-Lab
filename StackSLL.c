#include<stdio.h>
#include<stdlib.h>
typedef struct Stack
{
    int data;
    struct Stack* next;
}Stack;
Stack* top = NULL;
int isEmpty() {return(top==NULL);}
Stack* createNode(int data)
{
    Stack* newNode = (Stack*)malloc((sizeof(Stack)));
    if(newNode == NULL) 
    {
        printf("\nError : Memory Allocation Failed !");
        exit(0);
    }
    newNode->next = NULL;
    newNode->data = data;
    return(newNode);
}
void push(int data)
{
    Stack* newNode = createNode(data);
    if(isEmpty()) top = newNode;
    else
    {
        newNode->next = top;
        top = newNode;
    }
}
void pop()
{
    Stack* del = top;
    top = top->next;
    free(del);
}
void display()
{
    if(isEmpty()) printf("\nError : Stack Empty !");
    else
    {
        Stack*temp = top;
        printf("\nTop");
        while(temp!=NULL)
        {
            printf("->%d",temp->data);
            temp=temp->next;
        }
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
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("Enter an option : \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the data to push :\n");
                scanf("%d",&data);
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                break;
        }
    }
    while(choice<=3);
}