//  Guess_Letter.cpp
//  Hangman


#include "Guess_Letter.h"
#include "ValidateInput.h"
#include "Hangman_Drawing.hpp"
#include "End.h"

void player_guess_letter(string rand_word)
{
    // initializing variables and construct
    string used_letters;
    ValidateInput validateInput;
    char letter;
    int wrong_guesses = 0;

    // determines length of the word
    int length = rand_word.length();
    
    //puts underscores as a temporary placeholder for letters.
    string fill_in(length, '_'); 
    
    while (fill_in != rand_word && wrong_guesses < 6)
    {
        hangman_drawing(wrong_guesses);
        
        // outputs the underscores
        cout << fill_in << endl; 
        // outputs letters already guessed
        cout << "Used letters: " << used_letters << endl; 
        
        //The user will be able to guess the word after three guesses or continue guessing letters.
        if (count(fill_in.begin(), fill_in.end(), '_') < 3 || wrong_guesses == 5) 
        {
            string final_guess = "0";
            string yes = "1";
            
            if (wrong_guesses == 5)
            {
                cout << "You have one guess left. Would you like to guess the word?" << endl;
                cout << "Enter 1 for yes...Enter 2 for no: ";
                cin >> final_guess;
                
                // checks validity
                string choice = validateInput.Validate_one_or_two(final_guess); 
                
                if (choice == yes)
                {
                    player_guess_word(wrong_guesses, rand_word);
                    break;
                }
            }
            else
            {
                cout << "There are less than 3 letters left. Would you like to guess the word?" << endl;
                cout << "Enter 1 for yes...Enter 2 for no: ";
                cin >> final_guess;
                
                // checks validity
                string choice = validateInput.Validate_one_or_two(final_guess); 
                
                if (choice == yes)
                {
                    player_guess_word(wrong_guesses, rand_word);
                    break;
                }
            }
        }
        
        // calling function to allow code to only take in 1 character that hasn't been previously used
        letter = validateInput.Validate_one_letter(used_letters); 

        // adds letter inputted by user into user_letters string
        used_letters += letter; 
        
        // checks every letter of the rand_word
        bool correct_guess = false;
        for (int i = 0; i < length; i++) 
        {
            // if letter guessed by user is in the word
            if (rand_word[i] == letter) 
            {
                // corresponding underscore is filled in
                fill_in[i] = letter; 
                correct_guess = true;
            }
        }
        
        // if the letter guessed is wrong a body part is added.
        if (!correct_guess) 
        {
            wrong_guesses++;
            cout << "Your guest was incorrect." << endl;
        }
    }

    // runs if all guesses were used and are incorrect
    if (wrong_guesses == 6 || fill_in == rand_word) 
    {
        endgame(rand_word, wrong_guesses, fill_in);
    }
}
