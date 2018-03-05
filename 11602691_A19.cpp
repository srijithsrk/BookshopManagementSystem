#include<iostream>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "s.h"
using namespace std;      
class Book
{
	int quantities;
	float price;
	char name[20];
	char author[20]; 
	char date[20];
	char description[20];
	char onrent[20];
	public:
				void AddDetails()
				{
				cout<<"enter name of book";
			    cin>>name;
				cout<<"no of quantities available";
				cin>>quantities;
				cout<<"enter name of author";
				cin>>author;
				cout<<"enter price";
				cin>>price;
				cout<<"enter the date of purchase";
				cin>>date;
				cout<<"Enter description of book";
				cin>>description;
				}
				
				void showData(){
					cout<<"no of quantities:"<<quantities<<endl;
					cout<<"price of book is:"<<price<<endl;
					cout<<"name of the book :"<<name<<endl;
					cout<<"name of author :"<<author<<endl;
					cout<<"date of issue :"<<date<<endl;
					cout<<"description of book:"<<description<<endl;
				}
				char* getName(){
					return name;
				}
				int getQuantity(){
					return quantities;
				}
};
//Adding records
void AddRecords(){
	fstream file;
	file.open("book12.dat",ios::binary|ios::app|ios::out);
	file.seekg(0); 
	DelayWelcome();
	char ch;
	Book book;
	do{
		cout<<"ENTER BOOK DATA"<<endl;
		book.AddDetails();
		file.write(reinterpret_cast<char*>(&book), sizeof(book));
		cout<<"Enter another book  record (y/n)?";
		cin>>ch;
	}while(ch=='y');
	file.close();
}

//Seeing All Records
void SeeRecords(){
	fstream file;
	Book book; 
	file.open("book12.dat",ios::binary|ios::in);
	file.read( reinterpret_cast<char*>(&book), sizeof(book));
	while( !file.eof() ){
      book.showData();           
      file.read( reinterpret_cast<char*>(&book), sizeof(book)); 
	  cout<<endl; 
      }
   file.close();
}

//Search 
void Search(){
	cout<<"Welcome To The  Search Menu"<<endl;
	fstream file;
	Book book; 
	file.open("book12.dat",ios::binary|ios::in);
	file.read( reinterpret_cast<char*>(&book), sizeof(book));
	char str[30];
	 cin>>str;
	while( !file.eof() ){
      if(strcmp(str,book.getName())==0){
      	book.showData();
	  }          
      file.read( reinterpret_cast<char*>(&book), sizeof(book)); 
      }
}

void Rent(){
system("cls");
cout<<"Issue book for rent"<<endl;
SeeRecords();
int res;
char book_name[20];
cout<<"Enter book name to rent"<<endl;
cin>>book_name;
fstream file;
Book book; 
	file.open("book12.dat",ios::binary|ios::in);
	file.read( reinterpret_cast<char*>(&book), sizeof(book));
	while( !file.eof() ){
      if(strcmp(book_name,book.getName())==0){
      	if(book.getQuantity()==0)cout<<"out of stock";
      	else {
      		book.showData();
      		 cout<<"Want To Rent This Book"<<endl;
            cin>>res;
            if(res==1)cout<<"Book have been rented";
           else Rent();
		  }
	  }          
      file.read( reinterpret_cast<char*>(&book), sizeof(book)); 
      }
}
int main(){
	AddRecords();
	SeeRecords();
	Rent();
}

