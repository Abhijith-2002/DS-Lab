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
void insertAfter(int data,int adata)
{
    DLL* newNode = createNode(data);
    DLL* temp=first;
    if(first==NULL)
    {
        first = newNode;
    }
    else
    {
        while(temp!=NULL)
        {
            if(temp->data==adata)
            {
                if(temp->next==NULL)
                {
                    temp->next = newNode;
                    newNode->prev = temp;
                }
                else
                {
                    temp->next->prev=newNode;
                    newNode->next=temp->next;
                    newNode->prev=temp;
                    break;
                }
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
    int cho,data,adata;
    do
    {
        printf("\n1.Insert After Data");
        printf("\n2.Display");
        printf("\n3.Exit");
        printf("\nEnter your choice : ");
        scanf("%d",&cho);
        switch(cho)
        {
            case 1 :
                printf("\nEnter the data : ");
                scanf("%d",&data);
                printf("\nEnter the after data : ");
                scanf("%d",&adata);
                insertAfter(data,adata);
                break;
            case 2 :
                display();
                break;
            case 3 :
                break;
        }
    }while(cho<=2);
}