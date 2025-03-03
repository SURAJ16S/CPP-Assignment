#include<iostream>
using namespace std;

class cms{
    public:
    string name;
    int charityamount;
    cms *next;
    void accept();
    void display();
    void search(string uname);
    void modify(string uname);
}*start=NULL,*temp=NULL;

void cms::accept(){
    cms *nnode;
    nnode=new cms;
    cout<<"Enter Donator Name : ";
    cin>>nnode->name;
    cout<<"Enter Charity Amount : ";
    cin>>nnode->charityamount;
    nnode->next=NULL;

    if(temp==NULL){
        start=nnode;
        temp=start;
    }
    else{
        while(temp->next!=NULL){
            start = nnode;
            temp=temp->next;
        }
        temp->next=nnode;
    }
}
void cms::display(){
    temp=start;
    if(temp==NULL){
        cout<<"No Donation Till Now"<<endl;
    }
    else{
        while(temp!=NULL){
            cout<<"Name : "<<temp->name<<" Amount Donated : "<<temp->charityamount<<endl;
            temp=temp->next;
        }
    }
}
void cms::search(string uname){
     temp=start;
     int flag;
    if(temp==NULL){
        cout<<"No Donation Till Now"<<endl;
    }
    else{
        while(temp!=NULL){
            if(temp->name == uname){
                flag=1;
                break;
            }
            temp=temp->next;
        }
        if(flag==0){
            cout<<"User Not Found"<<endl;
        }
        else{
            cout<<"User Found"<<endl;
        }
    }
}
void cms::modify(string uname){
     temp=start;
     int flag;
    if(temp==NULL){
        cout<<"No Donation Till Now"<<endl;
    }
    else{
        while(temp!=NULL){
            if(temp->name == uname){
                flag=1;
        cout<<"Enter New Donator Name : ";
    cin>>temp->name;
    cout<<"Enter New Charity Amount : ";
    cin>>temp->charityamount;
                break;
            }
            temp=temp->next;
        }
        if(flag==0){
            cout<<"User Not Found"<<endl;
        }
        else{
            cout<<"User modified"<<endl;
        }
    }
}

cms test;
int main(){
test.accept();
test.display();
test.search("test");
test.modify("suraj");
test.display();
    return 0;
}


/* 
include header
create class 
inside public declare variable;
declare lms type pointer varible named next
declare member function
while exiting class declare to more pointer object variable *start=NULL and *temp=NULL

write definition of accept function
    create a new node of lms type - lms * nnode
    allocate memory dynamically
    accept message and store in nnode->VariableName
    at end nnode->next=NULL

    if(temp==NULL){
    start=nnode;
    temp=start;
    }
    else{
    while(temp->next!=NULL){
    temp-next=nnode;
    }
    }
    }         //end of accept function

    void lms::display(){
    temp = start;
    if(temp==NULL){
    cout<<"No ENtries";
    }
    else{
    while(temp!=NULL){
    cout<<temp->var<<" "<<temp->var2<<endl;
    temp=temp->next;                             //keep in mind
    }
    }
    }
*/