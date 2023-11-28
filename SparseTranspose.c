#include<stdio.h>
#define MAX_TERMS 100
typedef struct matrix
{
    int row;
    int column;
    int value;
}sparseMatrix;
sparseMatrix sparse[MAX_TERMS],sparseTranspose[MAX_TERMS];
int rows,cols,nonZeroCount;
void readSparse()
{
    int i,j;
    printf("\nEnter the Sparse Matrix :\n");
    scanf("%d %d %d",&rows,&cols,&nonZeroCount);
    sparse[0].row = rows;
    sparse[0].column = cols;
    sparse[0].value = nonZeroCount;
    for(i=1;i<=nonZeroCount;i++) scanf("%d %d %d",&sparse[i].row,&sparse[i].column,&sparse[i].value);
}
int convertTranspose()
{
    sparseTranspose[0].row = sparse[0].column;
    sparseTranspose[0].column = sparse[0].row;
    sparseTranspose[0].value = sparse[0].value;
    int i,j,k=1;
    for(i=1;i<=cols;i++)
    {
        for(j=1;j<=nonZeroCount;j++)
        {
            if(sparse[j].column == i)
            {
                sparseTranspose[k].row = sparse[j].column;
                sparseTranspose[k].column = sparse[j].row;
                sparseTranspose[k].value = sparse[j].value;
                k++;
            }
        }
    }
    return k;
}
void displaySparse(sparseMatrix sparse[],int n)
{
    for(int i=0;i<=n;i++) printf("\n%d %d %d",sparse[i].row,sparse[i].column,sparse[i].value);
}
void main()
{
    int n;
    readSparse();
    n = convertTranspose();
    displaySparse(sparseTranspose,n);
}