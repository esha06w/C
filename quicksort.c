#include<stdio.h>
int partition(int [],int,int);
void swap(int *,int *);
void quicksort(int [],int,int);
main()
{
    int n,i;
    printf("Enter size");
    scanf("%d",&n);
    printf("Enter elements");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    quicksort(a,0,n-1);
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    
}
void quicksort(int a[],int low,int high)
{
    if(low<high)
    {
        int par=partition(a,low,high);
        quicksort(a,low,par-1);
        quicksort(a,par+1,high);
    }
}
int partition(int a[],int low,int high)
{
    int pivot=a[high];
    int i=low-1;
    int j;
    for(j=low;j<high;j++)
    {
        if(a[i]<pivot)
        {
            i++;
            swap(&a[i],&a[j]);
        }
     }
     swap(&a[i+1],&a[high]);
     return (i+1);
}
void swap(int *a,int *b)
{
     int temp=*a;
     *a=*b;
     *b=temp;
}
     
