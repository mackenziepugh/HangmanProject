//  main.cpp
//  Hangman


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "Option.h"
#include "Guess_Letter.h"
#include "Guess_Word.h"


using namespace std;

// opens txt file with wordbank
string open_file ()
{
    ifstream inFile ("/Users/mackenziepugh/Downloads/HangmanProject/HangmanProject/wordbank.txt", ios::in); 
    if ( !inFile )
    {
        cerr << "File could not be opened" << endl;
        exit (1);
    }
    
    vector<string> wordbank;
    string word;

    // makes words from txt file into a vector
    while (inFile >> word) 
    {
        wordbank.push_back(word);
    }
    
    inFile.close();
    
    srand((unsigned int)time(nullptr)); 
    // randomly chooses an index in the vector
    int rand_word_index = rand() % wordbank.size();
    // index corresponds to word in the txt file
    string rand_word = wordbank[rand_word_index]; 
    
    return rand_word;
}

int main()
{
    string end;

    //introduction to game (instuctions)
    cout << "Welcome to Hangman!!!" << endl << endl;
    cout << "A word has been randomly chosen for you." << endl;
    cout << "You have 6 guesses to correctly guess the word." << endl;
    cout << "Each incorrect guess is an added body part." << endl;
    cout << "Once the body is completely hung , it's game over." << endl << endl;
    
    // calls function txt file to open and choose word
    string secret_word = open_file(); 
   
    cout << "The word is ";
    int length = secret_word.length();
    int i = 0;
    while (i < length)
    {
        cout << "_";
        i++;
    }
    cout << " and has " << length << " letters." << endl;
    
    user_options(secret_word); // calls to function in Option.h


    cout << "Thanks for playing Hangman!! Press any key to exit." << endl;
    cin >> end;

    return 0;
}
