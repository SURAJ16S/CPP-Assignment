#include<iostream>
using namespace std;

class person{
    public :
    string name,designation,id;
    int salary,bill;
    void accept();
    virtual void display()=0;
};

class doctor:public person{
public:
void accept(){
    cout<<"Enter Name : ";
    getline(cin,name);
    cout<<"Enter Designation : ";
    cin>>designation;
    cout<<"Enter Your ID : ";
    cin>>id;
    cout<<"Enter Salary : ";
    cin>>salary;
}

void display(){
    cout<<"Designation : "<<designation<<"\nName :"<<name<<"\tId :"<<id<<"\tSalary :"<<salary<<endl;
}
};

class adminstaff:public person{
public:
void accept(){
    cout<<"Enter Name : ";
    getline(cin,name);
    cout<<"Enter Designation : ";
    cin>>designation;
    cout<<"Enter Your ID : ";
    cin>>id;
    cout<<"Enter Salary : ";
    cin>>salary;
}

void display(){
    cout<<"Designation : "<<designation<<"\nName :"<<name<<"\tId :"<<id<<"\tSalary :"<<salary<<endl;
}
};

class patient:public person{
public:
void accept(){
    cout<<"Enter Name : ";
    getline(cin,name);
    cout<<"Enter Your ID : ";
    cin>>id;
    cout<<"Enter Bill : ";
    cin>>bill;
}

void display(){
    cout<<"Designation : "<<designation<<"\nName :"<<name<<"\tId :"<<id<<"\tBill :"<<bill<<endl;
}
};

doctor doc[5];
adminstaff ast[5];
patient pat[5];

int main(){
    doc[0].accept();
    doc[0].display();
    ast[0].accept();
    ast[0].display();
    pat[0].accept();
    pat[0].display();
    return 0;
}