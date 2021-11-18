//Executive_Black_Jack
#include "Executive_Black_Jack.h"
#include "Player.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <ctime>
using namespace std;

void Executive_Black_Jack::run() { //ru the game
srand(time(nullptr)); //create random number
char suits[4] = { 'H', 'C', 'D', 'S' } ; //since not everyone can support special ASCII characters... H = hearts, C = clubs...ect.
int value[13] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 }; //Jack, Queen, King = 10
char Jack = 'J'; //initialize variable
char Queen = 'Q'; //initialize variable
char King = 'K'; //initialize variable
char faceHolder; //initialize variable
int usedsuits[10]; //initialize variable
int usedvalues[10]; //initialize variable
int playerValue; //initialize variable
int houseValue; //initialize variable
int count = 1; //initialize variable
int bet; //initialize variable
bool boolean = false; //set variable to be false

for (int i = 0; i < 10; i++) //a  for loop
{
    usedsuits[i] = 0; //set the element at ith of the array to be 0
    usedvalues[i] = 0; //set the element at ith of the array to be 0
}

Player House; //create a node
Player Player1; //create a node
//int players;
int choice; //initialize variable

cout << "Start off with 5k coins reach 25k to win.\n"; //print out the game rule
cout << "\nGoodLuck!\n"; //print out the game rule
Player1.set_Coins(5000); //call the function

