//Player.h
#ifndef PLAYER_H
#define PLAYER_H
using namespace std;

class Player {

private:
int count = 0; //initialize variable
int m_Coins; //initialize variable


public:
/**
    *@pre: none
    *@post: returns a new int
    *@param: none
    *@throw: none
*/
Player();

int draw(int n);//int countHand();

/**
    *@pre: none
    *@post: returns 0 for the count
    *@param: none
    *@throw: none
*/
void return_zero();

/**
    *@pre: none
    *@post: set coin to be n
    *@param: none
    *@throw: none
*/
void set_Coins(int n);

/**
    *@pre: none
    *@post: returns count
    *@param: none
    *@throw: none
*/
int return_count();

/**
    *@pre: none
    *@post: returns coins to be 0
    *@param: none
    *@throw: none
*/
int return_coins();

/**
    *@pre: none
    *@post: returns coins to be coins plus n
    *@param: none
    *@throw: none
*/
void coin_Change(int n); //changes the amount of coins the player has. add or subtract.

};
#endif