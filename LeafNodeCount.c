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
int leafCount(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    else if(root->left==NULL && root->right==NULL)
    {
        return 1;
    }
    else
    {
        return leafCount(root->left)+leafCount(root->right);
    }
}
void main()
{
    Node* root = NULL;
    int data,choice;
    printf("Reading Tree...\n");
    do
    {
        printf("Enter the node data : \n");
        scanf("%d",&data);
        root = insertNode(root,data);
        printf("Continue adding more nodes?(1/0)\n");
        scanf("%d",&choice);
    }while(choice);
    printf("\nLeaf Count : %d",leafCount(root));
}