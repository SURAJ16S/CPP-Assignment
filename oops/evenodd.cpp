#include<iostream>
using namespace std;

int main(){
    int x;

    try {
        cout << "Enter Number: ";
        cin >> x;

        if (x == 0) { // Example to throw a char
            throw 'c';
        }
        throw x;
    }

    catch (int x) {
        if (x % 2 == 0) {
            cout << "Even" << endl;
        }
        else {
            cout << "Odd" << endl;
        }
    }

    catch (char c) {
        cout << "Character" << endl;
    }

    return 0;
}
