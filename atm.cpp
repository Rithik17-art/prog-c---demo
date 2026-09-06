#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    int pin = 1678;
    int enteredpin;
    int amount;
    int balance = 10000;
    int option;

    cout << "enter your name: ";
    cin >> name;

    for (int i = 0; i < 3; i++) 
    {
        cout << "enter your pin: ";

        cin >> enteredpin;

        if (enteredpin == pin)
         {
            cout << "hi welcome to the atm" << name << endl;

            do {
                cout << "choose your option" << endl;
                cout << "1. check your balance" << endl;
                cout << "2. withdraw" << endl;
                cout << "3. deposit" << endl;
                cout << "0. exit" << endl;
                cin >> option;

                if (option == 1)
                 {
                    cout << "your balance is " << balance << endl;
                }
                 else if (option == 2) 
                {
                    cout << "enter the amount to withdraw: ";
                    cin >> amount;

                    if (amount > balance) 
                    {
                        cout << "insufficient balance" << endl;
                    } else 
                    {
                        balance = balance - amount;
                        cout << "your balance is " << balance << endl;
                    }
                } 
                 else if (option == 3) 
                {
                    cout << "enter the amount to deposit: ";
                    cin >> amount;
                    balance = balance + amount;
                    cout << "your balance is " << balance << endl;
                } 
                 else if (option == 0)
                 {
                    cout << "thank you" << endl;
                } 
                 else 
                {
                    cout << "invalid option" << endl;
                }
            } while (option != 0);

            return 0;
        } 
        else 
        {
            cout << "wrong pin" << endl;
        }
    }

    cout << "too many wrong attempts" << endl;
    return 0;
}