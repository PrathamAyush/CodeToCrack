#include<fstream.h>
#include<conio.h>
#include<iomanip.h>
#include<stdio.h>
#include<string.h>

class Product
{
 int pid;
 char pname[20];
 char category[20];
 int qty;
 float rate;
 float amount;
 public:
 int getID(){return pid;}
 void getData();
 void outData();
 void showData();
 void modify();
}p;

void Product::getData()
{
 cout<<"\nEnter the Product Details.......\n";
 cout<<"==================================\n";
 cout<<"Enter the Product ID       : ";
 cin>>pid;
 cout<<"Enter the Product Name     : ";
 cin.ignore();
 cin.getline(pname,20);
 cout<<"Enter the Product Category : ";
 cin.getline(category,20);
 cout<<"Enter the Product Qty      : ";
 cin>>qty;
 cout<<"Enter the Product Rate     : ";
 cin>>rate;
 amount=rate*qty;
}

void header()
{
 cout.setf(ios::left);
 cout<<setw(10)<<"Prod.ID."
     <<setw(20)<<"Prod.Name"
     <<setw(20)<<"Prod.Category"
     <<setw(8)<<"Qty."
     <<setw(8)<<"Rate"
     <<setw(10)<<"Amount"
     <<endl;
 cout<<"========================================================================\n";
}

void Product::showData()
{
 cout.setf(ios::left);
 cout<<setw(10)<<pid
     <<setw(20)<<pname
     <<setw(20)<<category
     <<setw(8)<<qty
     <<setw(8)<<rate
     <<setw(10)<<amount
     <<endl;
}

void Product::outData()
{
 cout.setf(ios::left);
 cout<<"..........Product Details..........\n";
 cout<<"Product ID        : "<<pid<<endl;
 cout<<"Product Name      : "<<pname<<endl;
 cout<<"Product Category  : "<<category<<endl;
 cout<<"Product Qty       : "<<qty<<endl;
 cout<<"Product Rate      : "<<rate<<endl;
 cout<<"Product Amount    : "<<amount<<endl<<endl;
}

void Product::modify()
{
 int Pid, Qty;
 char Pname[20],Category[20];
 float Rate;
 outData();
 cout<<"\nEnter New Details......\n";
 cout<<"New Product ID (press -1 to retain old one)      : ";
 cin>>Pid;
 cout<<"New Product Name (press '.' to retain old one)   : ";
 cin.ignore();
 cin.getline(Pname,20);
 cout<<"New Product Category(press '.' to retain old one): ";
 cin.getline(Category,20);
 cout<<"New Product Qty (press -1 to retain old one)     : ";
 cin>>Qty;
 cout<<"New Product Rate(press -1 to retain old one)     : ";
 cin>>Rate;
 if(strcmp(Pname,".")!=0)     strcpy(pname,Pname);
 if(strcmp(Category,".")!=0)   strcpy(category,Category);
 if(Pid!=-1) pid=Pid;
 if(Qty!=-1) qty=Qty;
 if(Rate!=-1) rate=Rate;
 amount=qty*rate;
}

void AddRecord()
{
 ofstream fout;
 fout.open("products.bin",ios::binary|ios::app);
 p.getData();
 fout.write((char*)&p,sizeof(p));
 fout.close();
 cout<<"\nData Saved to Binary File.....\n";
}

void Display()
{
 ifstream fin;
 fin.open("products.bin",ios::binary);
 header();
 while(fin.read((char*)&p,sizeof(p)))
 {
  p.showData();
 }
 fin.close();
 cout<<"\nFile Reading Completed.....\n";
}

void Search()
{
 ifstream fin;
 int id,flag=0;
 fin.open("products.bin",ios::binary);

 cout<<"Enter the Product ID you want to Search : ";
 cin>>id;
 cout<<endl<<endl;
 while(fin.read((char*)&p,sizeof(p)))
 {
  if(id==p.getID())
  {
   p.outData();
   flag++;
  }
 }
 fin.close();
 if(flag==0)
  cout<<"The Product ID : "<<id<<" is not in the file....\n";
 cout<<"\nFile Reading Completed.....\n";
}

