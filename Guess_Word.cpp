//  Guess_Word.cpp
//  Hangman


#include "Guess_Word.h"

using namespace std;

void user_guess_word(int wrong_guesses, string rand_word)
{
    string guess;
    cout << "Type your final guess of the word here: ";
    cin >> guess;
    cout << endl;
    
    // replaces blank with user's guess  which will then determine if they are correct
    string fill_in = guess; 
    
    endgame(rand_word, wrong_guesses, fill_in);
}

