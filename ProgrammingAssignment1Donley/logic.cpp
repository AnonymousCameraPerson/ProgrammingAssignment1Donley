#include "logic.h"
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
using std::string;

//return type className::class Function name()
//constructor className::className()
logic::logic()
{
    word = "";
    scramble = "";
    for (int i = 0; i < 100; i++)
    {
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
    return word;
}

bool logic::createLists()
{
	std::ifstream file("dictionary.txt");
	std::string line;
    if (file.is_open()) {
        while (std::getline(file, line)) {
            std::cout << line << '\n';
        }
    }
    else {
		std::cerr << "Unable to open file\n";
    }
	return 0;
}

