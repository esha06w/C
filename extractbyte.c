#include<stdio.h>
main()
{
    int pos,res,num,n;
   // printf("Enter number");
    scanf("%d",&num);
   // num=0x12345678;
    num=0x(num);
    printf("Enter position");
    scanf("%d",&pos);
    n=0xFF;
    res=num&(n<<(pos*8));
    res=res>>(pos*8);
    printf("%0x",res);
}
