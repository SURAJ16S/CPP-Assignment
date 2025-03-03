#include<iostream>
using namespace std;

class bookshop{
public:
string title , author,publisher;
int stock;
float price;

bookshop(){
title ="empty";
author="empty";
publisher="empty";
stock = 0;
price =0.0;
}

~bookshop(){
    cout<<"deleted"<<endl;
}

void accept(){
  cin.ignore();
    cout<<"Enter Book Title : ";
    getline(cin,title);
    cout<<"Enter Author : ";
    getline(cin,author);
    cout<<"Enter Publisher Name : ";
    cin>>publisher;
    cout<<"Enter Stock Unit : ";
    cin>>stock;
    cout<<"Enter Book Price : ";
    cin>>price;
}

void display(){
    cout<<"_______________________________________"<<endl;
    cout<<"Title : "<<title<<"\nAuthor : "<<author<<"\nPublisher : "<<publisher<<"\nStock : "<<stock<<"\nPrice : "<<price<<endl;
    cout<<"________________________________________"<<endl;
}

void check(){
    int checkcopy;
    cout<<"Enter Amount To Check : ";
    cin>>checkcopy;
    if(checkcopy == stock){
        cout<<"required copies are available"<<endl;
        cout<<checkcopy <<" Copy Price : "<<checkcopy * price<<" Rs"<<endl;
    }
    else if(checkcopy > stock){
        cout<<"Only "<<stock<<" Copies are available"<<endl;
    }
    else{
        cout<<"Required "<<stock<<" are Available"<<endl;
    }
}

void checkcost(){
    int checkcopy;
    cout<<"Enter Amount To Check : ";
    cin>>checkcopy;
    cout<<"Total Cost : "<<price * checkcopy<<endl;
}

void purchase(){
    int pbook;
    cout<<"Enter Book Quantity To Purchase : ";
    cin>>pbook;
    if(pbook >stock){
        cout<<"Only "<<stock<<" Are Available";
        cout<<stock<<"Book Purchased Successfully of Cost "<<price*stock<<endl;
        stock=0;
    }
    else{
        cout<<pbook<<" Purchased at Rs "<<pbook*price<<" Successfully"<<endl;
        stock-=pbook;
    }
}
};
bookshop book[10];

int main(){
    int choice,flag=0,i;
    int index = 0;
string ctitle;
    do{
cout<<"Book Management System\n1.Accept Details\n2.Display Details\n3.Check Availability\n4.Check Cost\n5.Purchase Book\n6.Exit Book Shop\nEnter Your Choice : "<<endl;
cin>>choice;

switch(choice){
case 1:
 book[index].accept();
 index++;
 break;
case 2:
for(i=0;i<index;i++){
    if(book[i].title!="empty"){
        book[i].display();
    }
}
break;
case 3:
flag =0;
cout<<"Enter Book Title to Search : ";
cin>>ctitle;
for(i=0;i<index;i++){
    if(book[i].title == ctitle){
        flag =1;
        book[i].check();
    }
}
if(flag!=1){
    cout<<"Book Not Found"<<endl;
}
break;
case 4: 
flag =0;
cout<<"Enter Book Title to Search : ";
cin>>ctitle;
for(i=0;i<index;i++){
    if(book[i].title == ctitle){
        flag =1;
        book[i].checkcost();
    }
}
if(flag!=1){
    cout<<"Book Not Found"<<endl;
}
break;
case 5:

flag =0;
cout<<"Enter Book Title to Purchase : ";
cin>>ctitle;
for(i=0;i<index;i++){
    if(book[i].title == ctitle){
        flag =1;
        book[i].purchase();
    }
}
if(flag!=1){
    cout<<"Book Not Found"<<endl;
}
 break;
case 6:
cout<<"Thanks For Using Our Library"<<endl;
break;
default :
cout<<"Invalid Choice , Enter Valid Choice.";
}
    }while(choice!=6);
    return 0;
}