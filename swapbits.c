#include<stdio.h>
main()
{
   int n,a,b,res;
   scanf("%d",&n);
   a=n&15;
   a=a<<4;
   b=n>>4;
   res=a|b;
   printf("%d",res);
}
