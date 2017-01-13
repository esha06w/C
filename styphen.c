#include<stdio.h>
main()
{
    int n,i,j;
    float temp,budget;
    scanf("%d",&n);
    float arr[n];
    for(i=0;i<n;i++)
    {
       scanf("%f",&arr[i]);
    }
    scanf("%f",&budget);
    for(i=0;i<n;i++)
    {
       for(j=0;j<n-1-i;j++)
       {
           if(arr[j]>arr[j+1])
           {
               temp=arr[j];
               arr[j]=arr[j+1];
               arr[j+1]=temp;
           }
        }
     }
  //    for(i=0;i<n;i++)
  //     printf("%f ",arr[i]);
  //   printf("\n");
     for(i=0;i<n;i++)
     {
        if(arr[i]*(n-i)>budget)
        {
            printf("%f",budget/(n-i));
            break;
        }
        else
        {
            budget=budget-arr[i];
        }
     }
}
