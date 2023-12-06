#include<stdio.h>
#include<stdlib.h>
typedef struct queue
{
    int data;
    struct queue* next;
}queue;
queue* front = NULL;
queue* rear = NULL;
queue* createNode(int data)
{
    queue* newNode = (queue*)malloc(sizeof(queue));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void enqueueRear(int data)
{
    queue* newNode = createNode(data);
    if(front==NULL)
    {
        front = rear = newNode;
    }
    else
    {
        queue* temp = front;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        rear = newNode;
    }
}
void enqueueFront(int data)
{
    queue* newNode = createNode(data);
    if(front==NULL)
    {
        front = rear = newNode;
    }
    else
    {
        newNode->next=front;
        front=newNode;
    }
}
void dequeueFront()
{
    if(front==NULL) printf("\nQueue Empty");
    else
    {
        queue* del = front;
        front = front->next;
        free(del);
    }
}
void dequeueRear()
{
    if(front==NULL) printf("\nQueue Empty");
    else
    {
        queue* del = rear;
        queue* temp = front;
        while(temp->next!=rear)
        {
            temp=temp->next;
        }
        temp->next=NULL;
        rear = temp;
        free(del);
    }
}
void display()
{
    queue* temp = front;
    if(front==NULL) printf("\nQueue Empty");
    else
    {
        while(temp!=NULL)
        {
            printf("%d",temp->data);
            temp = temp->next;
        }
    }
}
void main()
{
    int cho,data;
    do
    {
        printf("\n1.Enqueue Front");
        printf("\n2.Enqueue Rear");
        printf("\n3.Dequeue Front");
        printf("\n4.Dequeue Rear");
        printf("\n5.Display");
        printf("\n6.Exit");
        printf("\nEnter your choice : ");
        scanf("%d",&cho);
        switch(cho)
        {
            case 1 :
                printf("\nEnter the data : ");
                scanf("%d",&data);
                enqueueFront(data);
                break;
            case 2 :
                printf("\nEnter the data : ");
                scanf("%d",&data);
                enqueueRear(data);
                break;
            case 3 :
                dequeueFront();
                break;
            case 4 :
                dequeueRear();
                break;
            case 5 :
                display();
            case 6 :
                break;
        }
    }while(cho<=5);
}