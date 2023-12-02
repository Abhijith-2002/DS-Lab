#include<stdio.h>
#include<stdlib.h>
typedef struct DoublyLinkedList
{
    float coef;
    int expo;
    struct DoublyLinkedList *next;
    struct DoublyLinkedList *prev;
}DoublyLinkedList;
DoublyLinkedList* head1=NULL;
DoublyLinkedList* head2=NULL;
DoublyLinkedList* head3=NULL;
int isEmpty(DoublyLinkedList* head)
{
    if(head==NULL) return 1;
    else return 0;
}
DoublyLinkedList* createNode(float coef,int expo)
{
    DoublyLinkedList* newNode = (DoublyLinkedList*)malloc((sizeof(DoublyLinkedList)));
    if(newNode == NULL) 
    {
        printf("\nError : Memory Allocation Failed !");
        exit(0);
    }
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->coef = coef;
    newNode->expo = expo;
    return(newNode);
}
void createPoly(DoublyLinkedList** head)
{
    float coef;
    int expo,choice;
    do
    {
        printf("\nEnter the coefficient :");
        scanf("%f",&coef);
        printf("\nEnter the exponent :");
        scanf("%d",&expo);
        DoublyLinkedList* newNode = createNode(coef,expo);
        if(isEmpty(*head))
        {
            *head = newNode;
        }
        else
        {
            DoublyLinkedList* temp = *head;
            while(temp->next!=NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
        printf("\nDo you want to add more terms?(Y=1/N=0)");
        scanf("%d",&choice);
    }
    while(choice);
}
void addPoly()
{
    DoublyLinkedList* temp1 = head1;
    DoublyLinkedList* temp2 = head2;
    while(temp1 && temp2)
    {
        if(temp1->expo>temp2->expo)
        {
            DoublyLinkedList* newNode = createNode(temp1->coef,temp1->expo);
            if(isEmpty(head3))
            {
                head3 = newNode;
            }
            else
            {
                DoublyLinkedList* temp3 = head3;
                while(temp3->next!=NULL)
                {
                    temp3=temp3->next;
                }
                temp3->next = newNode;
                newNode->prev = temp3;
            }
            temp1 = temp1->next;
        }
        else if(temp2->expo>temp1->expo)
        {
            DoublyLinkedList* newNode = createNode(temp2->coef,temp2->expo);
            if(isEmpty(head3))
            {
                head3 = newNode;
            }
            else
            {
                DoublyLinkedList* temp3 = head3;
                while(temp3->next!=NULL)
                {
                    temp3=temp3->next;
                }
                temp3->next = newNode;
                newNode->prev = temp3;
            }
            temp2 = temp2->next;
        }
        else
        {
            DoublyLinkedList* newNode = createNode(temp1->coef+temp2->coef,temp1->expo);
            if(isEmpty(head3))
            {
                head3 = newNode;
            }
            else
            {
                DoublyLinkedList* temp3 = head3;
                while(temp3->next!=NULL)
                {
                    temp3=temp3->next;
                }
                temp3->next = newNode;
                newNode->prev = temp3;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    while(temp1 || temp2)
    {
        if(temp1)
        {
            DoublyLinkedList* newNode = createNode(temp1->coef,temp1->expo);
            if(isEmpty(head3))
            {
                head3 = newNode;
            }
            else
            {
                DoublyLinkedList* temp3 = head3;
                while(temp3->next!=NULL)
                {
                    temp3=temp3->next;
                }
                temp3->next = newNode;
                newNode->prev = temp3;
            }
            temp1 = temp1->next;
        }
        if(temp2)
        {
            DoublyLinkedList* newNode = createNode(temp2->coef,temp2->expo);
            if(isEmpty(head3))
            {
                head3 = newNode;
            }
            else
            {
                DoublyLinkedList* temp3 = head3;
                while(temp3->next!=NULL)
                {
                    temp3=temp3->next;
                }
                temp3->next = newNode;
                newNode->prev = temp3;
            }
            temp2 = temp2->next;
        }
    }
}
void showPoly(DoublyLinkedList* head)
{
    DoublyLinkedList* temp = head;
    while(temp->next!=NULL)
    {
        printf("%.2fx^%d+",temp->coef,temp->expo);
        temp=temp->next;
    }
    printf("%.2fx^%d",temp->coef,temp->expo);
}
void main()
{
    printf("\nEnter the first polynomial: ");
    createPoly(&head1);
    showPoly(head1);
    printf("\nEnter the second polynomial: ");
    createPoly(&head2);
    showPoly(head2);
    printf("\nResult :");
    addPoly();
    showPoly(head3);
}