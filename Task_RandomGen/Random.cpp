#include <iostream>
#include <random> 
using namespace std;

int main()
{
    char playAgain;
    do
    {

        int n, count = 0;

        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distr(1, 100);
        int randomNumber = distr(gen);

        cout << "===========================\n";
        cout << "     🎯 Guess the Number     \n";
        cout << "===========================\n";
        cout << "I'm thinking of a number between 1 and 100... 🤔\n\n";

        while (true)
        {
            cout << "Enter your guess: ";
            cin >> n;
            count++;

            if (n > randomNumber)
            {
                cout << "🔻 Too high! Try again.\n\n";
            }
            else if (n < randomNumber)
            {
                cout << "🔺 Too low! Try again.\n\n";
            }
            else
            {
                cout << "🎉 Congrats!! You guessed it in " << count << " attempts. 🥳\n";
                break;
            }
        }

        cout << "\nDo you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "\nThanks for playing! 👋\n";
    return 0;
}
