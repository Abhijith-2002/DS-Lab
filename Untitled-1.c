#include<stdio.h>
typedef struct node
{
    int data;
    struct node* next;
}node;
node* first = NULL;
node* createNode(int data)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
}
void addEnd(int data)
{
    node* newNode = createNode(data);
    node* temp = first;
    if(first==NULL)
    {
        first = newNode;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void display()
{
    node* temp = first;
    if(first==NULL) printf("List Empty");
    else
    {
        while(temp!=NULL)
        {
            printf("%d",temp->data);
            temp->next;
        }
    }
}
void delete(int data)
{
    node* temp = first;
    if(first->data==data)
    {
        first = NULL;
    }
    else
    {
        while(temp->next->data!=data)
        {
            temp = temp->next;
        }
        node* del = temp->next;
        temp->next=temp->next->next;
        free(del);
    }
}
int main()
{
    int choice;
    do
    {
        int data;
        printf("1.Add elements\n");
        printf("2.Display Elements\n");
        printf("3.Delete Elements\n");
        printf("4.Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter value : ");
                scanf("%d",&data);
                addEnd(data);
                break;
            
            case 2:
                display();
                break;
            
            case 3:
                printf("Enter value that you want to delete : ");
                scanf("%d",&data);
                delete(data);
                break;

            case 4:
                break;

            default:
                printf("Invalid Choice\n");
                break;
        }
    }while(choice<4);
    return 0;
}