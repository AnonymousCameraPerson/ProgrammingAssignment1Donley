#pragma once
#include <string>
#include <iostream>

class logic {
public:
    logic();
    void setWord(std::string newWord);
    std::string getWord();
	std::string checkWord(std::string scrambledWord, std::string userInput);
        //constructor
    void introduction();
    //Provides a basic introduction ot the user
    bool createLists();
    //Opens a file and reads in the list of words that can be scrambled
    //Returns: true if words inserted and false if not
    bool playGame();
    //Carries out the actual word scrmabling
    //Returns: true if user wins and false if not
    std::string scrambler(std::string word);
    //Takes in a word and scrambles it
    //Returns a scrambled version of the parameter
    void end();
    //Displays the endgame information


////////////void setWord(std::string newWord);
////////////std::string getWord();

private:
    int numCorrect,           //the number of correct words
        smallWordLength,      //length of word arrays
        mediumWordLength,
        largeWordLength;
    std::string word;
	std::string scramble;
	std::string words[100];       //array of words read in from the file
	std::string scrambleWord[100]; //array of scrambled words
    std::string smallWords[5];    //array of words of length 4-5
    std::string mediumWords[5];   //array of words of length 6-7
    std::string largeWords[5];    //array of words of length 8+

    ////////////////////string word;
    ////////////////////string scramble;
    ////////////////////string words[100];
}; //end class logic
