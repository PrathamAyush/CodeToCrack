#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
 int i,num,n;
 long int result =1;
 clrscr();

 printf("Enter the number\n");
 scanf("%d%",&num);
 printf("tell which power to calculate\n");
 scanf("%d",&n);

 for(i=1;i<=n;i++)
 result=result*num;

 printf("\n pow(%d^%d)=%ld",num,n,result);

getch();
}