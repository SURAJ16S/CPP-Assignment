#include<iostream>
using namespace std ;

template<class T>
class Demo{
    public :
    T a ;
    T b ;

    void add(T a ,T b){
        cout<<"Addition is : "<<a+b<<endl;
    }
} ;
int main(){
    Demo<int> d ;
    d.add(10,20);
    return 0 ;
}