//  ValidateInput.cpp
//  Hangman

#include "ValidateInput.h"

ValidateInput::ValidateInput () {}

char ValidateInput::Validate_one_letter (string used_letters)
{
    char letter;
    string input;
    cout << "Enter a letter to guess: ";
    cin >> input;

    // only allows one character input
    letter = input[0]; 
    
    // checks if letter enetered has already been entered.
    while (used_letters.find(letter) != string::npos) 
    {
        cout << "You already guessed that letter." << endl;
        cout << "Please enter a different letter: " << endl;
        cin >> input;

        // only allows one character input
        letter = input[0];
    }
    
    return letter;
}

string ValidateInput::Validate_one_or_two (string user_input)
{
    string option_1 = "1";
    string option_2 = "2";
    
    // loops if user does not enter required numbers
    while (user_input != option_1 && user_input != option_2) 
    {
        cout << "Invalid." << endl;
        cout << "Please enter 1 or 2: ";
        cin >> user_input;
    }
    
    return user_input;
}
