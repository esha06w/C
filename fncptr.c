#include<stdio.h>
#include<string.h>
void bubblesort(char *[],int ,int (*)(char *,char*));
int lexo(char *,char *);
int numeric(char *,char *);
int numericrev(char *,char *);
int lexoignc(char *,char *);
main(int argc,char *argv[])
{
    char *str[]={"15","273","18","6"};
    int length=4;
    if(argc == 1)
    {
        bubblesort(str,length,&lexo);
    }
    else if(strcmp(argv[1],"-n") == 0)
    {
        bubblesort(str,length,&numeric);
    }
    else if(strcmp(argv[1],"-r") == 0)
    {
        bubblesort(str,length,&numericrev);
    }
    else if(strcmp(argv[1],"-f") == 0)
    {
        bubblesort(str,length,&lexoignc);
    }
    else
    {
        printf("Something wrong");
    }
}
void bubblesort(char *str[],int len,int (*fp)(char *,char *))
{
    printf("\nBubble sort\n");
    int i,j;
    char *temp;
    for(i = 0;i < len;i++)
    {
       for(j = 0;j < len-1-i;j++)
       {
          if((*fp)(str[j],str[j+1]))
          {
             // strcpy(temp,str[i]);
             // strcpy(str[i],str[j]);
             // strcpy(str[j],temp);
              temp = str[j];
              str[j] = str[j+1];
              str[j+1] = temp;
              printf("swap\n");
          }
       }
    }
    for(i=0;i<len;i++)
    {
       printf("%s  ",str[i]);
    }
    printf("\n");
}
int lexo(char *x,char *y)
{
    printf("**%s %s**\n",x,y);
    if(strcmp(x,y) > 0)
        return 1;
    return 0;
}
int numeric(char *x,char *y)
{
   // printf("\n2\n");
    int a = atoi(x);
    int b = atoi(y);
    if(a > b)
        return 1;
    return 0;
}
int numericrev(char *x,char *y)
{ 
    printf("\n3\n");
    return 0;
}
int lexoignc(char *x,char *y)
{
    printf("\n4\n");
    return 0;
}