do {
printMenu(); //print the menu
cin >> choice; //get the choice
if(std::cin.fail()){ //if cannot get the choice
      std::cin.clear(); //clear the choice
      std::cin.ignore(1000,'\n'); //ignore the coice
}


if(choice == 1) { //if the choice is 1
if(boolean == false){ //if it is false
cout << "How much would you like to bet?\n"; //ask for a bet
cin >> bet; //get the bet
boolean = true; //return true
}

int suitCard = rand() % 4; //initialize variable
int cardValue = rand() % 13; //initialize variable
//checking if facecards
if(cardValue == 10) { //if the value is 10
 faceHolder = Jack; //set it to be Jack
}
else if(cardValue == 11) { //if the value is 11
    faceHolder = Queen; //set it to be Queen
    cardValue = 10; //return 10
}
else if(cardValue == 12) { //if the value is 12
faceHolder = King; //set it to be King
cardValue = 10; //return 10
}
else if(cardValue == 1) { // Rules for Aces, Aces are counted as either 11 or 1 depending on the player's total value. If the player's hand total is 
                          // less than (possibly) 21, the ace is automatically defaulted to 11. However, if the total is (possibly) over 21 the card is set to one.
    faceHolder = 'A'; //set it to be "A"
    if(Player1.return_count() < 11){ //if the count is less than 11
        cardValue = 11; //return 11
    }
    else{ //if the count is not less than 11
        cardValue = 1; //return 1
    }
}

//prevents same card to be drawn.
for(int i = 0; i < count; i ++) { //a for loop
    while((usedsuits[i] == suitCard && usedvalues[i] == cardValue) || cardValue <= 0) { //if the number satisfies all this condition, quit the loop
        suitCard = rand() % 4; //calculate the card number
        cardValue = rand() % 13; //calculate the card number
        if(cardValue == 10) { //if the value is 10
            faceHolder = Jack; //set it to be Jack
        }
        else if(cardValue == 11) { //if the value is 11
            faceHolder = Queen; //set it to be Queen
            cardValue = 10; //return 10
        }
        else if(cardValue == 12) { //if the value is 12
            faceHolder = King; //set it to be King
            cardValue = 10; //return 10
        }
        else{  //if the value is not 10, 11 or 12
            faceHolder = '\0'; //print out faceFolder
        }
    }
//Player1.draw(cardValue);
//place cards in used pile. Both suit and card value.
}
usedsuits[count] = suitCard; //initialize variable
usedvalues[count] = cardValue; //initialize variable
count++; //renew count
playerValue = Player1.draw(cardValue); //initialize variable


if(faceHolder){ //if the number is in the faceHolder
    cout << faceHolder << " of " << suits[suitCard] << "\tTotal value : " << playerValue << '\n'; //print out the card
    }
else{ //if the number is not in the faceHolder   
    cout << value[cardValue]-1 << " of "<< suits[suitCard] << "\tTotal value : " << playerValue << '\n'; //print out the card
    }
faceHolder = '\0'; //print out faceFolder

if(playerValue > 21){ //if value is larger than 21
    cout << "Bust! you went over 21. You lost " << bet << " chips.\n"; //tell the user he loses
    Player1.coin_Change(-bet); //call the funtcion
    Player1.return_zero(); //call the funtcion
    boolean = false; //return false
    
    for(int i = 0; i < 10; i++){ //a for loop
    usedsuits[i] = 0; //set the element at ith place to be 0
    usedvalues[i] = 0; //set the element at ith place to be 0
}
}
}


if(choice == 2) { //if the choice is 2
std::cout << "\x1B[2J\x1B[H"; // refresh the screen.
cout << "House is drawing...\n"; //print out things
do {
int suitCard = rand() % 4; //calculate the card number
int cardValue = rand() % 13; //calculate the card number

if(cardValue == 10) { //if the value is 10
 faceHolder = Jack; //return Jack
}
else if(cardValue == 11) { //if the value is 11
    faceHolder = Queen; //return Queen
    cardValue = 10; //return 10
}
else if(cardValue == 12) { //if the value is 12
faceHolder = King; //return King
cardValue = 10; //return 10
}
else if(cardValue == 1) { // Rules for Aces, Aces are counted as either 11 or 1 depending on the player's total value. If the player's hand total is 
                          // less than (possibly) 21, the ace is automatically defaulted to 11. However, if the total is (possibly) over 21 the card is set to one.
    faceHolder = 'A'; //set it to be "A"
    if(House.return_count() < 11){ //if it is less than 11
        cardValue = 11; //return 11
    }
    else{ //if it is not less than 11
        cardValue = 1; //return 1
    }
}

//prevents same card from drawing multiple times.
for(int i = 0; i < count; i ++) { //a for loop
    while((usedsuits[i] == suitCard && usedvalues[i] == cardValue) || cardValue == 0) { //if the number satisfies all this condition, quit the loop
        suitCard = rand() % 4; //calculate the card number
        cardValue = rand() % 13; //calculate the card number
    }
 }
 
usedsuits[count] = suitCard; //initialize variable
usedvalues[count] = cardValue; //initialize variable
houseValue = House.draw(cardValue); //initialize variable and call the function
count++; //renew count
 
 if(faceHolder){ //if the number is in the faceHolder
    cout << faceHolder << " of " << suits[suitCard] << '\n'; //print out the card
    }
else{ //if the number is not in the faceHolder   
    cout << value[cardValue]-1 << " of "<< suits[suitCard] << '\n'; //print out the card
    }
    faceHolder = '\0'; //print out the faceHolder
} while(houseValue < playerValue); //if satisfies this condition, quit the loop
cout << "Total value: " << houseValue << '\n'; //print out the total value


//winning condition.
if((playerValue <= 21 && playerValue > houseValue) || houseValue > 21){ //if the value is less than 22
    cout << "You won the hand, " << "Payout of " << bet << " chips\n"; //tell the player that he wins the game
    Player1.coin_Change(bet); //call the funtion
 }
 else{ //if the value is not less than 22
     cout << "You lost the hand..."; //tell the player that he loses the game
     Player1.coin_Change(-bet); //call the funtion
 }
 cout << "You have " << Player1.return_coins() << " chips\n"; // tell the player how many coins he has
boolean = false; //set it to be false
Player1.return_zero(); //call the funtion 
House.return_zero(); //call the funtion
count = 1;
for(int i = 0; i < 10;i++){ //a for loop
    usedsuits[i] = 0; //return 0
    usedvalues[i] = 0; //return 0
}
}


if(choice == 3){ //if the choice is 3
    cout << "Congratulations!, You walked away with " << Player1.return_coins() << " Chips\n"; //tell the player that he wins
    return; //return
}
 

}while (Player1.return_coins() != 0 || House.return_coins() != 0 || Player1.return_coins() >= 25000); //call the function, if satisfies this, quit the loop
cout << "Congradulations! you Won!"; // messages the player they won.
}

void Executive_Black_Jack::printMenu(){ //print out the menu
    cout << "What would you like to do?:\n"; //print out the menu
    cout << "1) Draw\n"; //print out the menu
    cout << "2) Stay\n"; //print out the menu
    cout << "3) cash out (end game)\n"; //print out the menu
}