#include<stdio.h>
void linear_search(int keys[],int n,int search) {
    int i;
    for(i=0;i<n;i++) {
        if(keys[i]==search) {
            printf("\nElement found at index %d",i);
            break;
        }
    }
}
int main() {
    int i,n,search;
    printf("\nEnter the number of elements : ");
    scanf("%d",&n);
    int keys[n];
    for(i=0;i<n;i++) {
        printf("\nEnter the element %d :",i);
        scanf("%d",&keys[i]);
    }
    printf("\nEnter the element to search : \n");
    scanf("%d",&search);
    linear_search(keys,n,search);
    return 0;
}