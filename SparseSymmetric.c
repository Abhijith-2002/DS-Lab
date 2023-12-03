#include <stdio.h>
#define SIZE 100
typedef struct sparseMatrix
{
    int row;
    int col;
    int val;
} sparseMatrix;
sparseMatrix sparse[SIZE], sparseTranspose[SIZE];
void readSparse()
{
    scanf("%d %d %d", &sparse[0].row, &sparse[0].col, &sparse[0].val);
    for (int i = 1; i <= sparse[0].val; i++)
    {
        scanf("%d %d %d", &sparse[i].row, &sparse[i].col, &sparse[i].val);
    }
}

int transpose()
{
    sparseTranspose[0].row = sparse[0].col;
    sparseTranspose[0].col = sparse[0].row;
    sparseTranspose[0].val = sparse[0].val;
    int i,j;
    int k = 1;
    while (k <= sparse[0].val)
    {
        for(j=0;j<sparse[0].col;j++)
        {
            for(i=1;i<=sparse[0].val;i++)
            {
                if(sparse[i].col == j)
                {
                sparseTranspose[k].row = sparse[i].col;
                sparseTranspose[k].col = sparse[i].row;
                sparseTranspose[k].val = sparse[i].val;
                k++;
                }
            }
        }
    }
    return k;
}
int symmetric()
{
    if(sparse[0].row != sparse[0].col)
    {
        return 0;
    }
    else
    {
        for(int i=1;i<=sparse[0].val;i++)
        if(sparse[i].val != sparseTranspose[i].val)
        {
            return 0;
            break;
        }
        else return 1;
    }
}
void displaySparse(sparseMatrix sparse[], int k)
{
    int i;
    for (i = 0; i < k; i++)
    {
        printf("%d %d %d\n", sparse[i].row, sparse[i].col, sparse[i].val);
    }
}
int main()
{
    int k;
    printf("\nEnter the sparse matrix : \n");
    readSparse();
    printf("\nTranspose : \n");
    k = transpose();
    displaySparse(sparseTranspose,k);
    if(symmetric()) printf("Symmetric");
    else printf("Not Symmetric");
    return 0;
}