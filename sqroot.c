#include<stdio.h>
int sq(int n,int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        if(mid*mid==n)
            return mid;
        else if(mid*mid<n)
            return sq(n,mid+1,high);
         else
            return sq(n,low,mid-1);
    }
    else
    {
        if(low==0)
            return 0;
        else if(high*high>n)
            return high-1;
        else
            return high;
    }
}
main()
{
    int num,result;
    printf("Enter number");
    scanf("%d",&num);
    result=sq(num,0,num);
    printf("%d",result);
}
    
