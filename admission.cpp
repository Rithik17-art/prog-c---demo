#include <iostream>
#include <string>
using namespace std;
int marks;
string cource;
int main()
{
    cout << "enter the cource name: ";
    cin >> cource;

    cout << "enter the marks: ";
    cin >> marks;
    if (cource == "engineering")
    {
        if (marks >=90)
        {
            cout << "you are admitted to engineering cource";
        }    
        else cout << "marks not sufficient for admission";
    }    
    else if (cource == "b.com")
    {
        if (marks >=70)
        {
            cout << "you are admitted to b.com cource";
        }  
        else
        {
            cout << "marks not sufficient for admission";
        }
    }
    else 
    {
        cout << "invalid cource name";
    } 
    return 0;

}