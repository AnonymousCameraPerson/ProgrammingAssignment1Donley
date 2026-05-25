#include "logic.h"
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>
#include <iterator>
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
	int positionsVisited[20];
	int wordsize = std::size(word);
	char wordToReturn[20] = {};
	int wordToReturnIndex = 0;
	int randomPosition;
	char charAtRandomPosition;

	for (int i = wordsize; i > 0; i--) {
		//i equals size of remaining letters to scramble
		randomPosition = rand() % i;
		int j = 0;
		int k = 0;
		//for (int k=0; k<i;k++){
		while (k <= wordsize){
			//bool exists = std::any_of(std::begin(positionsVisited), std::end(positionsVisited), [j](int x) {
			auto it = std::find(std::begin(positionsVisited), std::end(positionsVisited), k);
				//}
			if (it != std::end(positionsVisited)) {
				k++;
				continue;
			}
			else if (j==randomPosition) {
				charAtRandomPosition = word[k];
				wordToReturn[wordToReturnIndex] = charAtRandomPosition;
				positionsVisited[wordToReturnIndex] = k;
				wordToReturnIndex++;
				break;
			}
			else {
				j++;
				k++;
			}
		}
	}    
	string returnValue = wordToReturn;
	return returnValue;
	//return word;
}
void logic::setWord(string newWord)
{
    word = newWord;
}

bool logic::checkWord(string word, string userInput, int& wins) {
	if (userInput == word) {
		wins++;
		return true;
	}
	else {
		return false;
	}
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

//string logic::checkWord(string scrambledWord, string userInput)
//{
//	if (userInput == word)
//		return "true";
//	else
//		return "false";
//}

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
		file.close();
    }
    else {
		std::cerr << "Unable to open file\n";
    }
	return 0;
}

string logic::checkIntel(int intel) {
	if (intel == 5){
		return "Congratulations, you are the smartest!";
	}
	else if (intel==4){
		return "Amazing! Try again to get the highest score! You are almost there!";
	}
	else if (intel == 3) {
		return "You're better than the worst! Try again to get better!";
	}

	if (intel == 2){
		return "Good job, try again to get better!";
	}
	if (intel == 1) {
		return "I can see you're a beginner. Keep practicing! You'll get better!";
	}
	return "You got nothing.";
}
