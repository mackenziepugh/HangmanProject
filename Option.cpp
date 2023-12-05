//  Option.cpp
//  Hangman

#include "Option.h"

using namespace std;

void player_options(string word)
{
    string guess_letter = "1";
    string guess_word = "2";
    string player_choice = "0";
    
    cout << "To guess a letter, enter 1. To guess the word, Enter 2:  ";
    cin >> player_choice;
    
    //check validity of input
    ValidateInput validateInput; 
    string option = validateInput.Validate_one_or_two(player_choice);
    
    if (option == guess_letter)
    {
        // use function in Guess_Letter.h
        player_guess_letter(word); 
    }
    else
    {
        int wrong_guesses = 0; 
        // use function in Guess_Word.h
        player_guess_word(wrong_guesses, word); 
    }

}
