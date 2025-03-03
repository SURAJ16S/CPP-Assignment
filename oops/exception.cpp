#include<iostream>
using namespace std;
int main(){



try{
int a =10,b=0;
cout<<a/b;
throw 10;
}

catch(int x){
    cout<<"Enter Valid Value Of B "<<endl;
}

    return 0;
}