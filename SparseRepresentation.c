#include<stdio.h>
typedef struct matrix
{
    int row;
    int column;
    int value;
}matrix;
int rows,cols,normalMatrix[10][10];
matrix sparseMatrix[100];
int nonZeroCount;
void readMatrix()
{
    printf("\nEnter the number of rows : ");
    scanf("%d",&rows);
    printf("\nEnter the number of columns : ");
    scanf("%d",&cols);
    printf("\nEnter the elements : \n");
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            scanf("%d",&normalMatrix[i][j]);
        }
    }
}
void convertSparse()
{
    sparseMatrix[0].row = rows;
    sparseMatrix[0].column = cols;
    int rowNo=1;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(normalMatrix[i][j]!=0)
            {
                sparseMatrix[rowNo].row = i;
                sparseMatrix[rowNo].column = j;
                sparseMatrix[rowNo].value = normalMatrix[i][j];
                rowNo++;
                nonZeroCount++;
            }
        }
    }
    sparseMatrix[0].value = nonZeroCount;
}
void displaySparse()
{
    for(int i=0;i<=nonZeroCount;i++)
    {
        printf("\n%d\t%d\t%d",sparseMatrix[i].row,sparseMatrix[i].column,sparseMatrix[i].value);
    }
}
void sparsity()
{
    float sparsity;
    sparsity = (((rows*cols)-nonZeroCount)/(float)(rows*cols));
    printf("\nThe sparsity of the matrix is : %f",sparsity);
}
void main()
{
    printf("\nEnter the matrix : ");
    readMatrix();
    convertSparse();
    displaySparse();
    sparsity();
}
