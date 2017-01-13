#include<stdio.h>
int binarysearch(int [],int,int);
int findoffset(int [],int);
int getnum(int [],int,int);
main()
{
    int n;
    printf("Enter size");
    scanf("%d",&n);
    int arr[n],i,num;
    printf("Enter element\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter element to search\n");
    scanf("%d",&num);
    if(binarysearch(arr,n,num))
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
}
int binarysearch(int arr[],int n,int num)
{
    int offset,beg,end,mid;
    offset=findoffset(arr,n);
    beg=offset;
    end=n+offset;
    while(beg<=end)
    {
        mid=(beg+end)/2;
        if(num==getnum(arr,n,mid))
        {
            return 1;
        }
        else if(num<getnum(arr,n,mid))
        {
            end=mid-1;
        }
        else
        {
            beg=mid+1;
        }
    }
    return 0;
}
int findoffset(int arr[], int n)
{
    int beg,end,mid,pos;
    beg=0;
    end=n-1;
    while(beg<=end)
    {
        mid=(beg+end)/2;
        if(mid==0)
        {
            return 0;
        }
        if(arr[mid-1]<arr[mid] && arr[mid]<arr[mid+1])
        {
            end=mid-1;
        }
        else if(arr[mid-1]>arr[mid] && arr[mid]>arr[mid+1])
        {
            beg=mid+1;
        }
        else
        {
            pos=mid;
            break;
        }
    }
    return pos;
}
int getnum(int arr[], int n, int mid)
{
    if(mid>n-1)
    {
       return arr[mid%n];
    }
    else
    {
       return arr[mid];
    }
}
