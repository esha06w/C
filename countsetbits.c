#include<stdio.h>
main()
{
    int n,flag=0,i;
    scanf("%d",&n);
    for(i=1;i<n;i++)
    {
        if(i + countsetbits(i) == n)
        {
             flag=1;
             break;
        }
    }
    if(flag==1)
       printf("false");
    else
       printf("true");
}
int countsetbits(int n)
{   int count=0;
    
       while(n!=0)
       {
           count=count + (n & 1);
	   n=n>>1;
       }
    
    return count;
}
