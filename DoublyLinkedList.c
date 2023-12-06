#include<stdio.h>
#include<stdlib.h>
typedef struct DLL
{
    int data;
    struct DLL* next;
    struct DLL* prev;
}DLL;
DLL* first = NULL;
DLL* createNode(int data)
{
    DLL* newNode = (DLL*)malloc(sizeof(DLL));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
void insertEnd(int data)
{
    DLL* newNode = createNode(data);
    DLL* temp=first;
    if(first==NULL)
    {
        first = newNode;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}
void display()
{
    DLL* temp=first;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}
void main()
{
    int cho,data;
    do
    {
        printf("\n1.Enqueue");
        printf("\n2.Display");
        printf("\n3.Exit");
        printf("Enter your choice : ");
        scanf("%d",&cho);
        switch(cho)
        {
            case 1 :
                printf("\nEnter the data : ");
                scanf("%d",&data);
                insertEnd(data);
                break;
            case 2 :
                display();
                break;
            case 3 :
                break;
        }
    }while(cho<=2);
}