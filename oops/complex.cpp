#include<iostream>
using namespace std;

class complex{
public:
int real,img;

complex(){
    real = 0;
    img = 0;
}

complex(int x,int y){
    real =x;
    img=y;
}

void display(){
    if(img>=0){
        cout<<real<<"+"<<img<<"i"<<endl;
    }
    else{
        cout<<real<<" "<<img<<"i"<<endl;
    }
}

complex operator+(complex c2);
friend complex operator-(complex c2);
complex operator*(complex c2);
complex operator/(complex c2);

}c1,c2,c3;

complex complex::operator+(complex c2){
    c3.real = c1.real + c2.real;
    c3.img = c1.img + c2.img;
    return c3;
}

complex operator-(complex c1,complex c2){
    c3.real = c1.real - c2.real;
    c3.img = c1.img - c2.img;
    return c3;
}

complex complex::operator*(complex c2){
    c3.real = c1.real * c2.real - c1.img * c2.img;
    c3.img = c1.real * c2.img + c1.real * c2.img;
    return c3;
}

complex complex::operator/(complex c2){
    c3.real = (c1.real * c2.real + c1.img * c2.img)/(c2.real * c2.real + c2.img * c2.img);
    c3.img =  (c1.img * c2.real - c1.real * c2.img)/(c2.real * c2.real + c2.img * c2.img);
    return c3;
}

int main(){
    int realn,imgn;
    int choice;
    do{
        cout<<"Complex Number Calculator\n1.Accept\n2.Display\3.Exit\nEnter Your Choice : ";
        cin>>choice;
        
        switch(choice){
            case 1:
            cout<<"Enter Real Number For First Number : ";
            cin>>realn;
            cout<<"Enter Imaginary Number For First Number : ";
            cin>>imgn;
            c1=complex(realn,imgn); 
            cout<<"Enter Real Number For Second Number : ";
            cin>>realn;
            cout<<"Enter Imaginary Number For second Number : ";
            cin>>imgn;
            c2=complex(realn,imgn); 
            break;

            case 2: 
            c1+c2;
            c3.display();
            c1-c2;
            c3.display();
            c1*c2;
            c3.display();
            c1/c2;
            c3.display();
            break;

            case 3: 
            cout<<"Exiting..."<<endl;break;
            default: 
            cout<<"Enter A Valid Choice"<<endl;
        }
    }while(choice!=3);

    return 0;
}