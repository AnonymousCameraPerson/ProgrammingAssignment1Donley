
class logic {
public:
    logic();
    void setWord(string newWord);
    string getWord();
        //constructor
    void introduction();
    //Provides a basic introduction ot the user
    bool createLists();
    //Opens a file and reads in the list of words that can be scrambled
    //Returns: true if words inserted and false if not
    bool playGame();
    //Carries out the actual word scrmabling
    //Returns: true if user wins and false if not
    string scrambler(string word);
    //Takes in a word and scrambles it
    //Returns a scrambled version of the parameter
    void end();
    //Displays the endgame information


////////////void setWord(string newWord);
////////////string getWord();

private:
    int numCorrect,           //the number of correct words
        smallWordLength,      //length of word arrays
        mediumWordLength,
        largeWordLength;
    string word;
	string scramble;
	string words[100];       //array of words read in from the file
	string scrambleWord[100]; //array of scrambled words
    string smallWords[50];    //array of words of length 4-5
    string mediumWords[50];   //array of words of length 6-7
    string largeWords[50];    //array of words of length 8+

    ////////////////////string word;
    ////////////////////string scramble;
    ////////////////////string words[100];
}; //end class logic
