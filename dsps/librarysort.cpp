/* 
Sorting Methods

>Bubble Sort : Bubble Sort is a simple sorting algorithm that repeatedly compares adjacent elements in an array and swaps them if required. This process continues for n-1 passes until the array is sorted.
-> total passes : n-1  (where n is no. of Element)
-> no of comparisson : n(n-1)/2
-> time complexity
best case :- O(N)
worst case :- O(N^2)
average case :- O(N^2)


    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

>Insertion Sort : Insertion Sort is a simple sorting algorithm in which in the first pass 'n th' element is supposed as it is sorted already 
and next element 'n+1 th' is compared with and swap if necessary
->total passes : n-1
->total comparison : n(n-1)/2
->time complexity :
best case : O(n)
worst case : O(n^2)
average case : O(n^2)

code ->
for (int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = key;
}


>Selection Sort : it is a simple sorting algorithm in which in first pass the 0 th position element compare with 1 st position and swap if 
require this is first comparison , in second comparison 0 th possition element compares with 2 nd one , this last till n -1 and pass 1 complete . at end of first pass smallest number get to itsd original position
->no of passes : n-1
->no of comparison : n(n-1)/2
->time complexity :
best case : O(n^2)
worst case : O(N^2)
average case : O(N^2)
for(int i=0;i<n;i++){
    for(int j =i+1;j<n;j++){
        if(a[i]>a[j]){
            T temp= a[i];
            a[i] = a[j];
            a[j] = temp;
        }


problem statement : College library has N books.Write C++ program to store the
cost of books in array in ascending order. Books are to be
arranged in descending order of their cost.Write function for
A)Copy costs of books those with cost less than 500 in new array
a) Delete the duplicate entries using temporary array
b) Delete duplicate entries without using temporary array
c) Count number of books with cost more than 500

*/
#include<iostream>
using namespace std;

class library{
    public :
    string title;
    int price;

    void accept(){
        cout<<"Enter Book Title : ";
        cin>>title;
        cout<<"Enter Book Price : ";
        cin>>price; 
    }

    void display(){
        cout<<"Title : "<<title<<" Price : "<<price<<endl;
    }

    void ascorder(library book[],int n){
    library temp;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(book[i].price > book[j].price){
                temp = book[i];
                book[i]=book[j];
                book[j]=temp;
            }
        }
    }
    } 

    void descorder(library book[],int n){
    library temp;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(book[i].price < book[j].price){  //only change the sign for reverse swaping 
                temp = book[i];
                book[i]=book[j];
                book[j]=temp;
            }
        }
    }
    }

    void count(library book[],int n){  //declared void as it return count
        int count =0;
        for(int i =0;i<n;i++){
            if(book[i].title!=""){
                count++;
            }
        }
    cout<<"Total Book Present :"<<count<<endl;
    }

    void underfive(library book[],int n){
        for(int i =0;i<n;i++){
            if(book[i].price <= 500){
                book[i].display();
            }
        }
    } 

    void delduplicate(library book[],int n){
       int flag=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(book[i].title == book[j].title){
                    book[j].title="";
                    book[j].price=0;
                    flag=1;
                }
                
            }
        }
        if(flag){
            cout<<"Duplicate Elements Deleted Successfully"<<endl;
        }
        else{
            cout<<"No Duplicate Element"<<endl;
        }
    }
};
library book[100];
int main(){
    int choice ,i;
    int n;
    do{
        cout<<"Libray System\n1.Accept\n2.Display\n3.Sort in Ascending\n4.Sort In Descending\n5.Count\n6.Book Under 500\n7.delete Duplicate\n8.Exit "<<endl;
        cout<<"Enter Your Choice : ";
        cin>>choice;
    
 

    switch(choice){

        case 1:
        cout<<"Enter How Many books To Store : ";      //index logic should be there
        cin>>n;

        for(i=0;i<n;i++){
            book[i].accept();
        }
        break;

        case 2:
        for(i=0;i<n;i++){
            if(book[i].title!=""){
                book[i].display();
            }
        }
        break;

        case 3:
        book[0].ascorder(book,n);
        break;

        case 4:book[0].descorder(book,n);
        break;

        case 5:book[0].count(book,n);
        break;

        case 6:book[0].underfive(book,n);
        break;

        case 7:book[0].delduplicate(book,n);

        case 8:cout<<"Exiting..."<<endl;
        default: 
        cout<<"Enter A Valid Choice"<<endl;

    }    
        
    }while(choice!=8);

    return 0;
}