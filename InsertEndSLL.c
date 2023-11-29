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
    int choice,data;
    do
    {
        printf("Choose an operation : \n");
        printf("1.Add Node at End\n");
        printf("2.Display Linked List\n");
        printf("3.Exit\n");
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
                display();
                break;
            case 3:
                break;
        }
    }
    while(choice<=2);
}