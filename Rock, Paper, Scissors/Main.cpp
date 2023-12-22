#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Get the computer move
char getComputerMove()
{
    int move;
    // Generating a random number between 0 - 2
    srand(time(NULL));
    move = rand() % 3;

    // Returning move based on the random number generated
    if (move == 0)
    {
        return 'p';
    }
    else if (move == 1)
    {
        return 's';
    }
    return 'r';
}

// Function to return the result of the game
int getResults(char playerMove, char computerMove)
{
    // Condition for draw
    if (playerMove == computerMove)
    {
        return 0;
    }

    // Condition for win and loss according to game rule
    if ((playerMove == 's' && computerMove == 'p') ||
        (playerMove == 'p' && computerMove == 'r') ||
        (playerMove == 'r' && computerMove == 's'))
    {
        return 1;
    }
    return -1;
}

// Get a random exclamation
string getRandomExclamation()
{
    vector<string> exclamations = { "Oh!", "Darn!", "Shoot!", "Ah!", "F***!" };
    int index = rand() % exclamations.size();
    return exclamations[index];
}

// Driver code
int main()
{
    string playerName;
    int playerScore = 0, computerScore = 0;

    cout << "\n\n\n\t\t\tWelcome to Rock Paper Scissors\n";
    cout << "\n\t\tEnter your name: ";
    getline(cin, playerName);

    int numRounds;
    cout << "\n\t\tEnter the number of rounds you want to play: ";
    cin >> numRounds;

    for (int round = 1; round <= numRounds; ++round)
    {
        cout << "\n\t\tRound " << round << ":\n";
        cout << "\n\t\tEnter r for ROCK, p for PAPER, and s for SCISSOR\n\t\t\t\t\t";

        // Input from the user
        char playerMove;
        while (true)
        {
            cin >> playerMove;
            if (playerMove == 'p' || playerMove == 'r' || playerMove == 's')
            {
                break;
            }
            else
            {
                cout << "\t\t\tInvalid Player Move!!! Please Try Again." << endl;
            }
        }

        // Computer move
        char computerMove = getComputerMove();

        int result = getResults(playerMove, computerMove);

        // Get a random exclamation
        string exclamation = getRandomExclamation();

        // Printing result based on who won the round
        if (result == 0)
        {
            cout << "\n\t\t\tRound Draw!\n";
        }
        else if (result == 1)
        {
            cout << "\n\t\t\tCongratulations, " << playerName << "! You won this round!\n";
            playerScore++;
        }
        else
        {
            cout << "\n\t\t\t" << exclamation << " Computer won this round!\n";
            computerScore++;
        }

        // Showing both moves
        cout << "\t\t\tYour Move: " << playerMove << endl;
        cout << "\t\t\tComputer's Move: " << computerMove << endl;
    }

    // Show the final scores
    cout << "\n\t\t\tGame Over!\n";
    cout << "\n\t\t\tFinal Scores:\n";
    cout << "\t\t\t" << playerName << ": " << playerScore << " rounds\n";
    cout << "\t\t\tComputer: " << computerScore << " rounds\n";

    if (playerScore > computerScore)
    {
        cout << "\n\t\t\tCongratulations, " << playerName << "! You won the game!\n";
    }
    else if (playerScore < computerScore)
    {
        cout << "\n\t\t\tComputer won the game!\n";
    }
    else
    {
        cout << "\n\t\t\tIt's a tie!\n";
    }

    return 0;
}