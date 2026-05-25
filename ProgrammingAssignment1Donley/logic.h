#pragma once
#include <string>
#include <iostream>

class logic {
public:
    logic();
    void setWord(std::string newWord);
    std::string getWord();
    std::string getWord1();
    std::string getWord2();
    std::string getWord3();
    std::string getWord4();
    std::string getWord5();
	std::string checkIntel(int intel);
	bool checkWord(std::string word, std::string userInput, int& wins);
        //constructor
    void introduction();
    //Provides a basic introduction ot the user
    bool createLists();
    //Opens a file and reads in the list of words that can be scrambled
    //Returns: true if words inserted and false if not
    void playGame();
	void arrayFunction(std::string word);
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
	std::string scrambledWord;       //the scrambled version of the word
    std::string scrambleWords[100]; //array of scrambled words
    std::string smallWords[100];    //array of words of length 4-5
    std::string mediumWords[100];   //array of words of length 6-7
    std::string largeWords[100];    //array of words of length 8+
	char wordArray[1];        //array of characters to hold the letters of the word
    ////////////////////string word;
    ////////////////////string scramble;
    ////////////////////string words[100];
}; //end class logic
