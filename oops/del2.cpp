#include<iostream>
using namespace std;

template<class t,class T>

class test{
public:

t a;
T b;

void sum(t a ,T b){
    cout<<a+b<<endl;
}

};

class test2:public test<class t,class T>{
    public:
    void sum(class t a ,class T b){
        cout<<"test";
    }
};

int main(){

test<int,float> obj1;
obj1.sum(2,5.1);
test<int,float> obj2;
obj2.sum(2,7.2);
test<char,int> obj3;
obj3.sum('a',1);

test2<int ,char> objtest;
objtest.sum(3,5.);


    return 0;
}