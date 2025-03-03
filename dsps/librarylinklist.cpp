/*
Link List :linear data structure where the data is stored in the node 
each node consit of two parts address field of next node and data field 
it is unidirectional (can traverse in only one direction)
types - singly , doubly , circular  

problem statement : A library needs to manage a collection of books (data fields such as b
ook title, author, ISBN, availability status, and other relevant information), maintain 
information about each book, support operations like adding, removing, and searching for books, and provide efficient access to library resources. Use the concept of 
Linked List for implementation of the Library Management system.
*/
#include<iostream>
using namespace std;

class lms{                                //declare class and also required variables
    public:
    string title, author ,publisher;  
    int price ,quantity;

    lms *next;      //declare pointer of lms type to point to next

    //declare the member functions
    void accept();
    void display();
    void search(string ss);
    void update(string ss);
    void remove(string ss);

}*start=NULL ,*temp=NULL;        //initialiaze pointer to start and temp node as NULL

void lms::accept(){
    lms * nnode;     //declare a new node 
    nnode = new lms ;    //allocate memory dynamically to nnode
    //accept info and store in nnode->
    cout<<"Enter Book Title : ";
    cin>>nnode->title;
    cout<<"Enter Book author : ";
    cin>>nnode->author;
    cout<<"Enter Book publisher : ";
    cin>>nnode->publisher;
    cout<<"Enter Book price : ";
    cin>>nnode->price;
    cout<<"Enter Book quantity : ";
    cin>>nnode->quantity;
    nnode->next=NULL;       //data is stored and close the node

if(start == NULL){
    start = nnode;          //start pointer to nnode
    temp = start;       //and temp pointer to start node
}
else{
    temp=start;                  //donot forget
    while(temp->next!=NULL){
        temp = temp->next;         //traverses to the end
    }
    temp->next=nnode;
}
}

void lms::display(){
    temp =start;
    if(temp==NULL){
        cout<<"No Books Are Available"<<endl;
    return;  
    }
    else{
        while(temp!=NULL){
            cout<<"Title : "<<temp->title<<"\nAuthor : "<<temp->author<<"\nPublisher : "<<temp->publisher<<"\nQuantity : "<<temp->quantity<<"\nPrice : "<<temp->price<<endl;
            temp=temp->next;
        }
    }
}

void lms::search(string ss){
    temp=start;
    int flag=0;
    while(temp!=NULL){
        if(temp->title == ss){
            flag=1;
            break;
        }
        temp=temp->next;
    }
    if(flag==0){
         cout<<"Book Not Found"<<endl;
    }
    else{
        cout<<"Book Found"<<endl;
    }
}

void lms::update(string ss){
    temp=start;
    int flag=0;
    while(temp!=NULL){
        if(temp->title == ss){
            flag=1;
             
            break;
        }
        temp=temp->next;
    }
    if(flag==0){
         cout<<"Book Not Found"<<endl;
    }
    else{
       cout<<"Book Found"<<endl;
        cin.ignore();
        cout<<"Enter New Title : ";
        temp->title;
        cout<<"Enter New author : ";
        temp->author;
        cout<<"Enter New publisher : ";
        temp->publisher;
        cout<<"Enter New price : ";
        temp->price;
        cout<<"Enter New quantity : ";
        temp->quantity;
    }
}

void lms::remove(string ss) {
    temp = start;
    // Traverse the list to find the node to be marked for deletion
    while (temp != NULL) {
        if (temp->title == ss) {
            // Mark the node for deletion by setting default values
            temp->title = "";
            temp->author = "";
            temp->publisher = "";
            temp->price = 0;
            temp->quantity = 0;
            cout << "Book Marked for Deletion" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Book Not Found" << endl;
}


lms test;
int main(){
    int choice;
    string title;
    test.accept();
    test.display();
    title= "suraj";
    test.search(title);
    test.update(title);
    test.display();
    test.remove(title);
    test.display();
    
    return 0;
}