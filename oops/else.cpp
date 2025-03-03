//swapping using only two variable and using the function template
#include<iostream>
using namespace std;
template<class T>
T swap(T a,T b){
    a=a+b;
    b=a-b;
    a=a-b;
    cout<<"A : "<<a<<"\nB : "<<b<<endl;
}
int main(){
cout<<swap('t','p');
    return 0;
}