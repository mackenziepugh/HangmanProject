//  ValidateInput.h
//  Hangman

#pragma once

#include <limits>
#include <string>
#include <iostream>

using namespace std;

class ValidateInput
{
public:
    ValidateInput ();
    char Validate_one_letter(string used_letters);
    string Validate_one_or_two(string player_input);
};