void Modify()
{
 fstream fio;
 int id,flag=0,pos;
 fio.open("products.bin",ios::binary|ios::out|ios::in);

 cout<<"Enter the Product ID you want to Modify : ";
 cin>>id;
 while(fio.read((char*)&p,sizeof(p)))
 {
  pos=fio.tellg();
  if(id==p.getID())
  {
   cout<<"\nThe following Data will be modifed:"<<endl;
   fio.seekg(pos-sizeof(p));
   p.modify();
   fio.write((char*)&p,sizeof(p));
   cout<<"\nThe data modified successfully...\n";
   flag++;
  }
 }
 fio.close();
 if(flag==0)
  cout<<"The Product ID : "<<id<<" is not in the file....\n";
 cout<<"\nFile Reading Completed.....\n";
}

void Delete()
{
 ifstream fin;
 ofstream fout,out;
 int id,flag=0;
 fin.open("products.bin",ios::binary);
 fout.open("tempProd.bin",ios::binary);
 out.open("Protrash.bin",ios::binary|ios::app);
 cout<<"Enter the Product ID you want to Delete : ";
 cin>>id;
 while(fin.read((char*)&p,sizeof(p)))
 {
  if(id==p.getID())
  {
   out.write((char*)&p,sizeof(p));
   cout<<"\n\nThe Following record is moved to trash....\n\n";
   p.outData();
   flag++;
  }
  else
  {
   fout.write((char*)&p,sizeof(p));
  }
 }
 fin.close();
 fout.close();
 out.close();
 if(flag==0)
  cout<<"The Product ID : "<<id<<" is not in the file....\n";
 cout<<"\nFile Reading Completed.....\n";
 remove("products.bin");
 rename("tempProd.bin","products.bin");
}

void viewTrash()
{
 ifstream fin;
 fin.open("protrash.bin",ios::binary);
 header();
 while(fin.read((char*)&p,sizeof(p)))
 {
  p.showData();
 }
 fin.close();
 cout<<"\nFile Reading Completed.....\n";
}

void Restore()
{
 int id,flag=0;
 ifstream fin("protrash.bin",ios::binary);
 ofstream fout("products.bin",ios::binary|ios::app);
 ofstream out("tempstor.bin",ios::binary);
 cout<<"Enter the Product ID you want to Restore : ";
 cin>>id;
 while(fin.read((char*)&p,sizeof(p)))
 {
  if(id==p.getID())
  {
   fout.write((char*)&p,sizeof(p));
   cout<<"\n\nThe Following record is restored to file....\n\n";
   p.outData();
   flag++;
  }
  else
  {
   out.write((char*)&p,sizeof(p));
  }
 }
 fin.close();
 fout.close();
 out.close();
 if(flag==0)
  cout<<"The Product ID : "<<id<<" is not in the Trash file....\n";
 cout<<"\nFile Reading Completed.....\n";
 remove("protrash.bin");
 rename("tempstor.bin","protrash.bin");
}

void menu()
{
 cout<<"==============PRODUCT MENU OPTIONS===========\n\n";
 cout<<"\t0. Exit\n";
 cout<<"\t1. Add Record\n";
 cout<<"\t2. Show Records\n";
 cout<<"\t3. Search Record\n";
 cout<<"\t4. Delete Record\n";
 cout<<"\t5. Modify Record\n";
 cout<<"\t6. Show Deleted Items\n";
 cout<<"\t7. Restore Deleted Items\n";
 cout<<"\tEnter choice   : ";
}

void project()
{
 int ch;
 do
 {       clrscr();
  menu();
  cin>>ch;
  clrscr();
  switch(ch)
  {
   case 1: AddRecord(); break;
   case 2: Display(); break;
   case 3: Search(); break;
   case 4: Delete(); break;
   case 5: Modify(); break;
   case 6: viewTrash(); break;
   case 7: viewTrash(); Restore(); break;
  }
  getch();
 }while(ch);
}

void main()
{
 project();
}
