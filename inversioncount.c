#include<stdio.h>
int mergesort(int[],int,int);
int merge(int[],int,int,int);
main()
{
    int i,n;
    printf("Enter size");
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int inversioncount=mergesort(arr,0,n-1);
    printf("%d\n",inversioncount);
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
int mergesort(int arr[],int left,int right)
{
    int inv=0;
   if(left<right)
   {
    int mid=(left+right)/2;
    inv=mergesort(arr,left,mid);
    inv+=mergesort(arr,mid+1,right);
    inv+=merge(arr,left,mid,right);
   }
    return inv;
}
int merge(int arr[],int left,int mid,int right)
{
    int inv=0,n1,n2,i,j,k;
    n1=mid-left+1;
    n2=right-mid;
    int a1[n1],a2[n2];
    for(i=0;i<n1;i++)
    {
        a1[i]=arr[left+i];
    }
    for(j=0;j<n2;j++)
    {
        a2[j]=arr[mid+1+j];
    }
    i=0;
    j=0;
    k=left;
    while(i<n1 && j<n2)
    {
        if(a1[i]<a2[j])
        {
            arr[k++]=a1[i];
            i++;
        }
        else
        {
            arr[k++]=a2[j];
            j++;
            inv+=(mid-i+1);
        }
    }
    while(i<n1)
    {
        arr[k++]=a1[i];
        i++;
    }
    while(j<n2)
    {
        arr[k++]=a2[j];
        j++;
    }
    /*int inv=0;
    int i,j,k;
    i=left;
    j=mid+1;
    k=left;
    while(i<=mid && j<=right)
    {
       if(arr[i]<=arr[j])
       {
            aux[k++]=arr[i++];
       }
       else
       {
            aux[k++]=arr[j++];
            inv=inv+(mid-i+1);
       }
    }
    while(i<=mid)
    {
        aux[k++]=arr[i++];
    }
    while(j<=right)
    {
         aux[k++]=arr[j++];
    }
    for(i=left;i<=right;i++)
    {
         arr[i]=aux[i];
    }*/
    return inv;
}

