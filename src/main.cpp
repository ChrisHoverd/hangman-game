#include <iostream>
#include <string>
#include <time.h>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

vector<string> words = {"green", "orange", "bike", "karate"};
int random_number;
char letter_guess;
int guessed = 1;



class WordObject{
    public:
        string word = words[random_number];
        int word_length = word.length();
        string consoleWord = word;

        void fillConsoleWord(){
            for (int i = 0; i < word_length; i++)
            {
                consoleWord[i] = '_';
            }
        }
        void findLetter(char letter)
        {
            int occurence = 0;
            int pos;
            int pos2;
            pos = word.find(letter);
            if(pos != string::npos)
            {
                occurence++;
                consoleWord[pos] = letter;
                pos2 =  word.find(letter,pos+1);
                if(pos2 != string::npos)
                {
                    occurence++;
                    consoleWord[pos2] = letter;
                }
            }
            cout << "The word includes " << occurence << " " << "\""<< letter << "\"" "\n";
            cout << consoleWord << "\n"; 
            }
};

void getRandomNumber(){
    srand(time(0));
    random_number = rand()%5;
}

int main()
{
    getRandomNumber();
    WordObject secretWord;
    secretWord.word = words[random_number];
    secretWord.fillConsoleWord();
    cout << "Hangman Game \n" << "The word I'm thinking of is " << secretWord.word_length << " characters long.\n";
    
    while(guessed != 0)
    {
        cout << "Please guess a letter.\n";
        cin >> letter_guess;
        secretWord.findLetter(letter_guess);
        guessed = secretWord.word.compare(secretWord.consoleWord);
    }  
    cout << "Congratulations, you successfully guessed the word: " << secretWord.word <<endl;
    system("pause");
    return 0;
}

