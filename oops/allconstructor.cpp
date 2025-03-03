// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class test{
   public:
   int roll;
    //default or non-parameterised constructor
    test(){
        roll=2;
    }
    //parameterised contructor
    test(int x){
        roll=x;
    }
    //copy constructor
    test(test &ss){
        roll = ss.roll*2;
    }
    
    void display(){
        cout<<roll<<endl;
    }
}t[3];

int main() {
    t[0].display();

    t[1]=test(3);
    t[1].display();

    t[2]=test(t[1]);
    t[2].display();


    return 0;
}