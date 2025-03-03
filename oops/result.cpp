#include<iostream>
using namespace std;

class student{
    public:
    string name , prn;
    void accept(){
        cout<<"Enter Name : ";
        cin>>name;
        cout<<"Enter PRn : ";
        cin>>prn;
    }
    void display(){
        cout<<"Name : "<<name<<"\tPRN : "<<prn<<endl;
    }
};

class academic:virtual public student{
    public: 
    string subject[2];
    int ciamarks[2];
    int esemarks[2];
    int total[2];
     void acadaccept(){
        for(int i =0;i<2;i++){
            cin.ignore();
            cout<<"Enter Subject Name : ";
            cin>>subject[i];
            cout<<"Enter Cia MArks : ";
            cin>>ciamarks[i];
            cout<<"Enter ese MArks : ";
            cin>>esemarks[i];
        total[i]=ciamarks[i]+esemarks[i];
        }
     }
     void displayacad(){
        for(int i =0;i<2;i++){
            cout<<"Subject : "<<subject[i]<<"\nCIA : "<<ciamarks[i]<<"\nESE : "<<esemarks[i]<<"\nTOTAL:"<<total[i]<<endl;
        }
     }
};

class sport:virtual public student{
public:
string sport,grade;
void acceptsport(){
    cout<<"Enter SPort Name : ";
    cin>>sport;
    cout<<"Enter Grade : ";
    cin>>grade;
}
void displaysport(){
    cout<<"SPort : "<<sport<<"\tGrade : "<<grade<<endl;
}
};
class result:public sport,public academic{
    public:
    void acceptres(){
        student::accept();
        academic::acadaccept();
        sport::acceptsport();
    }

    void displayres(){
        student::display();
        academic::displayacad();
        sport::displaysport();
    }
};

result res[10];
int main(){
res[0].acceptres();
res[0].displayres();
    return 0;
}