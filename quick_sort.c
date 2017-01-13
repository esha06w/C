#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int partition(struct student [],int,int,int (*)(char [],char []));
void swap(struct student,struct student);
void quicksort(struct student [],int,int,int (*)(char [],char []));
int cmpstr(struct student,struct student);
int cmpint(char [],char []);
int cmpflt(char [],char []);
struct student
{ char name[20];
  char age[5];
  char marks[5];
};
main()
{
    int n,i;
    printf("Enter size");
    scanf("%d",&n);
    struct student s[n];
    printf("Enter elements");
    for(i=0;i<n;i++)
    {
        scanf("%s",s[i].name);
        scanf("%s",s[i].age);
        scanf("%s",s[i].marks);
    }
    int ch;
    printf("\n1.a/c to name\n2.a/c to age\n3.a/c to marks\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: quicksort(a,0,n-1,cmpstr);
                break;
        case 2: quicksort(a,0,n-1,cmpint);
                break;
        case 3: quicksort(a,0,n-1,cmpflt);
                break;
        default: printf("\nWrong option\n");
    }
    printf("\nOUTPUT\n");
    for(i=0;i<n;i++)
    {
        printf("%s %s %s\n",s[i].name,s[i].age,s[i].marks);
    }
    
}
void quicksort(struct student a[],int low,int high,int (*fp)(char [],char []))
{
    if(low<high)
    {
        int par=partition(a,low,high,fp);
        quicksort(a,low,par-1,fp);
        quicksort(a,par+1,high,fp);
    }
}
int partition(struct student a[],int low,int high,int (*fp)(char [],char []))
{
    char pivot[20];
    strcpy(pivot,a[high]);
    int i=low-1;
    int j;
    for(j=low;j<high;j++)
    {
        if((*fp)(a[j],pivot)<0)
        {
            i++;
            swap(&a[i],&a[j]);
        }
     }
     swap(&a[i+1],&a[high]);
     return (i+1);
}
void swap(struct student a,struct student b)
{
     struct student temp;
     temp=a;
     a=b;
     b=temp;
}
int cmpstr(struct student a,struct student b)
{
    if(strcmp(a.name,b.name)<0)
       return 1;
    else return 0;
}
int cmpint(char a[], char b[])
{

}
int cmpflt(char a[],char b[])
{

}
