#include<stdio.h>
#include<stdlib.h>
typedef struct CircularDLL
{
    int data;
    struct CircularDLL* next;
    struct CircularDLL* prev;
}CircularDLL;
CircularDLL* first = NULL;
CircularDLL* last = NULL;
int isEmpty()
{
    return(first==last && first==NULL);
}
CircularDLL* createNode(int data)
{
    CircularDLL* newNode = (CircularDLL*)malloc((sizeof(CircularDLL)));
    if(newNode == NULL) 
    {
        printf("\nError : Memory Allocation Failed !");
        exit(0);
    }
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->data = data;
    return(newNode);
}
CircularDLL* insertEnd(int data)
{
    CircularDLL* newNode = createNode(data);
    if(isEmpty())
    {
        first = last = newNode;
        first->next = last->next = NULL;
        first->prev = last->prev = NULL;
    }
    else
    {
        last->next = newNode;
        newNode->prev = last;
        last = newNode;
        last->next = first;
        first->prev = last;
    }
}
void display()
{
    if(isEmpty()) printf("Error : Empty List !");
    else
    {
        CircularDLL* temp = first;
        printf("%d ",temp->data);
        temp = temp->next;
        while(temp!=first)
        {
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
}
void main()
{
    int choice,data;
    do
    {
        printf("Choose an operation : \n");
        printf("1.Add element at end\n");;
        printf("2.Display Queue\n");
        printf("3.Exit\n");
        printf("Enter an option : \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the data :\n");
                scanf("%d",&data);
                insertEnd(data);
                break;
            case 2:
                display();
                break;
            case 3:
                break;
        }
    }
    while(choice<=2);
}
