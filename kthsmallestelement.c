#include<stdio.h>
int partition(int [],int,int);
void swap1(int [],int,int);
int quicksort(int arr[],int low,int high,int k)
{
    if(k>0 && k<=(high-low+1))
   {
    int par=partition(arr,low,high);
    if(par-low==k-1)
    return arr[par];
    else if(par-low>k-1)
    return quicksort(arr,low,par - 1,k);
    else
    return quicksort(arr,par + 1,high,k+low-par-1);
   }
  return 0;
}
int partition(int arr[],int low,int high)
{
    int r = rand() % (high - low + 1);
    int pivot = low + r;
    swap1(arr, high, pivot);
    printf("***%d***\n",pivot);
    int j;
    int i = low-1;
    for(j = low;j <= high;j++)
    {
        if(arr[j] < arr[high])
        {
            swap1(arr,j,++i);
        }
    }
    swap1(arr,i+1,high);
    return i+1;
}
void swap1(int arr[],int x,int y)
{
    int temp;
    if(x == y) return;
    temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}
main()
{
    int n;
    printf("Enter size");
    scanf("%d",&n);
    int i,arr[n];
    for(i = 0;i < n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int k;
    printf("Enter value of k");
    scanf("%d",&k);
    int res=quicksort(arr,0,n-1,k);
    printf("\nRes %d\n",res);
    for(i = 0;i < n;i++)
    {
        printf("%d ",arr[i]);
    }
}
