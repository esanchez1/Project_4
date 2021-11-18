#include "Trivia.h"
#include <iostream>
#include <string.h>
#include <limits>
using namespace std;


Trivia::Trivia(){
    initializegeneralKnowledgeArray(); //call the function
    initializePopCultureArray(); //call the function
    initializeCompScienceArray(); //call the function
}

void Trivia:: run() //run the game
{
	int triviaMenuOption = 0; //initialize value
			
	do{
		cout << "Welcome to Trivia! This is a one player game. You will be provided with\n"; //print out the menu
		cout << "3 different categories which you are free to choose from.\n The categories are:\n"; //print out the menu
		cout << "1) General Knowledge\n"; //print out the menu
		cout << "2) Computer Science Trivia\n"; //print out the menu
		cout << "3) Pop Culture Trivia \n"; //print out the menu
		cout << "4) Exit to Main Menu \n"; //print out the menu
		cout << "Player Choice: "; //print out the menu
		cin >> triviaMenuOption; //get the option
		bool bad = false; //set it to be false
			bad = cin.fail(); //if filed than call the function
        if(bad){ //if failed
            cout << "\n\n Please enter a valid input \n\n." << endl; //ask the player to enter again
	        cin.clear(); //clear the input
	        cin.ignore(1000, '\n'); //ignore the input
        }

		if(triviaMenuOption == 1) //if the option is 1
		{
			generalKnowledgeTrivia(); //call the function
			break; //get out of the loop
		}
		else if(triviaMenuOption == 2) //if the option is 2
		{
			computerScienceTrivia(); //call the function
			break; //get out of the loop
		}
		else if(triviaMenuOption == 3) //if the option is 3
		{
			popCultureTrivia(); //call the function
			break; //get out of the loop
		}

		if(triviaMenuOption == 4) //if the option is 4
		{
			break; //get out of the loop
		}
	}while (triviaMenuOption != 1 || triviaMenuOption != 2 ||triviaMenuOption != 3); //continue running the loop

}
bool Trivia::checkWin(int triviaPoints, int game, bool test) //check who wins the game
{
	string gameName; //initialize the string

	if(game == 1) //if the game is 1
	{
		gameName = "General Knowledge Trivia"; //print out the game name

	}
	else if (game == 2) //if the game is 2
	{
		gameName = "Computer Science Trivia"; //print out the game name
   
	}	
	else //if the game is not 1 or 2
	{
		gameName = "Pop Culture Trivia"; //print out the game name
 
	}	
	
	if(triviaPoints >= 5 ) //if the trivia point is larger or equal than 5
	{
		if(test == 0 ) //if the test is 0
		{
			cout<< "Congratulations! YOU WON! You have scored a total of "<< triviaPoints << " by playing " << gameName << "\n"; //tell the player that he wins the game

		}
		return true; //return true
	}
	else if(triviaPoints >=3 && triviaPoints < 5 && test == 0) //if tset is 0 and the trivia points is larger or equal to 3 and less than 5
	{
		if(test == 0) //if the test is 0
		{
			cout<< "You were close! You have scored a total of "<< triviaPoints << " by playing " << gameName << "\n"; //tell the player that he loses the game
		}
		return false; //return false
	}
	else
	{	if(test == 0) //if the test is 0
		{
			cout << "Try harder next time! You have scored a total of "<< triviaPoints << " by playing " << gameName << "\n"; //tell the player that he loses the game

		}
		return false; //return false
	}
	
}
void Trivia:: initializegeneralKnowledgeArray()
{
    generalKnowledgeArray[0] = "Which horoscope sign has a crab?\n"; //print out the question
    generalKnowledgeAnsArray[0] = "cancer"; //print out the answer

    generalKnowledgeArray[1] = "What is the tiny piece at the end of a shoelace called?\n"; //print out the question
    generalKnowledgeAnsArray[1] = "aglet"; //print out the answer

    generalKnowledgeArray[2] = "The Statue of Liberty was given to the US by which country? \n"; //print out the question
    generalKnowledgeAnsArray[2] = "france"; //print out the answer

    generalKnowledgeArray[3] = "What is the smallest ocean in the world?\n"; //print out the question
    generalKnowledgeAnsArray[3] = "arctic"; //print out the answer

    generalKnowledgeArray[4] = "What color eyes do most humans have?\n"; //print out the question
    generalKnowledgeAnsArray[4] = "brown"; //print out the answer

    generalKnowledgeArray[5] = "Which planet is the hottest in the solar system?\n"; //print out the question
    generalKnowledgeAnsArray[5] = "venus"; //print out the answer

    generalKnowledgeArray[6] = " Which mammal has no vocal cords?\n"; //print out the question
    generalKnowledgeAnsArray[6] = "giraffe"; //print out the answer
}
void Trivia::initializePopCultureArray()
{
    popCultureArray[0] = "What is the acronym for 'shaking my head'?\n"; //print out the question
	popCultureAnsArray[0] = "smh"; //print out the answer;

    popCultureArray[1] = "Which Avenger other than Captain America was able to pick up Thor’s Mjolnir in the Marvel movies?\n"; //print out the question
	popCultureAnsArray[1] ="vision"; //print out the answer

    popCultureArray[2] = "What was the first non-English-language film to win Best Picture at the Oscars\n"; //print out the question
	popCultureAnsArray[2] ="parasite"; //print out the answer 

    popCultureArray[3] ="Who is the oldest Kardashian sister?\n"; //print out the question
	popCultureAnsArray[3] = "kourtney"; //print out the answer

    popCultureArray[4] = "What is Chandler Bing’s middle name?\n"; //print out the question;
	popCultureAnsArray[4] = "muriel"; //print out the answer

    popCultureArray[5] ="Which Friends character was Courteney Cox originally asked to play?\n"; //print out the question
	popCultureAnsArray[5] = "rachel"; //print out the answer

    popCultureArray[6] ="In which country did the first season of Survivor take place?\n"; //print out the question
	popCultureAnsArray[6] = "malaysia"; //print out the answer
}
void Trivia:: initializeCompScienceArray()
{   
    compScienceArray[0] = " What is often seen as the smallest unit of memory?\n"; //print out the question
	compScienceAnsArray[0] = "kilobyte"; //print out the answer

    compScienceArray[1] = " Which computer hardware device performs the functions like click, point, drag, or select?\n"; //print out the question
	compScienceAnsArray[1] = "mouse"; //print out the answer

    compScienceArray[2] = "Which information storage is used to store short-term running programs and data in a computer?\n"; //print out the question
	compScienceAnsArray[2] = "ram"; //print out the answer

    compScienceArray[3] =  "What is the computer's main circuit board called?\n"; //print out the question
	compScienceAnsArray[3] = "motherboard"; //print out the answer

    compScienceArray[4] =  "When an instruction which is recently executed has high chances of execution again, it is called ________ locality\n"; //print out the question
	compScienceAnsArray[4] = "temporal"; //print out the answer

    compScienceArray[5] =  "True/False: A do-while loop goes through the loop at least one time\n"; //print out the question
	compScienceAnsArray[5] = "true"; //print out the answer

    compScienceArray[6] = "True/False: The first programmer was a man?\n"; //print out the question
	compScienceAnsArray[6] = "false"; //print out the answer
   

}

