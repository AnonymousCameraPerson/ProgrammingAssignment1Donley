#include <iostream>
#include <allegro5/allegro.h>
#include <string>
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
	//read the file into game.readFile()
	game.setWord("Frank");
	cout << game.getWord() << endl;

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
		cout << "\n\tUser entered niput and that ended the program\n";
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
	scrambledWord = game.getFirstWord()
		//print this out
		//get a word from the user
		//check the word from the user to the correct word
	answer = game.checkFirstWord(scrambleWord, UserInput)
	if (answer == true)
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