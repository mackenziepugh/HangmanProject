//  End.cpp
//  Hangman


#include "End.h"

using namespace std;

// outputs final hangman drawing
void endgame(string rand_word, int wrong_guesses, string fill_in)
{

    if (fill_in == rand_word)
    {
        //if user guessed correctly
        hangman_drawing(wrong_guesses);
        cout << "CONGRATS!!! You won! The word was ' " << rand_word << "'." << endl;
        cout << "YOU WON!!!" << endl;
    }
    // if user ran out of guesses
    else if (wrong_guesses == 6) 
    {
        hangman_drawing(wrong_guesses);
        cout << "Sorry, you ran out of guesses. The word was '" << rand_word << "'." << endl;
        cout << "YOU LOST." << endl;
    }
    else 
    {
        // if user guessed the word incorrectly
        wrong_guesses = 6;
        hangman_drawing(wrong_guesses);
        cout << "Sorry, you were wrong. The word was '" << rand_word << "'." << endl;
        cout << "YOU'VE LOST." << endl;
    }

}
