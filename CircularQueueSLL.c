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
void enqueue(int data)
{
    queue* newNode = createNode(data);
    if(front==NULL)
    {
        front=newNode;
        rear=newNode;
    }
    else
    {
        rear->next = newNode;
        newNode->next = front;
        rear = newNode;
    }
}
void dequeue()
{
    queue* del = NULL;
    if(front==NULL) printf("Empty List");
    else if(front==rear)
    {
        del = front;
        front = NULL;
        rear = NULL;
    }
    else
    {
        del = front;
        front=front->next;
        rear->next = front;
        free(del);
    }
}
void display()
{
    queue* temp = front;
    while(temp->next!=front)
    {
        printf("%d",temp->data);
        temp = temp->next;
    }
    printf("%d",temp->data);
}
void main()
{
    int cho,data;
    do
    {
        printf("\n1.Enqueue");
        printf("\n2.Dequeue");
        printf("\n3.Display");
        printf("\n4.Exit");
        printf("\nEnter your choice : ");
        scanf("%d",&cho);
        switch(cho)
        {
            case 1 :
                printf("\nEnter the data : ");
                scanf("%d",&data);
                enqueue(data);
                break;
            case 2 :
                dequeue();
                break;
            case 3 :
                display();
                break;
            case 4 :
                break;
        }
    }while(cho<=3);
}