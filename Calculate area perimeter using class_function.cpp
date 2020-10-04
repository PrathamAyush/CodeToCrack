#include<iostream>
#include<conio.h>
using namespace std;
class ractangle
{
  public:
      float length,breadth;
      float area()
       {
	   return length*breadth;
       }
      float perimeter()
       {
	   return 2*(length*breadth);
       }
};
void main()
{
    ractangle one,two;
    clrscr();
    cout<<"Enter length and breadth of first ractangle"<<endl;
    cin>>one.length>>one.breadth;
    cout<<"Area of first ractangle is ="<<one.area()<<endl;
    cout<<"Perimeter of first ractangle is ="<<one.perimeter()<<endl;
    cout<<"-------------------------------------------------"<<endl;
    cout<<"Enter lenght and breadth of second ractangle"<<endl;
    cin>>two.length>>two.breadth;
    cout<<"Area vof second ractangle is ="<<two.area()<<endl;
    cout<<"Perimeter of second ractangle is ="<<two.perimeter()<<endl;
    getch();
}
