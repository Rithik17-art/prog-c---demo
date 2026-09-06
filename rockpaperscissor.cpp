#include <iostream>
using namespace std;

int main() 
{
    int playerscore = 0;
    int computerscore = 0;
    int player, computer;

    for (int i = 0; i < 3; i++)
    {
        cout << "enter 1 for rock, 2 for paper and 3 for scissors: ";
        cin >> player;
        computer = rand() % 3 + 1;
        cout << "computer choose " << computer << endl;
        if (player == computer)
        {
            cout << "try again" << endl;
        }
        else if (player == 1 && computer == 3 || player == 2 && computer == 1 || player == 3 && computer == 2)
        {
            cout << "you win" << endl;
            playerscore++;
        }
        else
        {
            cout << "computer wins" << endl;
            computerscore++;
        }


    }
    

    
}