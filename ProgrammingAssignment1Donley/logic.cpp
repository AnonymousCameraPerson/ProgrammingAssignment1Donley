#include "logic.h"
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using std::string;


//return type className::class Function name()
//constructor className::className()
logic::logic()
{
    word = "";
    scramble = "";
    for (int i = 0; i < 100; i++)
    {
		srand(time(0));
		int randomNum = rand() % std::size(smallWords);
        words[i] = "";
        //no deconstructor needed since no dynamic memory has been created
    }
}
//return type className::class Function name(parameter)
void logic::setWord(string newWord)
{
    word = newWord;
}

string logic::getWord()
{
	srand(time(0));
	int randomNum = rand() % std::size(smallWords);
	word = smallWords[randomNum];
    return word;
}

string logic::checkWord(string scrambledWord, string userInput)
{
	if (userInput == word)
		return "true";
	else
		return "false";
}

bool logic::createLists()
{
	std::ifstream file("dictionary.txt");
	std::string line;
	smallWordLength = 0;
	mediumWordLength = 0;
	largeWordLength = 0;
    if (file.is_open()) {
        while (std::getline(file, line)) {
            //std::cout << line << '\n';
			if (line.length() == 4 || line.length() == 5)
			{
				smallWords[smallWordLength] = line;
				smallWordLength++;
			}
			else if (line.length() == 6 || line.length() == 7)
			{
				mediumWords[mediumWordLength] = line;
				mediumWordLength++;
			}
			else if (line.length() >= 8)
			{
				largeWords[largeWordLength] = line;
				largeWordLength++;
			}
        }
    }
    else {
		std::cerr << "Unable to open file\n";
    }
	return 0;
}

