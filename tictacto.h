//tictacto.h
//hangman.h
#ifndef TICTACTO_H
#define TICTACTO_H
#include <iostream>
using namespace std;


class tictacto {

public:
bool flag1 = false; //set the flag 1 to be false
bool flag2 = false; //set the flag 2 to be false

/**
*@pre: none
*@post: displays tic-tac-toe board
*@param: none
*@throw: none 
*/
bool Board(bool test);

/**
*@pre: none
*@post: prompts player 1 for a row and column they wish to place an O at until they give a valid row and column number
*@param: none
*@throw: none 
*/
void player(int player);

/**
*@pre: none
*@post: prompts player 2 for a row and column they wish to place an X at until they give a valid row and column number
*@param: none
*@throw: none 
*/
void player2();

/**
 *@pre row and col is chosen and executes after each player's turn.
 *@post sets a flag true if winning conditions are met.
 *@param None
 *@throw None
 */
void winningcondition();

/**
 *@pre Board is generated.
 *@post alternates between player 1 and player 2 choosing coordinates.
 *@param None
 *@throw None
 */
void begin();

/**
 *@pre Board is generated.
 *@post handles the winning condition flags and couts the winner.
 *@param None
 *@throw None
 */
void run();
int changePlayer(int currentPlayer);

char board[3][3]={{' ',' ', ' '},
                  {' ',' ', ' '}, 
                  {' ',' ', ' '}};;

};
#endif


