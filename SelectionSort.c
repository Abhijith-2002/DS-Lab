#include<stdio.h>
void selectionSort(int n,int a[])
{
    for(int i=0;i<n;i++)
    {
        int min = i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            {
                min = j;
            }
        }
        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
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
    selectionSort(n,a);
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}