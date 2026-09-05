#include <iostream>
using namespace std;
int main()
{
    int amount;
    cout << "Enter the amount: ";
    cin >> amount;
    cout << "The tax amount is: " << amount * 0.18 << endl;
    cout << "The total amount is: " << amount + (amount * 0.18) << endl;
    return 0;
}