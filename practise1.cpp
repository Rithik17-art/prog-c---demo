#include <iostream>
using namespace std;

int main()
{
    string name;
    int age;

    cout << "What's your name: ";
    getline(cin, name);

    cout << "What's your age: ";
    cin >> age;

    cout << "Hello, you are " << name << endl;
    cout << "Your age is " << age << endl;

    return 0;
}