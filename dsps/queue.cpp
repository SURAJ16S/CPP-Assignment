/*
Queue : it is a linear data structure which stores the data sequentially and follows the FIFO Principle
means first element added will be removed first 
>problem of memory wastage as it size shrinks 
>can be used where there are limit seats are there ,and after accepting , it should not accept the new entries, but can delete the older entries till it reaches zero and after that it will again take new entries  

operations
enqueue , dequeue , isfull , isempty , peek ,

front = from here element is removed 
rear = from here element enters 

>:< Queue Rules 

ENQUEUE : 
>initialize both front and rear to -1 
    queue is full : rear == size -1
    first element : if rear == front == -1 , set both front and rear to 0 , then insert the element at queue[rear]
    normal insert : otherwise , increament rear and insert the element at queue[rear]

QEQUEUE : 
    queue is empty : rear == front  == -1
    single element : if rear == front , dequeue the element and reset rear and front to -1
    normal remove : otherwise increment front and remove the element at queue[front]

PEAK ELEMENT : Queue[front]
DISPLAY ALL ELEMENTS : Front To Rear Iterate and print  
*/

#include<iostream>
using namespace std;
int queue[5];
int n =5,i;
int front =-1,rear=-1;

void enqueue(int x){
    if(rear == n-1){
        cout<<"Queue Is fuLL";
        return;
    }   
    else if(front ==-1 && rear==-1){
        rear =0;
        front =0;
        queue[rear]=x;
    }
    else{
        rear++;
        queue[rear]=x;
    }
}

void dequeue(){
    if(front ==-1 && rear ==-1){
        cout<<"Queue is Empty";
    }   
    else if(rear == front){    //if only one element present 
        rear =-1; 
        front =-1; 
    }
 
    else{
        cout<<"Element deleted Successfully : "<<queue[front];
        front++;
     }
}

void peek(){
    cout<<"Peek Element : "<<queue[front]<<endl;
}

void display(){
    if(front== -1 && rear==-1){
        cout<<"Queue Is empty";
    }
    else{
    for(int i=front;i<=rear;i++){
        cout<<queue[i]<<endl;
    }
    }
}

int main(){
int choice,element;
do{
cout<<"1.enter\n2.delete\n3.display peek\n4.display all\n5exit\nenter choice : ";
cin>>choice;
    switch(choice){
case 1: 
cout<<"enter element :";
cin>>element;
enqueue(element);
break;
case 2: 
dequeue();
break;
case 3: 
peek();
break;
case 4: 
display();
break;
case 5:cout<<"exiting"<<endl; 
break;
default:cout<<"Enter A valid choice";
    }
}while(choice!=5);

    return 0;
}