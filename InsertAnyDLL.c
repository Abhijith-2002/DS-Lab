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
void insertAny(int data,int pos)
{
    DLL* newNode = createNode(data);
    DLL* temp=first;
    if(pos==1)
    {
        if(first==NULL)
        {
            first = newNode;
        }
        else
        {
            newNode->next = first;
            first->prev = newNode;
            first = newNode;
        }
    }
    else
    {
        int track = 1;
        while(track!=pos-1)
        {
            temp=temp->next;
            track++;
        }
        if(temp->next=NULL)
        {
            temp->next=newNode;
            newNode->prev=temp;
        }
        else
        {
            newNode->next = temp->next;
            temp->next->prev = newNode;
            newNode->prev = temp;
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
    int cho,data,pos;
    do
    {
        printf("\n1.Insert at Position");
        printf("\n2.Display");
        printf("\n3.Exit");
        printf("\nEnter your choice : ");
        scanf("%d",&cho);
        switch(cho)
        {
            case 1 :
                printf("\nEnter the data : ");
                scanf("%d",&data);
                printf("\nEnter the position : ");
                scanf("%d",&pos);
                insertAny(data,pos);
                break;
            case 2 :
                display();
                break;
            case 3 :
                break;
        }
    }while(cho<=2);
}