#include<stdio.h>
void bubbleSort(int n,int a[])
{
    int swapped;
    for(int i=0;i<n-1;i++)
    {
        swapped = 0;
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                swapped = 1;
            }
        }
        if(swapped==0) break;
    }
}
void main()
{
    int n;
    printf("\nEnter the size of array : ");
    scanf("%d",&n);
    int a[n];
    printf("\nEnter the elements : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    bubbleSort(n,a);
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}