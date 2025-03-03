#include<iostream>
using namespace std ;

template <class t , class x>
void add(t a , x b){
    cout<<"Addition is : "<<a+b<<endl ;
}



int main(){

    add(10,20) ;
    add(12.5,45) ;
    return 0 ;
}