#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <ctime>
#include "Test.h"
#include "hangman.h"
#include "tictacto.h"
#include "Trivia.h"
#include "Executive_Black_Jack.h"
using namespace std;
void runTests() //run the program
{
	Test testObj; //create a node
	testObj.run(); //rum the function

}
void printMenu() //print the menu
{

int menuOption = 0; //initialize the variable
do{ //run the game until user want to quit
	cout << "\n* * * * * * * * * * * * * * * * \n"; //print out the menu
	cout<< "*        Game Options:        * \n"; //print out the menu
	cout << "* 1) Tic-tac-toe              *\n* 2) Hangman                  *\n* 3) Trivia                   *\n* 4) Blackjack                *\n* 5) Exit                     *\n"; //print out the menu
	cout << "  Player Choice: "; //ask for user 's choice
	cin >> menuOption; //get user's choice
	if(std::cin.fail()){ //if cannot get the choice
      std::cin.clear(); //clear the choice
      std::cin.ignore(1000,'\n'); //ignore the coice}
	}
	cout << "* * * * * * * * * * * * * * * * \n"; //print out the menu

	if(menuOption == 1){ //if user choose to play game 1
		std::cout << "\x1B[2J\x1B[H"; //print out the choice
		cout << "Rules of the game:\n\n"; //print out game rule
		cout << "Two players, one in a circle (O) and one in a cross (X), take turns to play their own symbols on the 3x3 grid.\n"; //print out game rule
		cout << "The first to connect horizontally, straightly, and diagonally to form a line wins. If both sides play correctly, there will be a tie.\n\n"; //print out game rule
		tictacto exe; //create a node
		exe.run(); //run the game

	}
	if(menuOption == 2){ //if user choose to play game 2
		std::cout << "\x1B[2J\x1B[H"; //print out the choice
		cout << "You have chosen to play hangman. You will guess one letter of a secret word at a time until you either guess every\n"; //print out game rule
		cout << "letter of the word correctly or the entirety of the stick figure has been displayed\n"; //print out game rule
		cout << "(one body part of the stick figure will be displayed for each wrong guess).\n"; //print out game rule
		cout << "You have to figure out the word in at most 6 guesses to win. You can choose to guess the whole word once, but if you guess incorrectly you lose.\n"; //print out game rule
		cout << "NOTE: the words are all lowercase, so don't waste your guess with an uppercase letter.\n\n"; //print out game rule
		hangman exe; //create a node
		exe.run(); //run the game
	}
	if(menuOption == 3) //if user choose to play game 3
	{
		Trivia obj; //create a node
		obj.run(); //run the game
	}
	if(menuOption ==4) //if user choose to play game 4
	{
		std::cout << "\x1B[2J\x1B[H"; //print out the choice
		cout << " Welcome to BlackJack!\n"; //print out the welcome menu
		cout << "You will place a bet before each draw (no limit) and try to get as close to as 21 without going over.\n";
		cout << "The game is played with one 52 set of cards with face cards having a value of 10\n";
		cout << "Ace's have either a value of 1 or 11, if you draw an Ace before total of 10, the ace is defaulted to 11 otherwise its value is 1.\n";
		cout << "Once the player sits on their hand, the house will draw to match or go over the player's hand.\n";
		cout << "If the player and house tie's, the house wins.\n";
		Executive_Black_Jack exe; //create a node
		exe.run(); //run the game
	}
	}while(menuOption != 5); //if user choose 5, then quit game

}
int main(){ //run the game 
        std::cout << "\x1B[2J\x1B[H"; //print out the game menu

        cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n";  //print out the welcome menu
        cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n\n"; //print out the welcome menu
        cout << "W                 W   E E E E E   L           C C C C     O  O O     M          M   E E E E E \n"  ; //print out the welcome menu
        cout << " W               W    E           L          C          O        O   M  M  M  M M   E\n"; //print out the welcome menu
        cout << "   W      W     W     E E E E     L          C          O        O   M     M    M   E E E \n"; //print out the welcome menu
        cout << "     W   WW   W       E           L          C          O        O   M          M   E \n "; //print out the welcome menu
        cout <<"       W   W         E E E E E   L L L L L   C C C C     O  O  O    M          M   E E E E E \n\n "; //print out the welcome menu
        cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n"; //print out the welcome menu
        cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n"; //print out the welcome menu

        cout<< "\n\nHello! Welcome to Team 9 Mini Games \n"; //print out the welcome menu
	int menuOption; //initialize the variable
	do //run the game until user want to quit
	{

		cout << "Would you like to:\n"; //print out the game menu
		cout << "1. See Game Menu\n"; //print out the game menu
		cout << "2. Run tests\n"; //print out the game menu
		cout << "3. Exit\n"; //print out the game menu
		cin >> menuOption; //get the game menu
		if(std::cin.fail())
		{ //if cannot get the choice
			std::cin.clear(); //clear the choice
			std::cin.ignore(1000,'\n'); //ignore the coice}
		}
		if(menuOption ==1) //if use choose 1
		{
			printMenu(); //call the function
		}
		else if(menuOption == 2) //if use choose 2
		{
			runTests(); //call the function
		}
	}while(menuOption != 3); //if user choose 3, then quit game
	
}
