#include<iostream>
using namespace std;

class test{
    public:
    string name;
    test *next , *prev;
    void accept();
    void display();
}*start=NULL,*tail=NULL,*temp=NULL;

void test::accept(){
    test *nnode;
    nnode= new test;
    cout<<"ENter String : ";
    cin>>nnode->name;
    nnode->next=NULL;
    nnode->prev=NULL;

    if(temp==NULL){
    start =nnode;
    tail=nnode;

    }
    else{
        temp=start;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=nnode;
        nnode->prev=temp;
        tail=nnode;
    }
}

void test::display(){
    temp=start;
  if(temp==NULL){
    cout<<"Empty";
  }
  else{
    while(temp!=NULL){
        cout<<temp->name;
        temp=temp->next;
    }
  }
}
test t;
int main(){
t.accept();
    return 0;
}