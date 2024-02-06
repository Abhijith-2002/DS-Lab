#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 50
typedef struct Node
{
    int vertex;
    struct Node* next;
}Node;
Node* createNode(int v)
{
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
typedef struct Graph
{
    int V;
    bool adj[MAX][MAX];
    struct Node** adjlists;
}Graph;
Graph* initializeAdjacencyMatrix(int v)
{
    Graph* graph = malloc(sizeof(Graph));
    graph->V = v;
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            graph->adj[i][j] = false;
        }
    }
    return graph;
}
Graph* initializeAdjacencyList(int v)
{
    Graph* graph = malloc(sizeof(Graph));
    graph->V = v;
    graph->adjlists = malloc(v*sizeof(Node*));
    for(int i=0;i<v;i++)
    {
        graph->adjlists[i] = NULL;
    }
    return graph;
}
void addEdgeAdjMatrix(Graph* graph,int v,int w)
{
    graph->adj[v][w] = true;
}
void addEdgeAdjList(Graph* graph,int v,int w)
{
    Node* newNode = createNode(w);
    newNode->next = graph->adjlists[v];
    graph->adjlists[v] = newNode;

    newNode = createNode(v);
    newNode->next = graph->adjlists[w];
    graph->adjlists[w] = newNode;
}
void printMatrix(Graph* graph)
{
    for(int i = 0;i<graph->V;i++)
    {
        printf("%d : ",i);
        for(int j = 0;j<graph->V;j++)
        {
            printf("%d ",(int)graph->adj[i][j]);
        }
        printf("\n");
    }
}
void printList(Graph* graph)
{
    for(int v=0;v<graph->V;v++)
    {
        Node* temp = graph->adjlists[v];
        printf("%d : ",v);
        while(temp)
        {
            printf("%d ",temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}
void BFSAdjMatrix(Graph* graph,int s)
{
    bool visited[graph->V];
    for(int i=0;i<graph->V;i++)
    {
        visited[i] = false;
    }
    int queue[graph->V];
    int front = 0, rear = 0;
    visited[s] = true;
    queue[rear++] = s;
    while(front!=rear)
    {
        s = queue[front++];
        printf("%d ",s);
        for(int adjacent = 0;adjacent<graph->V;adjacent++)
        {
            if(graph->adj[s][adjacent] && !visited[adjacent])
            {
                visited[adjacent] = true;
                queue[rear++] = adjacent;
            }
        }
    }
}
void BFSAdjList(Graph* graph,int s)
{
    bool visited[graph->V];
    for(int i=0;i<graph->V;i++)
    {
        visited[i] = false;
    }
    int queue[graph->V];
    int front = 0, rear = 0;
    visited[s] = true;
    queue[rear++] = s;
    while(front!=rear)
    {
        s = queue[front++];
        printf("%d ",s);
        Node* temp = graph->adjlists[s];
        while(temp)
        {
            int adjVertex = temp->vertex;
            if(!visited[adjVertex])
            {
                visited[adjVertex] = true;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }
}
void DFSAdjMatrix(Graph* graph,int s)
{
    bool visited[graph->V];
    for(int i=0;i<graph->V;i++)
    {
        visited[i] = false;
    }
    int stack[graph->V];
    int top = -1;
    visited[s] = true;
    stack[++top] = s;
    while(top!=-1)
    {
        s = stack[top--];
        printf("%d ",s);
        for(int adjacent = 0;adjacent<graph->V;adjacent++)
        {
            if(graph->adj[s][adjacent] && !visited[adjacent])
            {
                visited[adjacent] = true;
                stack[++top] = adjacent;
            }
        }
    }
}
void DFSAdjList(Graph* graph,int s)
{
    bool visited[graph->V];
    for(int i=0;i<graph->V;i++)
    {
        visited[i] = false;
    }
    int stack[graph->V];
    int top=-1;
    visited[s] = true;
    stack[++top] = s;
    while(top!=-1)
    {
        s = stack[top--];
        printf("%d ",s);
        Node* temp = graph->adjlists[s];
        while(temp)
        {
            int adjVertex = temp->vertex;
            if(!visited[adjVertex])
            {
                visited[adjVertex] = true;
                stack[++top] = adjVertex;
            }
            temp = temp->next;
        }
    }
}
int main()
{
    int choice,V,v,w,s;
    Graph* graphM;
    Graph* graphL;
    do
    {
        printf("\nSelect an option : ");
        printf("\n1)Create graph(Adjacency Matrix)");
        printf("\n2)Create graph(Adjacency List)");
        printf("\n3)Add edge(Adjacency Matrix)");
        printf("\n4)Add edge(Adjacency List)");
        printf("\n5)Display adjacency matrix");
        printf("\n6)Display adjacency list");
        printf("\n7)BFS(Adjacency Matrix)");
        printf("\n8)BFS(Adjacency List)");
        printf("\n9)DFS(Adjacency Matrix)");
        printf("\n10)DFS(Adjacency List)");
        printf("\n11)Exit");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 :
                printf("\nEnter the number of vertices :");
                scanf("%d",&v);
                graphM = initializeAdjacencyMatrix(v);
                break;
            case 2 :
                printf("\nEnter the number of vertices :");
                scanf("%d",&v);
                graphL = initializeAdjacencyList(v);
                break;
            case 3 :
                printf("\nEnter the edge vertisces : ");
                scanf("%d %d",&v,&w);
                addEdgeAdjMatrix(graphM,v,w);
                break;                                                   
            case 4 :
                printf("\nEnter the edge vertisces : ");
                scanf("%d %d",&v,&w);
                addEdgeAdjList(graphL,v,w);
                break;
            case 5 :
                printMatrix(graphM);
                break;  
            case 6 :
                printList(graphL);
                break; 
            case 7 :
                printf("\nEnter the starting vertex : ");
                scanf("%d",&s);
                BFSAdjMatrix(graphM,s);
                break; 
            case 8 :
                printf("\nEnter the starting vertex : ");
                scanf("%d",&s);
                BFSAdjList(graphL,s);
                break;
            case 9 :
                printf("\nEnter the starting vertex : ");
                scanf("%d",&s);
                DFSAdjMatrix(graphM,s);
                break;
            case 10 :
                printf("\nEnter the starting vertex : ");
                scanf("%d",&s);
                DFSAdjList(graphL,s);
                break;
            default :
                break;
        }
    }while(choice<=10);
}