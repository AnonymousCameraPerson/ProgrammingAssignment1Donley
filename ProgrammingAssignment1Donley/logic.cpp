#include "logic.h"
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>
using std::string;
using namespace std;


//return type className::class Function name()
//constructor className::className()
logic::logic()
{

    /*word = "";
    scramble = "";
    for (int i = 0; i < std::size(word); i++)
    {
		srand(time(0));
		int randomNum = rand() % std::size(smallWords);
        words[i] = "";
        //no deconstructor needed since no dynamic memory has been created
    }*/
}
//return type className::class Function name(parameter)
void arrayFunction(string word) {
	char wordArray[1];
	for (int i = 0; i < std::size(word); i++)
	{
		wordArray[i] = word[i];
	}
	//scrambler(wordArray);
}

string logic::scrambler(string word) {
	char arr[50];
	int size = std::size(word);
	int randomChoices[50] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	int numsSeen[50] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	for (int i = 0; i < std::size(word); i++) {
		randomChoices[i] = i;
	}    

	//OR while randomChoices is not empty?????
	for (int i = 0; i < std::size(word); i++) {
		int randomNumber = rand() % size;
		//choose from choices

		numsSeen[i] = randomNumber;
		cout << randomNumber << endl;
		//remove this number from randomChoices
		//inner loop goes through every char. 
		// for each, add to numSeen
		//remove num from randomChoices
		for (int j = 0; j < std::size(word); j++) {
			if (numsSeen[i] == randomChoices[j]){
				//remove randomChoices[j] from randomChoices
			}
			else {
				arr[randomNumber] = word[randomNumber];
			}
		}
	
		size--;
	//	
	}
	string scrambledWord = arr;
	return scrambledWord;
	//return word;
}
void logic::setWord(string newWord)
{
    word = newWord;
}

string checkWord(string word, string userInput) {
	if (userInput == word)
		return "true";
	else
		return "false";
}
string logic::getWord(){
return word;
}
string logic::getWord1()
{
	//srand(time(0));
	int randomNum = rand() % std::size(smallWords);
	word = smallWords[randomNum];
    return word;
}
string logic::getWord2()
{
	//srand(time(1));
	int randomNum = rand() % std::size(smallWords);
	word = smallWords[randomNum];
	return word;
}
string logic::getWord3()
{
	//srand(time(2));
	int randomNum = rand() % std::size(mediumWords);
	word = mediumWords[randomNum];
	return word;
}
string logic::getWord4()
{
	//srand(time(0));
	int randomNum = rand() % std::size(mediumWords);
	word = mediumWords[randomNum];
	return word;
}
string logic::getWord5()
{
	//srand(time(4));
	int randomNum = rand() % std::size(largeWords);
	word = largeWords[randomNum];
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

