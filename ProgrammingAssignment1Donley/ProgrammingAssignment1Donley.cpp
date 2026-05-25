#include <iostream>
#include <allegro5/allegro.h>
#include <string>
#include <ctime>
#include "logic.h"
using std::string;
using namespace std;


logic game; //instance of logic
bool finished = false;
bool timeOut = false;

void* input(ALLEGRO_THREAD *ptr, void *arg);
void* timer(ALLEGRO_THREAD* ptr, void* arg);


int main(int argc, char *argv[])
{
	
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
	string userinput1;
	string userinput2;
	string userinput3;
	string userinput4;
	string userinput5;
	int wins = 0;
	//read the file into game.readFile()
	game.playGame();
	game.createLists();
	srand(time(0));

	game.setWord(game.getWord1());
	string word1 = game.getWord();
	string scramword1 = game.scrambler(word1);
	cout << "Guess the word: "<<scramword1 << endl;
	cin >> userinput1;
	bool win1 = game.checkWord(word1, userinput1, wins);

	game.setWord(game.getWord2());
	string word2 = game.getWord();
	if (word2 == word1)
	{
		game.setWord(game.getWord2());
		word2 = game.getWord();
	}
	string scramword2 = game.scrambler(word2);
	cout << "Guess the word: " << scramword2 << endl;
	cin >> userinput2;
	bool win2 = game.checkWord(word2, userinput2, wins);
	//cout << word2 << endl;

	game.setWord(game.getWord3());
	string word3 = game.getWord();
	string scramword3 = game.scrambler(word3);
	cout << "Guess the word: " << scramword3 << endl;
	cin >> userinput3;
	bool win3 = game.checkWord(word3, userinput3, wins);
	//cout << word3 << endl;

	game.setWord(game.getWord4());
	string word4 = game.getWord();
	while (word4 == word3) {
		game.setWord(game.getWord3());
		word4 = game.getWord();
	}
	string scramword4 = game.scrambler(word4);
	cout << "Guess the word: " << scramword4 << endl;
	cin >> userinput4;
	bool win4 = game.checkWord(word4, userinput4, wins);
	//cout << word4 << endl;

	game.setWord(game.getWord5());
	string word5 = game.getWord();
	string scramword5 = game.scrambler(word5);
	cout << "Guess the word: " << scramword5 << endl;
	cin >> userinput5;
	bool win5 = game.checkWord(word5, userinput5, wins);
	//cout << word5 << endl;
	string tellUser = game.checkIntel(wins);
	cout << endl<<tellUser << endl;
	//cin >> finished;
	finished = true;
	return NULL;
}

void* timer(ALLEGRO_THREAD* ptr, void* arg)
{
	time_t startTime, currentTime;
	startTime = time(NULL);
	currentTime = time(NULL);
	while (currentTime-startTime <60 && !finished)
	{
		currentTime = time(NULL);
	}
	timeOut = true;
	return NULL;
}