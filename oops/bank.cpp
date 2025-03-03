
#include<iostream>
using namespace std;

class bank{
public:
string name,ifsc;
long int accountno ;
float balance;

bank(){
    ifsc="ABC123mn";
    balance= 200;
}

~bank(){
    cout<<"deleted"<<endl;
}

void accept(){
    cin.ignore();
    cout<<"Enter Your Name :";
    getline(cin,name);
    cout<<"Enter Account Number : ";
    cin>>accountno;
}

void display(){
    cout<<name<<"\t"<<accountno<<"\t"<<ifsc<<"\t"<<balance<<endl;
}

void deposit(){
int amnt;
cout<<"Enter Ammount To Deposit : ";
cin>>amnt;
balance+=amnt;
cout<<amnt<<" rs Deposited Successfully"<<endl;
cout<<"Updated Balance : "<<balance<<endl;
}
void withdraw(){
    int amnt;
    cout<<"Enter ammount to Withdraw : ";
    cin>>amnt;
    if(amnt > balance){
        cout<<"Sorry , You Dont Have Sufficient Balance"<<endl;
    }
    else{
        balance-=amnt;
        cout<<"Ammount "<<amnt<<" Successfully Withdrawned"<<endl;
        cout<<"Updated Balance : "<<balance<<endl;
    }
}

};
bank user[10];

int main(){
    int choice,flag=0,i;
    int userindex = 0;
    do{
        cout<<"Bank System\n1.Accept\n2.Display\n3.Deposit\n4.Withdraw\n5.Modify\n6.delete\n7.Exit Bank\nEnter Your Choice : "<<endl;
        cin>>choice;
flag =0;
        switch(choice){
            
            case 1: 
            user[userindex].accept();
            userindex++;
            break;

            case 2:
            cout<<"Name\tAccount No\tIfsc Code\tBalance"<<endl;
            for(int i=0;i<userindex;i++){
               
                if(user[i].name!=""){
                    user[i].display();
                }
            }
            break;

            case 3:
            flag =0;
            int accno;
            cout<<"Enter Account No Deposit : ";
            cin>>accno;
            for(i=0;i<userindex;i++){
                if(user[i].accountno == accno){
                    flag =1;
                    user[i].deposit();
                }
                }
                if(flag!=1){
                    cout<<"User Not Found"<<endl;
            }
      
            break;

            case 4:
            flag =0;
            cout<<"Enter Account No Withdraw : ";
            cin>>accno;
            for(i=0;i<userindex;i++){
                if(user[i].accountno == accno){
                    flag =1;
                    user[i].withdraw();
                }
                }
            if(flag!=1){
                    cout<<"User Not Found"<<endl;
            }
            break;

            case 5:
            flag =0;
            cout<<"Enter Account No Modify : ";
            cin>>accno;
            for(i=0;i<userindex;i++){
                if(user[i].accountno == accno){
                    flag =1;
                    user[i].accept();
                }
                }
            if(flag!=1){
                cout<<"User Not Found"<<endl;
            }
            break;

          case 6:
          flag =0;
         cout << "Enter Account No to Delete: ";
         cin >> accno;
            for (i = 0; i < userindex; i++) {
                if (user[i].accountno == accno) {
                    flag = 1;
                    user[i].name = "";  // Mark as deleted by clearing the name
                    user[i].accountno = 0;
                    user[i].balance = 0;
                    cout << "Account Deleted Successfully." << endl;
                 break;
        }
    }
    if (flag != 1) {
        cout << "User Not Found" << endl;
    }
    break;

            case 7:
            cout<<"Thanks For Using Our Bank"<<endl;
            break;

            default:
            cout<<"Invalid Choice , Enter A Valid Choice"<<endl;
        }
    }while(choice!=7);
}