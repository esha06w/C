#include<stdio.h>
#include<string.h>
main()
{
    char str[100],temp;
    printf("Enter a string");
    scanf("%s",str);
    int i,j,k,dif,min=999,len,pos;
    len=strlen(str);
    for(i=len-2;i>=0;i--)
    {
        if(str[i+1]<str[i])
        {
            for(j=i+1;j<len;j++)
            {
                dif=str[i]-str[j];
                if(dif>0 && dif<min)
                {
                    min=dif;
                    pos=j;
                }
            }
            temp=str[i];
            str[i]=str[pos];
            str[pos]=temp;
            int count=0;
            for(j=i+1;j<len;j++)
            {
                for(k=i+1;k<len-1-count;k++)
                {
                     if(str[k]<str[k+1])
                     {
                        temp=str[k];
                        str[k]=str[k+1];
                        str[k+1]=temp;
                     }
                }
                count++;
            }
            break;
        }
   }
   printf("%s",str);
}
