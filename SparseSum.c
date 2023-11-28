#include<stdio.h>
#define MAX_TERMS 100
typedef struct matrix
{
    int row;
    int column;
    int value;
}sparseMatrix;
sparseMatrix sparse1[MAX_TERMS],sparse2[MAX_TERMS],sparseResult[MAX_TERMS];
int rows,cols;
int SIZE1,SIZE2;
int readSparse(sparseMatrix sparse[])
{
    int i,j,nonZeroCount;
    printf("\nEnter the Sparse Matrix :\n");
    scanf("%d %d %d",&rows,&cols,&nonZeroCount);
    sparse[0].row = rows;
    sparse[0].column = cols;
    sparse[0].value = nonZeroCount;
    for(i=1;i<=nonZeroCount;i++) scanf("%d %d %d",&sparse[i].row,&sparse[i].column,&sparse[i].value);
    return nonZeroCount;
}
int Compatible()
{
    if(sparse1[0].row == sparse2[0].row && sparse1[0].column == sparse2[0].column) return 1;
    else return 0;
}
int sparseSum()
{
    sparseResult[0].row = sparse1[0].row;
    sparseResult[0].column = sparse1[0].column;
    int i=1;
    int j=1;
    int k=1;
    if(Compatible())
    {
        while(i<=SIZE1 && j<=SIZE2)
        {
            if(sparse1[i].row == sparse2[j].row && sparse1[i].column == sparse2[j].column)
            {
                sparseResult[k].row = sparse1[i].row;
                sparseResult[k].column = sparse1[i].column;
                sparseResult[k].value = sparse1[i].value + sparse2[j].value;
                i++;
                j++;
            }
            else if(sparse1[i].row == sparse2[j].row)
            {
                sparseResult[k].row = sparse1[i].row;
                if(sparse1[i].column < sparse2[j].column && i<SIZE1)
                {
                    sparseResult[k].column = sparse1[i].column;
                    sparseResult[k].value = sparse1[i].value;
                    i++;
                }
                else
                {
                    sparseResult[k].column = sparse2[j].column;
                    sparseResult[k].value = sparse2[j].value;
                    j++;
                }
            }
            else
            {
                if(sparse1[i].row < sparse2[j].row)
                {
                    sparseResult[k].row = sparse1[i].row;
                    sparseResult[k].column = sparse1[i].column;
                    sparseResult[k].value = sparse1[i].value;
                    i++;
                }
                else
                {
                    sparseResult[k].row = sparse2[j].row;
                    sparseResult[k].column = sparse2[j].column;
                    sparseResult[k].value = sparse2[j].value;
                }
            }
            k++;
        }
        while(i<SIZE1)
        {
            sparseResult[k].row = sparse1[i].row;
            sparseResult[k].column = sparse1[i].column;
            sparseResult[k].value = sparse1[i].value;
            k++;
            i++;
        }
        while(j<SIZE2)
        {
            sparseResult[k].row = sparse2[j].row;
            sparseResult[k].column = sparse2[j].column;
            sparseResult[k].value = sparse2[j].value;
            k++;
            j++;
        }
        sparseResult[0].value = k-1;
        return k-1;
    }
}
void displaySparse(sparseMatrix sparse[],int n)
{
    for(int i=0;i<=n;i++) printf("\n%d %d %d",sparse[i].row,sparse[i].column,sparse[i].value);
}
void main()
{
    int n;
    SIZE1 = readSparse(sparse1);
    SIZE2 = readSparse(sparse2);
    n = sparseSum();
    if(n) displaySparse(sparseResult,n);
}