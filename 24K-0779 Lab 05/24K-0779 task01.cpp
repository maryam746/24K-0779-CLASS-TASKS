#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

bool game(int guessnumber, int player, int n)
{
    int guess;
    cout << "Player " << player << ", enter your guess: ";
    cin >> guess;
    if (guess < 1 || guess > 100)
    {
        cout << "out of range" << endl;
        return game(guessnumber, player, n);
    }
    if (guess == guessnumber)
    {
        cout << "Player " << player << " wins" << endl;
        return true;
    }
    cout << (guess < guessnumber ? "too low" : "too high") << endl;
    int next = (player % n) + 1;
    return game(guessnumber, next, n);
}

int main()
{
    srand(time(0));
    int guessnumber = rand() % 100 + 1;
    int n;
    cout << "Enter number of players: ";
    cin >> n;
    game(guessnumber, 1, n);
}
