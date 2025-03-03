#include<iostream>
using namespace std;

class classroom{
    private:
    string player;
    int health;
    float rating;
    public:
    //default constructor is required if we are using the parameterised constructor 
    classroom(){ 
        player = "Demon";
        health =120;
        rating =9.8;
    }
    classroom(int x){
        player ="five";
        health =x;
        rating =8.5;
    }
    
    ~classroom(){
        cout<<"Destructor is called"<<endl;
    }
    
    void accept(){
        cout<<"Enter character name : ";
        getline(cin,player);
        cout<<"Enter The Player health : ";
        cin>>health;
        cout<<"Enter The Rating of the player : ";
        cin>>rating;
    }
    
    void display(){
        if(player!=""){
            cout<<player<<"\t"<<health<<"\t"<<rating<<endl;
        }
    }
    
};

classroom student[10];

int main(){
   
    int i =0,index=0;
    student[0].accept();
    student[0].display();
    student[1].display();
    student[2].display();
    student[3].display();
    student[4].display();
   student[5]=classroom(5);
   //parameterised constructor
   //object[index]=classname(arguement to pass);
   //classname objectname(arg to pass);
    student[5].display();
    student[6].display();
    student[7].display();
    student[8].display();
    student[9].display();
    
    return 0;
}
