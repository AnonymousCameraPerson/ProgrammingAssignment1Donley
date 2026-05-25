#include <iostream>
#include <allegro5/allegro.h>
#include <string>
#include <ctime>
#include "logic.h"
using std::string;
using namespace std;

void* input(ALLEGRO_THREAD *ptr, void *arg);
void* timer(ALLEGRO_THREAD* ptr, void* arg);



logic game; //instance of logic
bool finished = false;
bool timeOut = false;

int main()
{
	string userinput1;
	string userinput2;
	string userinput3;
	string userinput4;
	string userinput5;
	//read the file into game.readFile()
	game.createLists();
	srand(time(0)); 

	game.setWord(game.getWord1());
	string word1 = game.getWord();
	string scramword1= game.scrambler(word1);
	cout << scramword1 << endl;
	cin >> userinput1;
	game.checkWord(scramword1, userinput1);

	game.setWord(game.getWord2());
	string word2 = game.getWord();
	if (word2 == word1)
	{
		game.setWord(game.getWord2());
		word2 = game.getWord();
	}
	string scramword2 = game.scrambler(word2);
	cout << scramword2 << endl;
	cin >> userinput2;
	game.checkWord(scramword2, userinput2);
	//cout << word2 << endl;

	game.setWord(game.getWord3());
	string word3 = game.getWord();
	string scramword3 = game.scrambler(word3);
	cout << scramword3 << endl;
	cin >> userinput3;
	game.checkWord(scramword3, userinput3);
	//cout << word3 << endl;

	game.setWord(game.getWord4());
	string word4 = game.getWord();
	if (word4 == word3) {
		game.setWord(game.getWord3());
		word4 = game.getWord();
	}
	string scramword4 = game.scrambler(word4);
	cout << scramword4 << endl;
	cin >> userinput4;
	game.checkWord(scramword4, userinput4);
	//cout << word4 << endl;

	game.setWord(game.getWord5());
	string word5 = game.getWord();
	string scramword5 = game.scrambler(word5);
	cout << scramword5 << endl;
	cin >> userinput5;
	game.checkWord(scramword5, userinput5);
	//cout << word5 << endl;

///////////////////////////////////////
	ALLEGRO_THREAD* create1 = NULL, *create2 = NULL;
	create1 = al_create_thread(input, NULL);
	create2 = al_create_thread(timer, NULL);

	while (!finished && !timeOut)
	{
		if (!finished && !timeOut)
		{
			al_start_thread(create1);
			al_start_thread(create2);
		}
		else {
			al_destroy_thread(create1);
			al_destroy_thread(create2);
		}
	}
	if (finished)
		cout << "\n\tUser entered input and that ended the program\n";
	else
		cout<<"\n\tTime ran out and that ended the program\n";
	system("pause");
	return 0;
}
///////////////////////////////////////////
void* input(ALLEGRO_THREAD* ptr, void* arg)
{
	finished = false;
	//while finished is equal to false
	string scrambledWord = game.getWord();
		//print this out
		//get a word from the user
		//check the word from the user to the correct word
	string UserInput;
	cin >> UserInput;
	string answer = game.checkWord(scrambledWord, UserInput);
	if (answer == "true")
			//Guessed the correct word
	//if all five words were guessed
		finished = true;
	//end of the while loop
	return NULL;
}

void* timer(ALLEGRO_THREAD* ptr, void* arg)
{
	time_t startTime, currentTime;
	startTime = time(NULL);
	currentTime = time(NULL);
	while (currentTime-startTime <10 && !finished)
	{
		currentTime = time(NULL);
	}
	timeOut = true;
	return NULL;
}