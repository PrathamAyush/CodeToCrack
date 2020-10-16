                                       /*    *************************************************************************************************
                                              *************************Simple Student Manegment system virsion 1.0***************************
                                               **************************************Made By BoltDevil**************************************
                                                *******************************Feel Free To Modify If You Want*****************************     */
#include<iostream>
#include<conio.h>
class student
 {
   private:
	  int roll;
	  char name[20];
	  float marks;
   public:
	 void input();
	 void display();
 };
 void student::input()
  {
    cout<<"Enter the student Roll number"<<endl;
    cin>>roll;
    cout<<"Enter the student name:"<<endl;
    cin>>name;
    cout<<"Enter marks of student:"<<endl;
    cin>>marks;
  }
 void student::display()
  {
    

cout<<"_______________________________________"<

<endl;
    cout<<name<<"\tDetails"<<endl;
    

cout<<"_______________________________________"<

<endl;
    cout<<"\nRoll No. Is:- "<<roll;
    cout<<"\nName Is:- "<<name;
    cout<<"\nMarks is:- "<<marks;
    

cout<<"\n_______________________________________"

<<endl;
  }
void main()
 {
   clrscr();  //clrscr() function not work in IDEs so you can remove it.
  int i,n;
   student s[10]; //Objejt created for 10 student if you want extend it.
  //int i,n;
   cout<<"Enter The Number of student"<<endl;
   cin>>n;
   for(i=0;i<n;i++)
   s[i].input();
   for(i=0;i<n;i++)
   s[i].display();
   getch();
 }