bool Trivia::checkAns(int questionNum, string category, string answer)
{   
    if(category == "General Knowledge") //if the category is "General Knowledge"
    {
        if(generalKnowledgeAnsArray[questionNum] == answer) //if the answer is correct
		{
			return true; //return true
		}
		else{ //if the answer is not correct
			return false; //return false
		}
    }
	  if(category == "Pop Culture") //if the category is "Pop Culture"
    {
        if(popCultureAnsArray[questionNum] == answer) //if the answer is correct
		{
			return true; //return true
		}
		else{ //if the answer is not correct
			return false; //return false
		}
    }
	if(category == "Computer Science") //if the category is "Computer Science"
    {
        if(compScienceAnsArray[questionNum] == answer) //if the answer is correct
		{
			return true; //return true
		}
		else{ //if the answer is not correct
			return false; //return false
		}
    }
	return false; //return false

}
void Trivia::generalKnowledgeTrivia()
{
	string question1Answer; //initialize string
	int triviaPoints = 0; //initialize variable
	cout << "\n\nYou have chosen General Knowledge! Answer 10 questions and try to earn as many\npoints as possible to be crowned a winner!\n REMEMBER: Spelling is important!\n"; //print out the rule
	
		for(int i = 0; i < 7; i++) //a for loop
		{
			cout << "\n QUESTION " << i+1 << ":\n"; //print out the question
			cout<< generalKnowledgeArray[i]; //print out the question
			cin>> question1Answer; //get the answer
			if(checkAns(i, "General Knowledge", question1Answer)==false) //if the answer is wrong
			{
				
				cout << "Wrong Answer!!\n"; //tell the player that he is wrong
			}
			else{ //if the answer is correct
					triviaPoints = triviaPoints + 1; //give the player points
			}
		}
	
	checkWin(triviaPoints, 1,0); //check if the player is win or not

}

void Trivia::computerScienceTrivia()
{
	string question1Answer; //initialize string
	int triviaPoints = 0; //initialize variable
	cout << "\n\nYou have chosen Computer Science! Answer 7 questions and try to earn as many\npoints as possible to be crowned a winner!\n REMEMBER: Spelling is important!\n"; //print out the rule
	
	for(int i = 0; i < 7; i++) //a for loop
		{
			cout << "\n QUESTION " << i+1 << ":\n"; //print out the question
			cout<< compScienceArray[i]; //print out the question
			cin>> question1Answer; //get the answer
			if(checkAns(i, "Computer Science", question1Answer)==false) //if the answer is wrong
			{
				
				cout << "Wrong Answer!!\n"; //tell the player that he is wrong
			}
			else{ //if the answer is correct
					triviaPoints = triviaPoints + 1; //give the player points
			}
		}
	
	checkWin(triviaPoints, 2, 0 ); //check if the player is win or not
}

void Trivia:: popCultureTrivia()
{
	string question1Answer; //initialize string
	int triviaPoints = 0; //initialize variable
	cout << "\n\nYou have chosen Pop Culture! Answer 7 questions and try to earn as many\npoints as possible to be crowned a winner!\n REMEMBER: Spelling is important!\n"; //print out the rule
	
	for(int i = 0; i < 7; i++) //a for loop
		{
			cout << "\n QUESTION " << i+1 << ":\n"; //print out the question
			cout<< popCultureArray[i]; //print out the question
			cin>> question1Answer; //get the answer
			if(checkAns(i, "Pop Culture", question1Answer)==false) //if the answer is wrong
			{
				
				cout << "Wrong Answer!!\n"; //tell the player that he is wrong
			}
			else{ //if the answer is correct
					triviaPoints = triviaPoints + 1; //give the player points
			}
		}
	
	checkWin(triviaPoints, 3, 0); //check if the player is win or not
}
 