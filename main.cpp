#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

void generateNumber(string& secret)
{
    srand(time(NULL));
    secret = "";
    while (secret.length() < 4)
    {
        char digit = '0' + rand() % 10;
        if (secret.find(digit) == string::npos)
        {
            secret += digit;
        }
    }
}

void checkGuess(const string& secret, const string& guess, int& bulls, int& cows)
{
    bulls = 0;
    cows = 0;
    for (int i = 0; i < 4; i++)
    {
        if (guess[i] == secret[i])
        {
            bulls++;
        } else if (secret.find(guess[i]) != string::npos)
        {
            cows++;
        }
    }
}

void playGame(const string& secret, int attempts = 0)
{
    string guess;
    cout << "Enter your guess: ";
    cin >> guess;

    int bulls, cows;
    checkGuess(secret, guess, bulls, cows);

    if (bulls == 4)
    {
        cout << "Congratulations! You guessed the number in " << attempts + 1 << " attempts.\n";
        return;
    }

    else
    {
        cout << "Bulls: " << bulls << ", Cows: " << cows << endl;
        playGame(secret, attempts + 1);
    }
}

int main()
{
    string secret;
    generateNumber(secret);
    cout << "I have generated a 4-digit number. Try to guess it!\n";

    playGame(secret);

    return 0;
}
