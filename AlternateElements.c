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
void displayAlt()
{
    int track=1;
    Node* temp = head;
    printf("\nDisplaying Alternating Elements...\n");
    while(temp)
    {
        if(track%2)
        {
            printf("%d",temp->data);
            if(temp->next)
            {
                printf("-->");
            }
        }
        temp=temp->next;
        track++;
    }
}
void main()
{
    readSLL();
    displayAlt();
}