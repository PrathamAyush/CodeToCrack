#include<iostream>
#include<conio.h>
#include<string.h>
void main()
{            //Password Masking Code '*'
 char pwd[]="password", verify[20], ch;   //current lonin password is "password".You can change with your own choice
 int i, chance=0;
 start:
 clrscr();
 i=0;
  cout<<"*************************PLEASE VERIFY YOUR AUTHENTICATION**********************\n";
 cout<<"Enter Your Password: ";
 do
 {
  ch=getch();
  if(ch!=13)
  {
   verify[i++]=ch;
   cout<<"*";
  }
  else
  {
   verify[i++]='\0';
  }
 }
 while(ch!=13);

 if(strcmp(pwd,verify)==0)
 {
  cout<<"\nYou Are Successfully login.";
  cout<<"\nWelcome Mr.BoltDevil"<<"\n"<<"\n";    //Change name to your own
 }
 else
 {
  cout<<"\nOops!Incorect password\n";
  cout<<chance<<" 3 chances Left";
  cout<<"\nEnter the correct passcode";
  chance++;
  getch();
  if(chance<=3) goto start;
 return;
 }
 // class Product;
 {
 cout<<"~~~~~~~~~~~~~WELCOME TO PACIFIC MALL~~~~~~~~~~~~~"<<endl<<endl;
 cout<<endl<<"      Enter your choise    "<<endl;
 cout<<"............................."<<endl<<endl;
 cout<<"1.MENS'S FASHION"<<endl;
 cout<<"2.LEDISE FASHION"<<endl;
 cout<<"3.KID'S FASHION"<<endl;
 getch();
 }}
           //This program is not compleated yet but password masking is done.full updated program is comming soon.you want to edit programm fell free. 
