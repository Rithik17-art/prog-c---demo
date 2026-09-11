#include <iostream>
#include <cstdlib>
using namespace std;
int playerscore=0;
int computerscore=0;
int gottoss;
int chosen;
int choice;
int userinput;
int computeroutput;
int comptoss;
int toss()
{
    return rand()%2+1;
}
void userbatting(int& userinput, int& computeroutput)
{
    cout << "enter a number between 0 and 6;" << endl;
    if (userinput < 0 || userinput > 6)
    {
        cout << "invalid input" << endl;
        cout << "enter a number between 0 and 6;" << endl;
    }
    cin >> userinput;
    computeroutput=rand()%6+1;
}
void userbowling(int&userinput, int& computeroutput)
{
    cout << "enter a number between 0 to 6 to bowl" << endl;
    cin >> userinput;
    if (userinput < 0 || userinput > 6)
    {
        cout << "invalid input" << endl;
        cout << "enter a number between 0 to 6 to bowl" << endl;
    }
    ;
    computeroutput=rand()%6+1;
    cout << "computer chose: " << computeroutput << endl;
}
void computerbatting(int& userinput , int& computeroutput)
{
     cout << "enter a number between 0 to 6 to bowl" << endl;
    cin >> userinput;
    if (userinput < 0 || userinput > 6)
    {
        cout << "invalid input" << endl;
        cout << "enter a number between 0 to 6 to bowl" << endl;
    }
    computeroutput=rand()%6+1;
    cout << "computer chose: " << computeroutput << endl;
}
void computerbowling(int& userinput, int& computeroutput)
{
    cout << "enter a number between 0 and 6;" << endl;
    cin >> userinput;
    if (userinput < 0 || userinput > 6)
    {
        cout << "invalid input" << endl;
        cout << "enter a number between 0 and 6;" << endl;
    }
    computeroutput=rand()%6+1;
    cout << "computer chose: " << computeroutput << endl;
}

int main()
{
    
    cout << "Come lets play hand cricket" << endl;
    cout << "Enter your choice for toss (1 for heads and 2 for tails): ";
    cin >> choice; 
    gottoss = toss();
    if (choice==gottoss)
    {
        cout << "You won the toss" << endl;
        cout << "enter 1 to bat or enter 2 to bowl "<< endl;
        cin >> chosen;
        if (chosen == 1)
        {
            cout << "you chose to bat "<< endl;
            userbatting(userinput, computeroutput);
            for (int i=0; ; i++)
            {
                if (userinput==computeroutput)
                {
                    cout << "you are out " << endl;
                    cout <<"your score is " << playerscore << endl;
                    cout << "computer needs " << playerscore+1 << " to win" << endl;
                    cout << "computer is batting" << endl;
                    computerbatting(userinput, computeroutput);
                    for (int m=0; ; m++)
                    {
                        if (userinput == computeroutput)
                        {
                            cout << "computer is out" << endl;
                            cout << "computer score is " << computerscore << endl;
                            if (computerscore > playerscore)
                            {
                                cout << "computer won the match" << endl;
                            }
                            else if (computerscore < playerscore)
                            {
                                cout << "you won the match" << endl;
                            }
                            else
                            {
                                cout << "match is draw" << endl;
                            }
                            break;
                        }
                        else
                        {
                            computerscore = computerscore + computeroutput;
                            computerbatting(userinput, computeroutput);
                        }
                    }
                    break;
                }    
                else
                {
                    playerscore = playerscore + userinput;
                    userbatting(userinput, computeroutput);
                }    
                
            }
        }
        else if (chosen == 2)
        {
            cout << "you chose to bowl" << endl;
            userbowling(userinput, computeroutput);
            for (int j=0; ; j++)
            {
                if (userinput == computeroutput)
                {
                    cout << "computer is out" << endl;
                    cout << "computer score is " << computerscore << endl;
                    userbatting(userinput, computeroutput);
                    for (int n=0; ; n++)
                    {
                        if (userinput == computeroutput)
                        {
                            cout << "you are out" << endl;
                            cout << "your score is " << playerscore << endl;
                            if (playerscore > computerscore)
                            {
                                cout << "you won the match" << endl;
                            }
                            else if (playerscore < computerscore)
                            {
                                cout << "computer won the match" << endl;
                            }
                            else
                            {
                                cout << "match is draw" << endl;
                            }
                            break;
                        }
                        else
                        {
                            playerscore = playerscore + userinput;
                            userbatting(userinput, computeroutput);
                        }
                    } 
                    break;
                }
                else
                {
                    computerscore =computerscore + computeroutput;
                    userbowling(userinput,computeroutput);
                }
            }
        }
        else
        {
            cout << "invalid input" << endl;
        }

    }
    else
    {
        cout << "Computer won the toss" << endl;
        cout << "1.batting 2.bowling" << endl;
        cout << "computer chose " << (comptoss = toss()) << endl; 
        if (comptoss == 1)
        {
            cout << " computer choose to bat" << endl;
            computerbatting(userinput,computeroutput);
            for (int k=0; ; k++)
            {
                if (userinput == computeroutput)
                {
                    cout << "computer is out" << endl;
                    cout << "computer score is " << computerscore << endl;
                    userbatting(userinput, computeroutput);
                    for (int n=0; ; n++)
                    {
                        if (userinput == computeroutput)
                        {
                            cout << "you are out" << endl;
                            cout << "your score is " << playerscore << endl;
                            if (playerscore > computerscore)
                            {
                                cout << "you won the match" << endl;
                            }
                            else if (playerscore < computerscore)
                            {
                                cout << "computer won the match" << endl;
                            }
                            else
                            {
                                cout << "match is draw" << endl;
                            }
                            break;
                        }
                        else
                        {
                            playerscore = playerscore + userinput;
                            userbatting(userinput, computeroutput);
                        }
                    }
                    break;
                }
                else
                {
                    computerscore = computerscore + computeroutput;
                    computerbatting(userinput,computeroutput);
                }
            }
        }
        else if (comptoss == 2)
        {
            cout << "computer choose to bowl" << endl;
            computerbowling(userinput,computeroutput);
            for (int l=0; ; l++)
            {
                if (userinput == computeroutput)
                {
                    cout << "you are out" << endl;
                    cout << "your score is " << playerscore << endl;
                    computerbatting(userinput, computeroutput);
                    for (int p=0; ; p++)
                    {
                        if (userinput == computeroutput)
                        {
                            cout << "computer is out" << endl;
                            cout << "computer score is " << computerscore << endl;
                            if (computerscore > playerscore)
                            {
                                cout << "computer won the match" << endl;
                            }
                            else if (computerscore < playerscore)
                            {
                                cout << "you won the match" << endl;
                            }
                            else
                            {
                                cout << "match is draw" << endl;
                            }
                            break;
                        }
                        else
                        {
                            computerscore = computerscore + computeroutput;
                            computerbatting(userinput, computeroutput);
                        }
                    }
                    break;
                }
                else
                {
                    playerscore = playerscore + userinput;
                    computerbowling(userinput,computeroutput);
                }
            }
        }
        else
        {
            cout << "invalid input" << endl;
        }
    }

    cout << "do you want to play again? (1 for yes and 2 for no)" << endl;
    cin >> choice;
    if (choice == 1)
    {
        cout << "starting again " << endl;
        return main();
    }
    else if (choice == 2)
    {
        cout << "game over" << endl;
    }
    else
    {
        cout << "invalid input" << endl;
    }

    return 0;
}
