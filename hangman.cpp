//hangman.cpp
#include "hangman.h"
#include <string>
#include <cstdlib>
#include <time.h>
#include <ctime>
#include <fstream>
#include <stdexcept>

hangman::hangman()
{
    str = randomlyGenerateWord(); //initialize variable
    arr = new char [str.length()]; //initialize variable
    for (long long unsigned int i=0; i<str.length(); i++) //a for loop
    {
      arr[i]='_'; //set ith of the array to be "_"
    }
}

string hangman::randomlyGenerateWord(){
int size=0; //initialize variable
std::string word; //initialize variable
  std::ifstream myInFile; ////initialize variable
  myInFile.open("words.txt"); //open file
  if (myInFile.is_open()) //if file is open
  {
myInFile >> size; //get the size
        wordarr = new std::string [size]; //initialize and renew variable
for (int i=0; i<size; i++) //a for loop
{
myInFile >> word; //get the word
                wordarr[i]=word; //set the word at ith of the arrry
}
        myInFile.close(); //close the file
        srand(time(NULL)); //set a random number
  int num = rand()%size; //initialize variable
  return wordarr[num]; //return the result

}

    throw (std::runtime_error("words.txt did not open correctly")); //throw the result if the file is not open

}

bool hangman::charchecker(char guess)
{
bool isChar= false; //initialize variable, to make it be false
  for (int i=97; i<=122; i++) //a for loop
  {
    if (guess==i) //if the guess is correct
    {
      isChar=true; //return true
    }
  }
  return isChar; //return the result
}

bool hangman::funcForWrongGuess(int numGuesses){
if (numGuesses<=5) //if the guess is less or equal to 5
  {
    return false; //return false
  }
  else //if the guess is bigger than 5
  {
    return true; //return true
  }

}

void hangman::displayStickFigure(int numGuesses){
if (numGuesses==0) //if the guess is 0
  {

  }
  else if (numGuesses==1) //if the guess is 1
  {
    std::cout<< "O\n"; //print out the guess number 
  }
  else if (numGuesses==2) //if the guess is 2
  {
    std::cout << "O\n|\n"; //print out the guess number 
  }
  else if (numGuesses==3) //if the guess is 3
  {
    std::cout << " " << "O\n" << "\\" << "|" << "\n"; //print out the guess number 
  }
  else if (numGuesses==4) //if the guess is 4
  {
    std::cout << " " << "O\n" << "\\" << "|" << "/" << "\n"; //print out the guess number 
  }
  else if (numGuesses==5) //if the guess is 5
  {
    std::cout << " " << "O\n" << "\\" << "|" << "/" << "\n" << " /\n"; //print out the guess number 
  }
  else //if the guess is not 0, 1, 2, 3, 4, 5
  {
    std::cout << " " << "O\n" << "\\" << "|" << "/" << "\n" << " /\\\n"; //print out the guess number 
  }

}

void hangman:: run()
{
    int ans; //initialize variable
    long long unsigned int count =0; //initialize variable
    bool flag = false; //set the variable to be false
    bool charflag; //initialize variable
    bool displayFlag = true; //set the variable to be true
    std::string guessed = ""; //initialize variable
    std::string wrongGuessed = ""; //initialize variable
    bool wrongGuess=false; //set the variable to be false
    bool flagForAnotherGuess = false; //set the variable to be false
   
  do{
      std::cout << "Would you like to guess the whole word, note: you can only guess the whole word once and if its incorrect you lose (1) or a letter of the word (2): "; //print out the rule
      std::cin>>ans; //get the user choice
      //bad = std::cin.fail();
  if(std::cin.fail()){ //if cannot get the choice
      std::cin.clear(); //clear the choice
      std::cin.ignore(1000,'\n'); //ignore the coice
      displayFlag=false; //set the variable to be false
      flag=true; //set the variable to be true
  }
   if (ans==1) //if choice is 1
    {
      std::string guess; //initialize the variable
      std::cout << "Input your guess of what the word is: "; //ask for the word
      std::cin>>guess; //get the guess
      if (guess==str) // if the guess is correct
      {
        flag=true; //set the variable to be true
        displayFlag=false; //set the variable to be false
        std::cout << "You win\n";
      }
      else // if the guess is not correct
      {
        flag=true; //set the variable to be true
        displayFlag=false; //set the variable to be false
        std::cout << "You lose\n"; //tell the user they lose
      }

    }
    else if (ans==2) //if choice is 2
    {
      wrongGuess=false; //set the variable to be false
      char guess; //initialize variable
      do {
      flagForAnotherGuess=false; //set the variable to be false
     
      do{
      std::cout << "Please input your guess of a letter contained in the word: "; //ask for a word
      std::cin >> guess; //get the guess
      charflag=charchecker(guess); //call the function and put guess into it
      }while(charflag==false); //if the flag is false
      for (long long unsigned int i=0; i<guessed.length(); i++) //a for loop
      {
        if (guess == guessed[i]) //if the guess is ture
        {
          flagForAnotherGuess = true; //return true
        }
      } } while (flagForAnotherGuess==true); //if another choice is true, stop looping
      for (long long unsigned int i=0; i<str.length(); i++) //a for loop
      {
        if (guess==str[i]) //if the guess is correct
        {
          arr[i]=str[i]; //renew ith word at the array
          count++; //renew the count
          wrongGuess=true; //return true
        }
      }
      if (wrongGuess==false) //if the guess is not correct
      {
        wrongGuessed=wrongGuessed+guess; //renew word guesses
        flag = funcForWrongGuess(wrongGuessed.length()); //call the function and put length into it
        if (flag==true) //if the guess is true
        {
          std::cout << "You lose\n"; //tell the user he loses the game
          displayFlag=false; //return false
        }
      }
      guessed=guessed+guess; //renew the guess
      if (count == str.length()) //if the count equal the length of the word
      {
        flag=true; //return true
        displayFlag=false; //return false
        std::cout<<"You win!\n"; //tell the user he wins the game
      }

    }
    else //if choice is not 1 or 2
    {
      std::cout << "Not a valid input\n"; //tell the user the input is invalid
    }
    if (displayFlag==true) //if the variable is true
    {
      displayStickFigure(wrongGuessed.length()); //call the function and put a the word length
    for (long long unsigned int i=0; i<str.length(); i++) //a for loop
    {
      std::cout<<arr[i]; //print out the word at ith of the array
    }
    std::cout<<"\nList of Guesses\n"; //print out the list of guesses
    for (long long unsigned int i=0; i<guessed.length(); i++) //a for loop
    {
      std::cout << guessed[i] << " "; //print out the guesses
    }
    std::cout<<"\n"; //turin to the next line
    }
    }while ((ans!=1 || ans!=2) && flag==false); //if the falg is false if and only if choice is 1 or 2, quit the game


}

hangman::~hangman()
{
  delete[] arr; //delete the array
  delete[] wordarr; //delete the array
}