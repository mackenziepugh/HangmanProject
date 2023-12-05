//  Hangman_Drawing.cpp
//  Hangman

#include "Hangman_Drawing.h"

using namespace std;

// prints the hangman drawing and updates based on number of wrong guesses
void hangman_drawing(int wrong_guesses)
{
    cout << "  ____" << endl;
    cout << " |    |" << endl;
    cout << " |    " << (wrong_guesses >= 1 ? "O" : "") << endl;
    cout << " |   " << (wrong_guesses >= 3 ? "/" : "") << (wrong_guesses >= 2 ? "|" : "") << (wrong_guesses >= 4 ? "\\" : "") << endl;
    cout << " |   " << (wrong_guesses >= 5 ? "/" : "") << " " << (wrong_guesses >= 6 ? "\\" : "") << endl;
    cout << "_|_" << endl;
    cout << endl;
}

