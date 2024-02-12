#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node* next;
}Node;
Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
Node* head = NULL;
Node* tail = NULL;
void insertNode(int data)
{
    if(head==NULL)
    {
        Node* newNode = createNode(data);
        head=newNode;
        tail=newNode;
    }
    else
    {
        Node* newNode = createNode(data);
        tail->next = newNode;
        tail = newNode;
    }
}
void readSLL()
{
    int data,choice;
    printf("Reading Linked List...\n");
    do
    {
        printf("Enter the data : \n");
        scanf("%d",&data);
        insertNode(data);
        printf("Continue adding more elements?(1/0)\n");
        scanf("%d",&choice);
    }while(choice);
}
void nodeDiff(int pos1,int pos2)
{
    int track=1;
    Node* temp = head;
    int data1,data2;
    if(pos1==pos2)
    {
        printf("\nNode Difference : 0");
    }
    else
    {
        while(temp!=NULL && track<=pos2)
        {
            if(track==pos1)
            {
                data1 = temp->data;
            }
            else if(track==pos2)
            {
                data2 = temp->data;
            }
            track++;
            temp = temp->next;
        }
        printf("\nNode Difference : %d",(data2-data1));
    }
}
void main()
{
    int pos1,pos2;
    readSLL();
    printf("Enter pos 1\n");
    scanf("%d",&pos1);
    printf("Enter pos 2\n");
    scanf("%d",&pos2);
    nodeDiff(pos1,pos2);
}