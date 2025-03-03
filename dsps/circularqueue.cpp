/*
circular queue is circular data structure , in which the last position is connected to the first one 
>Help Avoid the Memory wastage


for circular queue rules : 
>initialize rear and front to -1 (queue is empty)

ENQUEUE
>if (rear+1)%size == front ,(queue is full)
>if rear == front == -1 ,then set both to 0 and then insert the element at queue[rear]
>normal insert; otherwise set rear = (rear + 1) % size and insert the element at queue[rear]
DEQUEUE
>empty queue -> rear == -1 && front == -1
>single element: if rear==front , dequeue the element and reset r and f to -1
>normal remove: remove the element at queue[front], then update front = (front + 1) % size

>PEEK : queue[front]
>DISPLAY : front to rear
*/

#include<iostream>
using namespace std;

int queue[5];
int size =5;
int front =-1,rear=-1,i=0;

void enqueue(int x){
    if((rear+1)%size==front){
        cout<<"Circular Queue Is Full"<<endl;
    }
    else if (rear ==-1 && front ==-1){
        rear=0;
        front=0;
        queue[rear]=x;
        cout<<"element entered : "<<x<<endl;
    }
    else{
        rear=(rear+1)%size;
        queue[rear]=x;
        cout<<"Element Entered : "<<x<<endl;
    }
}

void dequeue(){
    if(rear==-1 && front==-1){
        cout<<"Circular Queue is empty"<<endl;
    }
    else if(rear ==front){    //means one element means position is zero
        cout<<"Element Deleted : "<<queue[front]<<endl;
        rear == -1;
        front ==-1;
    }
     else{
        cout<<"Element Deleted : "<<queue[front]<<endl;
        front = (front+ 1)%size;
     }
}

void peek(){
    cout<<"Peek element : "<<queue[front]<<endl;
}

void display(){
    if(rear == -1 && front == -1){
        cout << "Queue is empty" << endl;
    }
    else {
        int i = front;
        cout << "Queue elements: ";
        while (i != rear){
            cout << queue[i] << " ";
            i = (i + 1) % size;
        }
        cout << queue[rear] <<endl;
    }
}


int main(){
int choice;
int x;
do{
    cout<<"1.accept\n2.delete\n3.peak\n4.display all"<<endl;
    cout<<"Enter Choice : ";
    cin>>choice;

    switch(choice){
        case 1: 
        cout<<"enter Element To enter : ";
        cin>>x;
        enqueue(x);
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

        case 5: 
        cout<<"exiting";
        break;

        default: cout<<"enter a valid choice "<<endl;
    }
}while(choice!=6);
    return 0;
}