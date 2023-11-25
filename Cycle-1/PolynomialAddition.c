#include<stdio.h>
#include<stdlib.h>
#define MAX_TERMS 100
typedef struct
{
    float coeff;
    int expo;
}polynomial;
polynomial firstPoly[MAX_TERMS],secondPoly[MAX_TERMS],resultPoly[MAX_TERMS];
int addPoly(int n1,int n2)
{
    int i,j,k;
    i=0;
    j=0;
    k=0;
    while(i<n1 && j<n2)
    {
        if(firstPoly[i].expo==secondPoly[j].expo)
        {
            resultPoly[k].coeff = firstPoly[i].coeff+secondPoly[j].coeff;
            resultPoly[k].expo = firstPoly[i].expo;
            i++;
            j++;
            k++;
        }
        else if(firstPoly[i].expo>secondPoly[j].expo)
        {
            resultPoly[k].coeff = firstPoly[i].coeff;
            resultPoly[k].expo = firstPoly[i].expo;
            i++;
            k++;
        }
        else
        {
            resultPoly[k].coeff = secondPoly[j].coeff;
            resultPoly[k].expo = secondPoly[j].expo;
            j++;
            k++;
        }
    }
    while(i<n1)
    {
        resultPoly[k].coeff = firstPoly[i].coeff;
        resultPoly[k].expo = firstPoly[i].expo;
        i++;
        k++;
    }
    while(j<n2)
    {
        resultPoly[k].coeff = secondPoly[j].coeff;
        resultPoly[k].expo = secondPoly[j].expo;
        j++;
        k++;
    }
    return k;
}
void displayPoly(polynomial poly[],int n)
{
    int i=0;
    for(i=0;i<n-1;i++)
    {
        printf("%.2fx^%d+",poly[i].coeff,poly[i].expo);
    }
    printf("%.2fx^%d",poly[i].coeff,poly[i].expo);
}
int readPoly(polynomial poly[])
{
    int n;
    printf("\nEnter the total number of terms in the polynomial :\n");
    scanf("%d",&n);
    printf("\nEnter the Coefficient and Exponenet in Descending Order");
    for(int i=0;i<n;i++)
    {
        printf("\nEnter the Coefficient-(%d) :",i+1);
        scanf("%f",&poly[i].coeff);
        printf("\nEnter the Exponent-(%d) :",i+1);
        scanf("%d",&poly[i].expo);
    }
    return n;
}
int main() {
    int n1,n2,n3;
    n1 = readPoly(firstPoly);
    printf("\nFirst Polynomial : ");
    displayPoly(firstPoly,n1);
    n2 = readPoly(secondPoly);
    printf("\nSecond Polynomial : ");
    displayPoly(secondPoly,n2);
    n3 = addPoly(n1,n2);
    printf("\nResultant Polynomial : ");
    displayPoly(resultPoly,n3);
    return 0;
}