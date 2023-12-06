#include<stdio.h>
#define SIZE 100
int queue[SIZE];
int front=-1;
int rear = -1;
void enqueue(int data)
{
    if((front==0 && rear==SIZE-1)||(rear == front-1))
    {
        printf("\nQueue Overflow");
    }
    else if(front==-1)
    {
        front = 0;
        rear = 0;
        queue[front] = data;
    }
    else
    {
        rear = ++rear%SIZE;
        queue[rear] = data;
    }
}
void dequeue()
{
    if(front==-1) printf("\nQueue Empty");
    else if(front==rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = ++front%SIZE;
    }
}
void display()
{
    if(front == -1) printf("\nQueue Empty");
    else if(front<=rear)
    {
        for(int i=front;i<=rear;i++)
        {
            printf("%d",queue[i]);
        }
    }
    else
    {
        for(int i=front;i<SIZE;i++)
        {
            printf("%d",queue[i]);
        }
        for(int i=0;i<=rear;i++)
        {
            printf("%d",queue[i]);
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