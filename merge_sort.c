#include<stdio.h>
void mergesort(int[],int,int,int[]);
void merge(int[],int,int,int,int[]);
int main()
{
    int n;
    printf("Enter size");
    scanf("%d",&n);
    int i,arr[n],aux[n];
    printf("Enter elements");
    for(i=0;i<n;i++)
    {
       scanf("%d",&arr[i]);
    }
    mergesort(arr,0,n-1,aux);
    for(i=0;i<n;i++)
    {
       printf("%d ",arr[i]);
    }
}
void mergesort(int arr[],int left,int right,int aux[])
{
    if(left<right)
    {
    int mid=(left+right)/2;
    mergesort(arr,left,mid,aux);
    mergesort(arr,mid+1,right,aux);
    merge(arr,left,mid,right,aux);
    }
}
void merge(int arr[],int left,int mid,int right,int aux[])
{
    int i,j,k;
    int n1=mid-left+1;
    int n2=right-mid;
    int l[n1],r[n2];
    for(i=0;i<n1;i++)
        l[i]=arr[left+i];
    for(j=0;j<n2;j++)
        r[j]=arr[mid+1+j];
    i=0;j=0;k=left;
    while(i<n1 && j<n2)
    {
        if(l[i]<r[j])
        {
            arr[k++]=l[i++];
        }
        else
        {
            arr[k++]=r[j++];
        }
    }
    while(i<n1)
    {
        arr[k++]=l[i++];
    }
    while(j<n2)
    {
        arr[k++]=r[j++];
    }
    /* for(i=left;i<right;i++)
     {
         arr[i]=aux[i];

     }*/
}
