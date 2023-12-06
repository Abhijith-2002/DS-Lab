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
void dequeue()
{
    if(front==NULL) printf("\nQueue Empty");
    else
    {
        queue* del = front;
        front = front->next;
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