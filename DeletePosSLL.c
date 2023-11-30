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
void deletePos(int pos)
{
    if(isEmpty()) printf("\nError : List Empty !");
    else
    {

        LinkedList*temp = first;
        LinkedList*del = NULL;
        if(pos==1)
        {
            del = first;
            first = first->next;
            free(del);
        }
        else
        {
            int count=1;
            while(count<pos-1)
            {
                temp=temp->next;
                count++;
            }
            del = temp->next;
            temp->next = temp->next->next;
            free(del);
        }
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
    int choice,data,pos;
    do
    {
        printf("Choose an operation : \n");
        printf("1.Add Node at End\n");
        printf("2.Delete by Position\n");
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
                printf("Enter the Position :\n");
                scanf("%d",&pos);
                deletePos(pos);
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