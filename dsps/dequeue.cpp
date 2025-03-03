/*
Double Ended Queue Is A Linear Data Structure that allows insertion and deletion form boths ends - front and rear
>combine properties of both stack and queue ,operations simillar to stack (LIFO AND FIFO)

operations - insert front/rear , delete front/rear , peek front/rear , isfull , inempty ,display all 

>:< RULE >:<
Full DEQUE : (rear + 1)% size = front
Empty Deque : front =-1

insert at front :
    >initially front =-1,then set both rear and front to 0
    >if front is at 0 , wrap around to size -1
    >otherwise ,increment rear by 1
    else , put value

insert at rear :
    >if deque is initially empty(front =-1),set both front and rear to 0
    >if rear is at size -1 ,wrap around to 0
    >otherwise increment rear by 1
    >else put value

delete at front :
    >if deque has only one element front == rear , reset both to -1
    >if front is at size -1 ,wrap around/ reset to 0
    >otherwise increment front by 1

delete fron rear :
    >if deque has only one element rear == front , reset both to -1
    >if rear is at 0 then wrap to size-1
    other wise decrement rear by 1 

*/

#include<iostream>
using namespace std;

const int size =5;
int queue[size];
int rear =-1,front =-1;

bool isfull(){
    return (front==(rear+1)%size);
}
bool isempty(){
    return (front==-1);
}

void insertfront(int x){
if(isfull()){
    cout<<"Overflow";
}
else if(front == -1){
    rear=0;
    front=0;
}
else if(front ==0){
    front = size-1;
}
else{
    front=front-1;
}
queue[front]=x;
cout<<"Element Enter Successfully"<<endl;
}

void insertrear(int x){
    if(isfull()){
         cout<<"Overflow"<<endl;
    }
    else if(rear ==-1){
        rear=0;
    }
    else if(rear==size-1){
        rear=0;
    }
    else{
        rear+=1;
    }
    queue[rear]=x;
    cout<<"Element Enter Successfully"<<endl;
}

void deletefront(){
    if(isempty()){
        cout<<"Underflow";
    }
    else if(rear == front){              
    cout<<"Deleted : "<<queue[front]<<endl;
       
        front=-1;
        rear=-1;
    }
    else if(front=size-1){
    cout<<"Deleted : "<<queue[front]<<endl;
       
        front =0;
    }
    else{
    cout<<"Deleted : "<<queue[front]<<endl;
       
        front = front + 1;
    }

}

void deleterear(){
    if(isempty()){
        cout<<"Underflow"<<endl;
    }
    
    else if(front == rear){
        cout<<"Deleted : "<<queue[rear]<<endl;
        front=-1;
        rear=-1;
    }
    else if(rear==0){
        cout<<"Deleted : "<<queue[rear]<<endl;
        rear=size -1;
    }
    else{
        cout<<"Deleted : "<<queue[rear]<<endl;
        rear=rear-1;
    }
}

void getfront(){
    if(isempty()){
        cout<<"Underflow"<<endl;
    }
    else{
        cout<<"Front Element : "<<queue[front]<<endl;
    }
}

void getrear(){
    if(isempty()){
        cout<<"Underflow"<<endl;
    }
    else{
        cout<<"rear Element : "<<queue[rear]<<endl;
    }
}

void displayall(){
    if(isempty()){
        cout<<"Underflow"<<endl;
    }
    else{
        int i = front;
        while(i!=rear){
            cout<<queue[i]<<endl;
            i=(i+1)%size;
        }
        cout<<queue[rear]<<endl;             //not to forget this 
    }
}

int main(){
int x,choice;
do{
cout<<"1.Accept front\n2.accept rear\n3.delete front\n4.delete rear\n5.getfront\n6.getrear\n7.display all\n8.exit"<<endl;
cout<<"Enter Your Choice : ";
cin>>choice;

switch(choice){
    case 1:
    cout<<"Enter Element : ";
    cin>>x;
    insertfront(x);
    break;

    case 2:
    cout<<"Enter Element : ";
    cin>>x;
    insertrear(x);
    break;

    case 3:
    deletefront();
    break;

    case 4:
    deleterear();
    break; 

    case 5:
    getfront();
    break;

    case 6:
    getrear();
    break;

    case 7:
    cout<<"All Elements"<<endl;
    displayall();
    break;

    case 8 : cout<<"exiting..."<<endl;    
    break;

    default: cout<<"Enter Valid Choice"<<endl;

}

}while(choice!=8);
    return 0;
}

