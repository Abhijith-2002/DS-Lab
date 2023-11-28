#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX_TERMS 100
typedef struct
{
    float coeff;
    int expo;
}polynomial;
polynomial poly[MAX_TERMS];
int readPoly()
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
void displayPoly(int n)
{
    int i=0;
    for(i=0;i<n-1;i++)
    {
        printf("%.2fx^%d+",poly[i].coeff,poly[i].expo);
    }
    printf("%.2fx^%d",poly[i].coeff,poly[i].expo);
}
int evalPoly(int x,int n)
{
    float result;
    for(int i=0;i<n;i++)
    {
        result+=(poly[i].coeff)*(pow(x,poly[i].expo));
    }
    return result;
}
int main() {
    int n,x,result;
    n = readPoly(poly);
    printf("\nPolynomial : ");
    displayPoly(n);
    printf("\nEnter the value of x : ");
    scanf("%d",&x);
    result = evalPoly(x,n);
    printf("\nThe result of polynomial evaluation : %d",result);
    return 0;
}