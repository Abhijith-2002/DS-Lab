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
void insertBefore(int data,int bdata)
{
    DLL* newNode = createNode(data);
    DLL* temp=first;
    if(first==NULL)
    {
        first = newNode;
    }
    else if(first->data==bdata)
    {
        newNode->next = first;
        first->prev = newNode;
        first = newNode;
    }
    else
    {
        while(temp!=NULL)
        {
            if(temp->next->data==bdata)
            {
                temp->next->prev=newNode;
                newNode->next=temp->next;
                newNode->prev=temp;
                break;
            }
            temp=temp->next;
        }
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
    int cho,data,bdata;
    do
    {
        printf("\n1.Insert Before Data");
        printf("\n2.Display");
        printf("\n3.Exit");
        printf("\nEnter your choice : ");
        scanf("%d",&cho);
        switch(cho)
        {
            case 1 :
                printf("\nEnter the data : ");
                scanf("%d",&data);
                printf("\nEnter the before data : ");
                scanf("%d",&bdata);
                insertBefore(data,bdata);
                break;
            case 2 :
                display();
                break;
            case 3 :
                break;
        }
    }while(cho<=2);
}