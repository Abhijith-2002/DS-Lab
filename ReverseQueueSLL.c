#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
int stack[SIZE],top =-1;
typedef struct Queue
{
    int data;
    struct Queue* next;
}Queue;
Queue* front = NULL;
int isEmpty() {return(front==NULL);}
Queue* createNode(int data)
{
    Queue* newNode = (Queue*)malloc((sizeof(Queue)));
    if(newNode == NULL) 
    {
        printf("\nError : Memory Allocation Failed !");
        exit(0);
    }
    newNode->next = NULL;
    newNode->data = data;
    return(newNode);
}
void Enqueue(int data)
{
    Queue* newNode = createNode(data);
    if(isEmpty()) front = newNode;
    else
    {
        Queue* temp = front;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void dequeue()
{
    if(isEmpty()) printf("\nError : Queue Empty !");
    else
    {
        Queue *del = front;
        front = front->next;
        free(del);
    }
}
void display()
{
    if(isEmpty()) printf("\nError : Queue Empty !");
    else
    {
        Queue*temp = front;
        printf("\nfront");
        while(temp!=NULL)
        {
            printf("->%d",temp->data);
            temp=temp->next;
        }
    }
}
void push(int data)
{
    stack[++top] = data;
}
int pop()
{
    return stack[top--];
}
void reverse()
{
    if(front==NULL) printf("Error : Queue Empty !");
    else
    {
        Queue*temp = front;
        while(temp!=NULL)
        {
            push(temp->data);
            temp = temp->next;
        }
        Queue*ptr = front;
        front = ptr;
        while(ptr!=NULL)
        {
            ptr->data = pop();
            ptr = ptr->next;
        }
    }
}
void main()
{
    int choice,data;
    do
    {
        printf("Choose an operation : \n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Reverse Queue\n");
        printf("4.Display Queue\n");
        printf("5.Exit\n");
        printf("Enter an option : \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the data to enqueue :\n");
                scanf("%d",&data);
                Enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                reverse();
                break;
            case 4:
                display();
                break;
            case 5:
                break;
        }
    }
    while(choice<=4);
}