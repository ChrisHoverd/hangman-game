#include <iostream>
#include <string>
using namespace std;

string word = "green";
int word_length = word.length();
char letter_guess;
int guessed = 1;
string placeholder = "_____";


void findLetter(char letter)
{
    int occurence = 0;
    int pos;
    int pos2;
    pos = word.find(letter);
    if(pos != string::npos)
    {
        occurence++;
        placeholder[pos] = letter;
        pos2 =  word.find(letter,pos+1);
        if(pos2 != string::npos)
        {
            occurence++;
            placeholder[pos2] = letter;
        }
    }
   cout << "The word includes " << occurence << " " << "\""<< letter << "\"" "\n";
   cout << placeholder << "\n"; 
}

int main()
{
    cout << "Hangman Game \n" << "The word I'm thinking of is " << word_length << " characters long.\n";
    
    while(guessed != 0)
    {
        cout << "Please guess a letter.\n";
        cin >> letter_guess;
        findLetter(letter_guess);
        guessed = word.compare(placeholder);
    }  
    cout << "Congratulations, you successfully guessed the word!\n";
    system("pause");
    return 0;
}

