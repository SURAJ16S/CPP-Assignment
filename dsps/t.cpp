#include <iostream>
#include <fstream>
#include <sstream> // For string stream
using namespace std;

/*
This top be added - check id for duplicate and ask again for the newer id , it should store each entry in the varible monthname-year for example if i want to display 4rht month and years 2024s result thenit shuold print April-2024 : 92372 rs total like this . it should store all the result .in file also create the object dynamically so that we dont need to manually increase the number of objects .optimise the porgram for better speed wihtout changing not a single logic fromthe code and functionality ,
apply better sorting methods and searching methods for faastst outpyut . also suggest me better data srtucture for this project 
*/

class shop {
public:
    int id;
    float spendcost;
    int date;
    int month;
    int year;
    string note;

    void accept(shop purchase[]) {
        int flag =0;
        int tmpid;
        while(flag!=1){

        cout << "Enter Purchase ID : ";
        cin >> id;

        for(int i=0;i<100;i++){
            if(purchase[i].id == id ){
                cin.ignore();
                cout<<"ID Present , Enter Another ID"<<endl;
                cout<<"Enter Purchase ID : ";
                cin>>tmpid;
                id == tmpid;
                flag ==1;   
                break;
            }
        }

        if(flag!=1){
            cout<<"ID Is Valid , Proceed Further"<<endl;
            id=tmpid;
        }
        }
        cin.ignore();
        cout << "Enter Date :";
        cin >> date;
        cout << "Enter Month :";
        cin >> month;
        cout << "Enter Year :";
        cin >> year;

        cout << "Enter Purchase Amount :";
        cin >> spendcost;
        cin.ignore();
        cout << "Enter A Note : ";
        getline(cin, note);
        cout << "\nPurchase Accepted Successfully" << endl;
    }

    void display() {
        cout << id << "\t" << date << "-" << month << "-" << year << "\t" << spendcost << "\t" << note << endl;
    }

    void modify(int searchid, int& flag) {
        if (id == searchid) {
            flag = 1;
            cout << "Purchase Found" << endl;
            cout << "Enter New Purchase Cost : ";
            cin >> spendcost;
            cin.ignore(); // Clear the newline character left in the buffer
            cout << "Enter A Note : ";
            getline(cin, note); // Optionally modify the note as well
            cout << "Amount Updated Successfully" << endl;
        }
    }

    void remove(int searchid, int& flag) {
        if (id == searchid) {
            flag = 1;
            cout << "Purchase Found" << endl;
            cout << "Removing Amount" << endl;
            id = 0;
            spendcost = 0;
            date = 0;
            month = 0;
            year = 0;
            note = "";
            cout << "Purchase Removed Successfully" << endl;
        }
    }
    void sorting(int ui , shop purchase[]){
    for(int i=0;i<ui;i++){
        for(int j=i;j<ui;j++){
            if(purchase[i].spendcost > purchase[j].spendcost){
                shop temp;
                temp = purchase[i];
                purchase[i] = purchase[j];
                purchase[j] = temp;
                cout<<"Sorted Successfully"<<endl;
            }
        }
    }
}
};

// Global array
shop purchase[100];

// Function to write data to CSV
void writeToCSV() {
    ofstream file("purchases.csv", ios::trunc); // Open in truncate mode to overwrite
    if (!file) {
        cout << "Error opening file for writing." << endl;
        return;
    }

    file << "ID,Date,Month,Year,Amount,Note\n"; // Header row
    for (int i = 0; i < 100; i++) {
        if (purchase[i].id != 0) { // Skip empty entries
            file << purchase[i].id << ","
                 << purchase[i].date << ","
                 << purchase[i].month << ","
                 << purchase[i].year << ","
                 << purchase[i].spendcost << ","
                 << purchase[i].note << "\n";
        }
    }

    file.close();
}

// Function to read data from CSV
void readFromCSV() {
    ifstream file("purchases.csv");
    if (!file) {
        cout << "No previous data found. Starting fresh." << endl;
        return;
    }

    string line, token;
    int index = 0;

    // Skip header row
    getline(file, line);

    // Read each line
    while (getline(file, line) && index < 100) {
        stringstream ss(line);

        getline(ss, token, ','); purchase[index].id = stoi(token);
        getline(ss, token, ','); purchase[index].date = stoi(token);
        getline(ss, token, ','); purchase[index].month = stoi(token);
        getline(ss, token, ','); purchase[index].year = stoi(token);
        getline(ss, token, ','); purchase[index].spendcost = stof(token);
        getline(ss, token, ','); purchase[index].note = token;

        index++;
    }

    file.close();
    cout << "Previous data loaded successfully from purchases.csv.\n";
}

int main() {
    int userindex = 0;
    int i = 0;
    int flag = 0;
    int searchid, choice;

    // Load data from CSV at program start
    readFromCSV();

    // Update userindex to reflect the number of loaded entries
    for (int i = 0; i < 100; i++) {
        if (purchase[i].id != 0) {
            userindex++;
        }
    }

    do {
        cout << "Shop Management System" << endl;
        cout << "1) Accept Purchase Details\n2) Display All Purchase\n3) Search Purchase\n4) Modify Purchase\n5) Delete Purchase\n6)Sorting\n 7)Exit System" << endl;
        cout << "Enter Your Choice : ";
        cin >> choice;
        cin.ignore(); // Clear the newline character left in the buffer

        switch (choice) {
        case 1: // Accept new purchase
            if (userindex < 100) {
                for (i = 0; i < 100; i++) {
                    if (purchase[i].id == 0) { // Find empty slot
                        purchase[i].accept(purchase);
                        userindex++;
                        writeToCSV(); // Update CSV after adding
                        break;
                    }
                }
            } else {
                cout << "Storage Full" << endl;
            }
            break;

        case 2: // Display purchases
            cout << "ID\tD-M-Y\t\tAmount\tNote" << endl;
            for (i = 0; i < userindex; i++) {
                if (purchase[i].id != 0) {
                    purchase[i].display();
                }
            }
            break;

        case 3: // Search purchase
            cout << "Enter Purchase Id To Search : ";
            cin >> searchid;
            flag = 0;
            for (i = 0; i < 100; i++) {
                if (purchase[i].id == searchid) {
                    flag = 1;
                    cout << "Purchase Found" << endl;
                    purchase[i].display();
                    break;
                }
            }
            if (flag == 0) {
                cout << "Purchase Not Found" << endl;
            }
            break;

        case 4: // Modify purchase
            cout << "Enter Purchase ID To Modify : ";
            cin >> searchid;
            flag = 0;
            for (i = 0; i < 100; i++) {
                purchase[i].modify(searchid, flag);
                if (flag == 1) break;
            }
            writeToCSV(); // Update CSV after modifying
            if (flag == 0) {
                cout << "Purchase Not Found" << endl;
            }
            break;

        case 5: // Remove purchase
            cout << "Enter Purchase ID To Remove : ";
            cin >> searchid;
            flag = 0;
            for (i = 0; i < 100; i++) {
                purchase[i].remove(searchid, flag);
                if (flag == 1) break;
            }
            writeToCSV(); // Update CSV after removing
            if (flag == 0) {
                cout << "Purchase Not Found" << endl;
            }
            break;

        case 6:
            cout<<"Record Is Sorting "<<endl;
            purchase[0].sorting(userindex , purchase);  
            writeToCSV(); // Update CSV after sorting
            break;


        case 7: // Exit
            cout << "Thanks For Using. Exiting System..." << endl;
            break;

        default:
            cout << "Enter Valid Choice" << endl;
        }
    } while (choice != 7);

    return 0;
}
