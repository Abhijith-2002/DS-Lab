#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct DoublyLinkedList
{
    char data;
    struct DoublyLinkedList *next;
    struct DoublyLinkedList *prev;
}DoublyLinkedList;
struct DoublyLinkedList *head = NULL;
int isEmpty()
{
    if(head==NULL) return 1;
    else return 0;
}
DoublyLinkedList* createNode(char ch)
{
    DoublyLinkedList* newNode = (DoublyLinkedList*)malloc((sizeof(DoublyLinkedList)));
    if(newNode == NULL) 
    {
        printf("\nError : Memory Allocation Failed !");
        exit(0);
    }
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->data = ch;
    return(newNode);
}
void insert(char ch)
{
    DoublyLinkedList *temp = head;
    DoublyLinkedList *newNode = createNode(ch);
    if(isEmpty())
    {
        head = newNode;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}
int palindrome()
{
    DoublyLinkedList *temp = head;
    DoublyLinkedList *ptr = head;
    while(ptr->next!=NULL)
    {
        ptr = ptr->next;
    }
    while(temp->next!=NULL)
    {
        if(temp->data!=ptr->data)
        {
            return 0;
            break;
        }
        else{
            temp = temp->next;
            ptr = ptr->prev;
            return 1;
        }
    }
}
int main()
{
    char str[20];
    printf("Enter the word :");
    scanf("%s",&str);
    for(int i = 0;i < strlen(str); i++)
    {
        insert(str[i]);
    }
    if(palindrome()) printf("Palindrome");
    else printf("Not Palindrome");
    return 0;
}