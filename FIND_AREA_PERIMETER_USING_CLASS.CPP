#include<iostream>   //iostream.h is old lib use in Turbo C++
#include<conio.h>

class rectangle
{
public:
    int length,width,length1,width1,area,perimeter,area1,perimeter1;
    void input()
    {
	clrscr();
	cout<<"Enter length of first rectangle:"<<endl<<"\t";
	cin>>length;
	cout<<"Enter width of first rectaingle:"<<endl<<"\t";
	cin>>width;
	cout<<"Enter length of second rectangle:"<<endl<<"\t";
	cin>>length1;
	cout<<"Enter Width of second rectangle:"<<endl<<"\t";
	cin>>width1;
    }
    void findArea()
    {
	area=length*width;
	area1=length1*width1;
    }
    void findPerimeter()
    {
	perimeter=2*(length+width);
	perimeter1=2*(length1+width1);
    }
    void display()
    {
	cout<<"Area of first rectangle is:"<<area<<endl;
	cout<<"Perimeter of first rectangle is:"<<perimeter<<endl;
	cout<<"-------------------------------------------"<<endl;
	cout<<"Area of second rectangle is:"<<area1<<endl;
	cout<<"Perimeter of second rectangle is:"<<perimeter1<<endl;
    getch();
    }
};
int main()
{
rectangle obj;
    obj.input();
    obj.findArea();
    obj.findPerimeter();
    obj.display();
    return 0;

}

