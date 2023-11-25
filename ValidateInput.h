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
    char only_one_letter(string used_letters);
    string only_one_or_two(string user_input);
};
