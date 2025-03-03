//swaping of two numbers using only two variable
#include <iostream>
using namespace std;
int main() {
   int a ,b;
   cout<<"Enter A Value : ";
   cin>>a;
   cout<<"Enter B Value : ";
   cin>>b;
   
   a=a+b;
   b=a-b;
   a=a-b;
   cout<<"A : "<<a<<" B : "<<b<<endl;  
    return 0;
}