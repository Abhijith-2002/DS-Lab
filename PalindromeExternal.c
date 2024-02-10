#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Node
{
    char data;
    struct Node* next;
    struct Node* prev;
}Node;
Node* createNode(char data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
Node* head = NULL;
Node* tail = NULL;
void insertNode(char data)
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
        newNode->prev = tail;
        tail = newNode;
    }
}
void readDLL()
{
    char str[50];
    printf("\nEnter the word : \n");
    scanf("%s",str);
    int i = 0;
    while(str[i]!='\0')
    {
        insertNode(str[i]);
        i++;
    }
}
void checkPalindrome()
{
    Node* fptr = head;
    Node* bptr = tail;
    bool palindrome = true;
    while(fptr!=bptr)
    {
        if(fptr->data!=bptr->data)
        {
            palindrome = false;
            break;
        }
        fptr = fptr->next;
        bptr = bptr->prev;
    }
    if(palindrome)
    {
        printf("\nPalindrome\n");
    }
    else
    {
        printf("\nNot Palindrome\n");
    }
}
void main()
{
    readDLL();
    checkPalindrome();
}