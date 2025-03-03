#include<iostream>
using namespace std;

template<class T>
void selsort(T a[],int size){
    for(int i =0;i<size-1;i++){
        for(int j =i+1;j<size;j++){
            if(a[i]>a[j]){
                T temp = a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    cout<<"Array Sorted Successfully";
    for(int i=0;i<size;i++){
        cout<<a[i]<<endl;
    }
}
int main(){
    int a[10];
    int size ;
    cout<<"Enter Size Of Array : ";
    cin>>size;
    for(int i=0;i<size;i++){
        cout<<"Enter "<<i<<" Value : ";
        cin>>a[i];
    }
    selsort(a,size);
    return 0;
}