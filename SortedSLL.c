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
void swapData(LinkedList* node1,LinkedList* node2)
{
    int temp;
    temp = node1->data;
    node1->data = node2->data;
    node2->data = temp;
}
void sort()
{
    LinkedList* current = first;
    LinkedList* index = NULL;
    while(current!=NULL)
    {
        index = current->next;
        while(index!=NULL)
        {
            if(current->data > index->data) swapData(current,index);
            index = index->next;
        }
        current = current->next;
    }
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
        printf("3.Sort Linked List\n");
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
                display();
                break;
            case 3:
                sort();
                break;
            case 4:
                break;
        }
    }
    while(choice<=3);
}