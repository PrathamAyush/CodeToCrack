#include<iostream.h>
#include<conio.h>
class avg
{
  public:
       float num1,num2,num3,average;
       void input()
	{
	  clrscr();
	  cout<<"Enter 3 number to calculate average"<<endl;
	  cin>>num1>>num2>>num3;
	}
       void findAvg()
	{
	  average=(num1+num2+num3)/3;
	}
       void display()
	{
	  cout<<"Average of the given number is:"<<average<<endl;
	  getch();
	}
   };
int main()
 {
    avg A;
    A.input();
    A.findAvg();
    A.display();
   return 0;
}
