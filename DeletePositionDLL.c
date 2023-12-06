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
void smallest()
{
    int small = 1000;
    DLL* temp = first;
    while(temp!=NULL)
    {
        if(temp->data < small)
        {
            small = temp->data;
        }
        temp->next;
    }
    return small;
}
void delete(int data)
{
    DLL* temp = first;
    DLL* del;
    if(first->data==data)
    {
        del = first;
        first = first->next;
        free(del);
    }
    else
    {
        while(temp->next->data!=data)
        {
            temp = temp->next;
        }
        del = temp->next;
        temp->next->next->prev = temp;
        temp->next = temp->next->next;
        free(del);
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
    int cho,data,small;
    do
    {
        printf("\n1.Insert");
        printf("\n2.Delete smallest");
        printf("\n3.Display");
        printf("\n4.Exit");
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
                small = smallest();
                delete(small);
                break;
            case 3 :
                display();
                break;
            case 4 :
                break;
        }
    }while(cho<=3);
}