#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}Node;
Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
Node* insertNode(Node* root,int data)
{
    if(root==NULL)
    {
        return createNode(data);
    }
    else if(data<root->data)
    {
        root->left = insertNode(root->left,data);
    }
    else
    {
        root->right = insertNode(root->right,data);
    }
    return root;
}
void preOrder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    printf("%d",root->data);
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    inOrder(root->left);
    printf("%d",root->data);
    inOrder(root->right);
}
void postOrder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d",root->data);
}
void levelOrder(Node* root)
{
    Node* queue[50];
    int front = -1;
    int rear = -1;
    Node* temp = root;
    queue[++rear] = temp;
    while(front!=rear)
    {
        temp = queue[++front];
        printf("%d",temp->data);
        if(temp->left)
        {
            queue[++rear] = temp->left;
        }
        if(temp->right)
        {
            queue[++rear] = temp->right;
        }
    }
}
Node* minValueNode(Node* root)
{
    Node* temp = root;
    while(temp->left)
    {
        temp = temp->left;
    }
    return temp;
}
Node* deleteNode(Node* root,int data)
{
    if(root==NULL) 
    {
        return root;
    }
    if(data<root->data)
    {
        root->left = deleteNode(root->left,data);
    }
    else if(data>root->data)
    {
        root->right = deleteNode(root->right,data);
    }
    else
    {
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            root = NULL;
        }
        else if(root->left==NULL)
        {
            Node* temp = root;
            root = root->right;
            free(temp);
        }
        else if(root->right==NULL)
        {
            Node* temp = root;
            root = root->left;
            free(temp);
        }
        else
        {
            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right,temp->data);
        }
    }
    return root;
}
Node* searchNode(Node* root,int data)
{
    if(root==NULL || root->data==data)
    {
        return root;
    }
    else if(data<root->data)
    {
        return searchNode(root->left,data);
    }
    else
    {
        return searchNode(root->right,data);
    }
}
void main()
{
    int choice,data,option;
    Node* root = NULL;
    do
    {
        printf("\nSelect an option : ");
        printf("\n1)Insertion");
        printf("\n2)Traversal");
        printf("\n3)Deleteion");
        printf("\n4)Search");
        printf("\n5)Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 :
                printf("\nEnter data to be inserted :");
                scanf("%d",&data);
                root = insertNode(root,data);
                break;
            case 2 :
                printf("\nSelect an option : ");
                printf("\n1)PreOrder traversal");
                printf("\n2)InOrder traversal");
                printf("\n3)PostOrder traversal");
                printf("\n4)LevelOrder traversal\n");
                scanf("%d",&option);
                switch (option)
                {
                case 1:
                    preOrder(root);
                    break;
                case 2:
                    inOrder(root);
                    break;
                case 3:
                    postOrder(root);
                    break;
                case 4:
                    levelOrder(root);
                    break;
                default:
                    break;
                }
                break;
            case 3 :
                printf("\nEnter the data to be deleted : ");
                scanf("%d",&data);
                root = deleteNode(root,data);
                break;
            case 4 :
                printf("\nEnter the data to be searched : ");
                scanf("%d",&data);
                if(searchNode(root,data))
                {
                    printf("\nFound!");
                }
                else
                {
                    printf("\nNot Found!");
                }
                break;;
            default :
                break;
        }
    }while(choice<=4);
}
