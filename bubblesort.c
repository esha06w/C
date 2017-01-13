#include<stdio.h>
#include<sys/time.h>
void bubblesort(int a[],int n);
main()
{    struct timeval start, end;
     int a1[8000],a2[16000],i,j=0;
     int t1,t2;
     long starttime,endtime;
     for(i=8000;i>=1;i--)
     {    a1[j]=i;
          j++;
     }
     j=0;
     for(i=16000;i>=1;i--)
     {    a2[j]=i;
          j++;
     }
     gettimeofday(&start,NULL);
     bubblesort(a1,8000);
     gettimeofday(&end,NULL);
     starttime=start.tv_sec*1000000+start.tv_usec;
     endtime=end.tv_sec*1000000+end.tv_usec;
     t1=endtime-starttime;
     gettimeofday(&start,NULL);
     bubblesort(a2,16000);
     gettimeofday(&end,NULL);
     starttime=start.tv_sec*1000000+start.tv_usec;
     endtime=end.tv_sec*1000000+end.tv_usec;
     t2=endtime-starttime;
     printf("%f",t2/(float)t1);
}
void bubblesort(int a[],int n)
{    int i,j,temp;
     for(i=0;i<n;i++)
     {    for(j=0;j<n-1-i;j++)
         {    if(a[j]>a[j+1])
              {    temp=a[j];
                   a[j]=a[j+1];
                   a[j+1]=temp;
              }
         }
     
