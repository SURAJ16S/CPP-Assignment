#include<iostream>
using namespace std;

class shop{
public:
int id;
float spendcost;
int date;
int month;
int year;
string note;

void accept(){
cout<<"Enter Purchase ID : ";
cin>>id;
cout<<"Enter Date :";
cin>>date;
cout<<"Enter Month :";
cin>>month;
cout<<"Enter Year :";
cin>>year;

cout<<"Enter Purchase Amount :";
cin>>spendcost;
cin.ignore();
cout<<"Enter A Note : ";
getline(cin,note);
cout<<"\nPurchase Accepted Successfully"<<endl;
}

void display(){
    cout<<id<<"\t"<<date<<" "<<month<<" "<<year<<"\t"<<spendcost<<"\t"<<note<<endl;
}

void modify(int searchid,int fg){
    if(id == searchid){
        fg=1;
        cout<<"Purchase Found"<<endl;
        cout<<"Enter New Purchase Cost : ";
        cin>>spendcost;
        cout<<"Amount Updated Successfully"<<endl;
    }
    if(fg!=1){
        cout<<"Purchase Not Found"<<endl;
    }
}
void remove(int searchid,int fg){
  if(id == searchid){
        fg=1;
        cout<<"Purchase Found"<<endl;
        cout<<"Removing Amount"<<endl;
        id=0;
        spendcost=0;
        date=0;
        month=0;
        year=0;
        note="";
        cout<<"Purchase Removed Successfully"<<endl;
    }
    if(fg!=1){
        cout<<"Purchase Not Found"<<endl;
    }
}
void sorting(int ui , shop purchase[]){
    for(int i=0;i<ui;i++){
        for(int j=i;j<ui;j++){
            if(purchase[i].spendcost > purchase[j].spendcost){
                shop temp;
                temp = purchase[i];
                purchase[i] = purchase[j];
                purchase[j] = temp;
                cout<<"Sorted Successfully"<<endl;
            }
        }
    }
}

};

shop purchase[100];

int main(){
int userindex=0;
int i=0;
int flag=0;
int searchid,modifycost,choice;

do{
cout<<"Shop Management System"<<endl;
cout<<"1)Accept Purchase Details\n2)Display All Purchase\n3)Search Purchase\n4)Modify Purchase\n5Delete Purchase\n6)Sort\n7)Exit System"<<endl;
cout<<"Enter Your Choice : ";
cin>>choice;

switch(choice){

case 1:
if(userindex!=0){
purchase[userindex].accept();
userindex++;
}
else{
    if(userindex==100){
for(i=0;i<100;i++){
    if(purchase[i].id == 0){
        purchase[i].accept();
        break;
    }
}
    }
    else{
        cout<<"Storage Full"<<endl;
    }
}

break;

case 2:
if(userindex!=0){
cout<<"ID\tD-M-Y\t\tAmount\tNote"<<endl;
for(i=0;i<userindex;i++){
    if(purchase[i].id == 0){
        continue;
    }
    else{
        purchase[i].display();
    }
}
}
else{
    cout<<"No Purchase Details Available"<<endl;
}
break;
case 3:
cout<<"Enter Purchase Id To Search : ";
cin>>searchid;
for(i=0;i<userindex;i++){
    if(purchase[i].id == searchid){
        flag =1;
        cout<<"Purchase Found"<<endl;
        purchase[i].display();
        break;
    }
}

if(flag==0){
    cout<<"Purchase Not Found"<<endl;
}

break;

case 4:
cout<<"Enter Purchase ID To Modify : ";
cin>>searchid;
for(i=0;i<userindex;i++){
    purchase[i].modify(searchid,flag=0);
}

break;
case 5:
cout<<"Enter Purchase ID To Remove : ";
cin>>searchid;
for(i=0;i<userindex;i++){
    purchase[i].remove(searchid,flag=0);
}

break;

case 6:
cout<<"Record Is Sorting "<<endl;
purchase[0].sorting(userindex , purchase);  
break;

case 7:
cout<<"Thanks For Using . \nExiting System..."<<endl;
break;

default: cout<<"Enter Valid Choice"<<endl;

}


}while(choice!=7);


return 0;    
}