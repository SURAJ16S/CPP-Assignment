#include<iostream>
using namespace std;
int main(){
    int age ;
    
    try{
        cout<<"Enter age : ";
        cin>>age;
        
        if(age>=18){
            throw 18;
        }
        else{
            throw 0;
        }
    }
    
    catch(int x){
        if(x==18){
            cout<<"Your Are Eligible For Vote "<<endl;
        }
        else{
            cout<<"You Cannot Vote"<<endl;
        }
        
        
    }
    return 0;
}