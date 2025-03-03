/*
>Linear Search : simplest searching technique, which sequentitally search for the target element in the array
>time complexity :
best case : O(1)
worst case : O(n)
average case : O(n)
>it is better for smaller datasets as it is inefficient for larger datasets
>works on both sorted and unsorted array

problem statement : You are given an integer array 'A' of size 'N', sorted innon
decreasing order.You are als ogiven an integer 'target'.Your task
is to write a function to search for 'target' in the array 'A'. If it
exists,return its index in 0- based indexing using Linear Search.
*/

#include<iostream>
using namespace std;

class Lsearch{
public:
int arr[20],n,i,target;
int flag =0;
void accept(){
    cout<<"Enter Size OF Array : ";
    cin>>n;
    for(i=0;i<n;i++){
        cout<<"Enter Array Element : ";
        cin>>arr[i];
    }
    cout<<"Enter Target Element to Search : ";
    cin>>target;
}

void linearsearch(){
    flag=0;
    for(i=0;i<n;i++){
        if(target==arr[i]){
            flag = 1;
            break;
        }
    }
    if(flag){
        cout<<"Element "<<target<<" Present At "<<i<<" Position"<<endl;
    }
    else{
        cout<<"Target Element "<<target<<" Not Found"<<endl;
    }
}

void count(){
    int count=0;
for(int i =0;i<n;i++){
    if(arr[i]==target){
        count++;
    }
}
if(count==0){
    cout<<"does not present"<<endl;
}
else{
cout<<"Target Element Occurs : "<<count<<endl;
}
}
    


void lastoccur(){
    int flag =0;
    for(int i = n-1;i>=0;i--){
        if(target==arr[i]){
            flag=1;
            break;
        }
    }
    if(flag){
        cout<<"last Occurence is at : "<<i<<" Position"<<endl;
    }
    else{
        cout<<"does not present in array";
    }
}

}test;

int main(){
    int choice;
    do{
        cout<<"Linear Search Algorithm\n1.Accept Array\n2.Search Target Element\n3.count\n4.last occurence\n5.Exit\nEnter Your Choice : ";
        cin>>choice;

        switch(choice){
            case 1 : test.accept();
            break;

            case 2 : test.linearsearch();
            break;

            case 3 : test.count();
            break;

            case 4 : test.lastoccur();
            break;

            case 5 : cout<<"Exiting"<<endl;
            break;

            default : cout<<"Enter A Valid Choice"<<endl;
        }
    }while(choice!=5);
    return 0;
}