/*
>>Binary Search : it is an efficient searching algorithm which works on Divide-and-Conquere principle , which compare the target element with middle position element 
->time Complexity:
best case : O(1)
worst case : O(n log n)
average case : O(n log n)

->array or dataset need to be sorted first 
->efficient for larger datasets
->more efficient and faster than linear search

logic :
int high = n - 1, mid, low = 0;
bool found = false;                //or can use flag

while (low <= high) {
    mid = (low + high) / 2;
    if (s[mid].rno == keys) {
        cout << "Student Attended The Training Session, Present At " << mid << " Position";
        found = true;
        break; // Exit the loop
    }
    else if (s[mid].rno > keys) {
        high = mid - 1;
    }
    else {
        low = mid + 1;
    }
}

if (!found) {
    cout << "Student " << keys << " Does Not Attend The Training Session\n";
}


Problem Statement : Write C++ program to store roll numbers of student in array who attended training program in random order. Write function for 
a) Searching whether particular student attended training program or not using linear search. OR 
b) Searching whether particular student attended training program or not using binary search
*/

#include<iostream>
using namespace std;

class student{
public:
string name;
int rollno;

void accept();
void display();
void linsearch(int n);
void binsearch(int n);

}; 
student stud[100];

void student::accept(){
    cin.ignore();
    cout<<"Enter Your Name : ";
    getline(cin,name);
    cout<<"Enter Roll No : ";
    cin>>rollno;
}

void student::display(){
    cout<<"Name : "<<name<<"\tRoll No : "<<rollno<<endl;
}

void student::linsearch(int n){
    int target,flag=0;
    cout<<"Enter Student Roll To Search : "<<endl;
    cin>>target;

    for(int i=0;i<n;i++){
        if(stud[i].rollno == target){
            flag=1;
            cout<<"Student Name : "<<stud[i].name<<" And Roll No : "<<stud[i].rollno<<" Attended The Program"<<endl;       
        break;
        }
    }
if(flag!=1){
    cout<<"Student Not Attended the program : ";
}
}

void student::binsearch(int n){
    int target;
    cout<<"Enter Student To Search : ";
    cin>>target;
//selection sort algorithm
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(stud[i].rollno > stud[j].rollno){
                student temp=stud[i];
                stud[i]=stud[j];
                stud[j]=temp;
            }
        }
    }
cout<<"Student List Sorted Successfully"<<endl;
int flag=0;
int high=n-1 , mid,low =0;
while(low<=high){
    mid =(high+low)/2;

    if(stud[mid].rollno == target){
        flag =1;
        cout<<"Student Name : "<<stud[mid].name<<" And Roll No : "<<stud[mid].rollno<<" Attended The Program"<<endl;
        break;
    }
    else if(stud[mid].rollno > target){
        high = mid-1;
    }
    else{
        low=mid+1;
    }
}
if(flag!=1){
    cout<<"Student not attended the program"<<endl;
}
}

int main(){
    int choice,index=0;

    do{
        cout<<"Student Attendance System\n1.Accept \n2.Display\n3.Search Student (linear search)\n4.Search Student (binary search)"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;

        switch(choice){
            case 1: 
            //normal call for accept
            stud[index].accept();
            index++;
            break;
            case 2: 
            cout<<"Student Attended the Program"<<endl;
            for(int i =0;i<index;i++){           //checking before and then only calling the display function for the record that is present 
                if(stud[i].name!=""){
                    stud[i].display();
                }
            }
            break;
            case 3:
            stud[0].linsearch(index);          //can call using any object
            break;
            case 4: 
            stud[0].binsearch(index);
            break;
            case 5: 
            cout<<"Exiting Program..."<<endl;
            break;

            default : cout<<"Enter A Valid Choice"<<endl;
        }

    }while(choice!=5);

    return 0;
}