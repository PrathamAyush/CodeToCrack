#include<iostream> //iostream.h is old lib use in Turbo C++
#include<conio.h>
void main()        //Also use "int main()".Note "int main()" wants return value so you use "int main()" you should have to return value to "main function"
{
clrscr();
 int arr[2][2];
 int sleft=0,sright=0;
 cout<<"Enter element into the matrix"<<endl;
 for(int i=0;i<2;i++)
 {
  for(int j=0;j<2;j++)
   {
     cout<<"enter element into row: "<< i + 1 <<" and column: "<< j + 1<<endl;
     cin>>arr[i][j];
      if(i==j)
	sleft=sleft+arr[i][j];
      if((i+j)==2-1)
	sright=sright+arr[i][j];
      }
   }
  cout<<endl<<endl;
  for( i=0;i<2;i++)
   {
     for(int j=0;j<2;j++)
      {
       cout<<arr[i][j]<<" ";
       }
       cout<<endl;
      }
   cout<<endl<<endl;
   cout<<"sum of left Diagonal is: "<<sleft<<endl;
   cout<<"sum of right Diagonal is: "<<sright<<endl;
   getch();
   }
