#include<stdio.h>
#include<stdlib.h>
typedef struct LinkedList
{
    int data;
    struct LinkedList* next;
}LinkedList;
LinkedList* first = NULL;
int isEmpty() {return(first==NULL);}
LinkedList* createNode(int data)
{
    LinkedList* newNode = (LinkedList*)malloc((sizeof(LinkedList)));
    if(newNode == NULL) 
    {
        printf("\nError : Memory Allocation Failed !");
        exit(0);
    }
    newNode->next = NULL;
    newNode->data = data;
    return(newNode);
}
void insertNodeEnd(int data)
{
    LinkedList* newNode = createNode(data);
    if(isEmpty()) first = newNode;
    else
    {
        LinkedList* temp = first;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void insertNodeAfter(int afterData,int data)
{
    LinkedList* newNode = createNode(data);
    LinkedList* temp = first;
    while(temp!=NULL && temp->data!=afterData )
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
void display()
{
    if(isEmpty()) printf("\nError : List Empty !");
    else
    {
        LinkedList*temp = first;
        printf("\nHead");
        while(temp!=NULL)
        {
            printf("->%d",temp->data);
            temp=temp->next;
        }
    }
}
void main()
{
    int choice,afterData,data;
    do
    {
        printf("Choose an operation : \n");
        printf("1.Add Node at End\n");
        printf("2.Add Node Before\n");
        printf("3.Display Linked List\n");
        printf("4.Exit\n");
        printf("Enter an option : \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the data to add :\n");
                scanf("%d",&data);
                insertNodeEnd(data);
                break;
            case 2:
                printf("Enter the after data :\n");
                scanf("%d",&afterData);
                printf("Enter the data :\n");
                scanf("%d",&data);
                insertNodeAfter(afterData,data);
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