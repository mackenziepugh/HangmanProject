//  Option.cpp
//  Hangman


#include "Option.h"

using namespace std;

void user_options(string random_word)
{
    string guess_letter = "1";
    string guess_word = "2";
    string users_choice = "0";
    
    cout << "To guess a letter, enter 1. To guess the word, Enter 2:  ";
    cin >> users_choice;
    
    //check validity of input
    ValidateInput validateInput; 
    string option = validateInput.only_one_or_two(users_choice);
    
    if (option == guess_letter)
    {
        // use function in Guess_Letter.h
        user_guess_letter(random_word); 
    }
    else
    {
        int wrong_guesses = 0; 
        // use function in Guess_Word.h
        user_guess_word(wrong_guesses, random_word); 
    }

}
