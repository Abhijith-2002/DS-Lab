#include<stdio.h>
#include<stdlib.h>
typedef struct Deque
{
    int data;
    struct Deque* next;
}Deque;
Deque* front = NULL;
int isEmpty() {return(front==NULL);}
Deque* createNode(int data)
{
    Deque* newNode = (Deque*)malloc((sizeof(Deque)));
    if(newNode == NULL) 
    {
        printf("\nError : Memory Allocation Failed !");
        exit(0);
    }
    newNode->next = NULL;
    newNode->data = data;
    return(newNode);
}
void enqueueRear(int data)
{
    Deque* newNode = createNode(data);
    if(isEmpty()) front = newNode;
    else
    {
        Deque* temp = front;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void enqueueFront(int data)
{
    Deque* newNode = createNode(data);
    if(isEmpty()) front = newNode;
    else
    {
        newNode->next = front;
        front = newNode;
    }
}
void dequeueFront()
{
    if(isEmpty()) printf("\nError : Deque Empty !");
    else
    {
        Deque *del = front;
        front = front->next;
        free(del);
    }
}
void dequeueRear()
{
    if(isEmpty()) printf("\nError : Deque Empty !");
    else
    {
        Deque *temp = front;
        while(temp->next->next!=NULL)
        {
            temp = temp->next;
        }
        Deque *del = temp->next;
        temp->next = NULL;
        free(del);
    }
}
void display()
{
    if(isEmpty()) printf("\nError : Deque Empty !");
    else
    {
        Deque*temp = front;
        printf("\nfront");
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
        printf("1.Enqueue Rear\n");
        printf("2.Enqueue Front\n");
        printf("3.Dequeue Front\n");
        printf("4.Dequeue Rear\n");
        printf("5.Display\n");
        printf("6.Exit\n");
        printf("Enter an option : \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the data :\n");
                scanf("%d",&data);
                enqueueRear(data);
                break;
            case 2:
                printf("Enter the data :\n");
                scanf("%d",&data);
                enqueueFront(data);
                break;
            case 3:
                dequeueFront();
                break;
            case 4:
                dequeueRear();
                break;
            case 5:
                display();
                break;
            case 6:
                break;
        }
    }
    while(choice<=5);
}