/*


problem statement : A pizza parlor accepts a maximum of M orders. Orders are served on a first-come, first-served basis. Order once placed 
cannot be canceled. Write a C++ program to simulate the system using a queue with an array.
*/
#include<iostream>
#include<string>
using namespace std;
const int size=10;
const float cost=100.0;                 //declare const cost and size for array
class pizza{
    public:    
    string name[size];
    int quantity[size];
    string mobile[size];                      //declare datafield array with the const size 
    int rear, front;

    pizza(){                    // set value to default -1
        rear=-1;
        front=-1;
    }

bool isfull(){                                      //boolean function to return full or not
   return front== (rear+1)%size;
}

bool isempty(){                                         //boolean function to return empty or not 
    return (front ==-1);
}
    void acceptorder(string uname,int qty , string phone){          //call the function using object and pass value at that time
        if(isfull()){                                                   //call isfull fucntion and display message 
            cout<<"Queue Is Full , Come Back Later"<<endl;
        }
        else if (front ==-1 && rear==-1){                                //if no orders so accept the first order by setting rear and front to '0'
            rear =0; front=0;
            name[rear]=uname;
            quantity[rear]=qty;
            mobile[rear]=phone;
            cout<<"Order Accepted Successfully"<<endl;
        }
        else{                                                       //update rears value and accept the input 
            rear = (rear+1)%size;
            name[rear]=uname;
            quantity[rear]=qty;
            mobile[rear]=phone;
            cout<<"Order Accepted Successfully"<<endl;
        }
    }

    void serveorder(){
        if(isempty()){                                              //call isempty and display message accordingly
            cout<<"No Order to Serve"<<endl;
        }

        else if(rear == front){                 //if only one order , then print served message and put rear and front to -1 
            cout<<"Order Served with Details\nName : "<<name[front]<<"\nQuantity : "<<quantity[front]<<"\nPrice : "<<cost*quantity[front]<<"\nMobile : "<<mobile[front]<<endl;
            rear=-1;
            front=-1;
        }
        else{             //display message and update front value
            cout<<"Order Served with Details\nName : "<<name[front]<<"\nQuantity : "<<quantity[front]<<"\nPrice : "<<cost*quantity[front]<<"\nMobile : "<<mobile[front]<<endl;
            front = (front+1)%size;
        }

/*DISCOUNT PART
 float price = cost * quantity[front]; // Calculate price
            if (front == 0) { // Check if it is the first order
                price *= 0.95; // Apply a 5% discount
                cout << "Congratulations! You are the first customer and get a 5% discount!" << endl;
            }
*/

    }

    void peekorder(){                //peak means front so just print it 
if(isempty()){
    cout<<"No Orders"<<endl;
}
else{
        cout<<"Top Most Order In Priority"<<endl;
        cout<<"Order Served with Details\nName : "<<name[front]<<"\nQuantity : "<<quantity[front]<<"\nPrice : "<<cost*quantity[front]<<"\nMobile : "<<mobile[front]<<endl;
    }
    }

    void display(){                       //same logic as previous
        cout<<"Orders List"<<endl;
        if(isempty()){
            cout<<"No Orders To Display"<<endl;
        }
        else{
            int i=front;
            while(i!=rear){
                cout<<"\nName : "<<name[i]<<"\nQuantity : "<<quantity[i]<<"\nPrice : "<<cost*quantity[i]<<"\nMobile : "<<mobile[i]<<endl;
                i=(i+1)%size;
            }
            cout<<"\nName : "<<name[rear]<<"\nQuantity : "<<quantity[rear]<<"\nPrice : "<<cost*quantity[rear]<<"\nMobile : "<<mobile[rear]<<endl;
        }
    }


};
pizza test;

int main(){
string name;
int qty;
string phone;
int choice;

do{
cout<<"1.Accept Order\n2.Serve Order\n3.display Top Order\n4.Display All Order\n5.Exit Pizza Shop\nEnter Your Choice : ";
cin>>choice;

switch(choice){
    case 1: //accept value into local variable and pass it in the class member function
    cin.ignore();
    cout<<"Enter Name : ";
    getline(cin,name);
    cout<<"Enter Quantity : ";
    cin>>qty;
    cout<<"Enter Mobile Number : ";
    cin>>phone;
    test.acceptorder(name,qty,phone); 
    break;
    case 2: 
    test.serveorder();
    break;
    case 3: 
    test.peekorder();
    break;
    case 4: 
    test.display();
    break;
    case 5: 
    cout<<"Exiting Shop, Thank You..."<<endl;
    break;
    default: cout<<"Enter Valid Choice"<<endl;
}
}while(choice!=5);
    return 0;
}

