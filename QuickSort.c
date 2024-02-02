#include<stdio.h>
int partition(int a[],int low,int high)
{
    int pivot = a[low];
    int k = high;
    for(int i=high;i>low;i--)
    {
        if(a[i]>pivot)
        {
            int temp = a[i];
            a[i] = a[k];
            a[k] = temp;
            k--;
        }
    }
    int temp = a[k];
    a[k] = a[low];
    a[low] = temp;
    return k;
}
void quickSort(int a[],int low,int high)
{
    if(low<high)
    {
        int pi = partition(a,low,high);
        quickSort(a,low,pi-1);
        quickSort(a,pi+1,high);
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
    quickSort(a,0,n-1);
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}