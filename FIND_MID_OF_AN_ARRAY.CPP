#include<iostream> //.h for Turbo C++ user 
#include<conio.h>
void main()
{
clrscr();
  int arr[50],n,i;
    cout<<"enter the leanth of an array"<<endl;
      cin>>n;
    cout<<"enter the element of an array:"<<endl;
         for( i=0;i<n;i++)
      cin>>arr[i];
         if(n%2==0)
     cout<<"middle element of an array is :"<<arr[n/2]<<endl;
         else// if(n%2==0)
    cout<<"middle element of an array is :"<<(arr[(n-1)/2]+arr[n/2])/2<<endl;
  getch();
  }
