#include<stdio.h>
void insertionSort(int n,int a[])
{
    for(int i=1;i<n;i++)
    {
        int key = a[i];
        int j = i-1;
        while(j>=0 && a[j]>key)
        {
            a[j+1] = a[j];
            j = j-1;
        }
        a[j+1] = key;
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
    insertionSort(n,a);
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}