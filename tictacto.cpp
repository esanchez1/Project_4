#include <iostream>
#include "tictacto.h"
using namespace std;



bool tictacto::Board(bool test) //print out the board
{  
    if(test == 0)// if the test is 0
    {
         cout << "1   2   3" << endl; //print out the board
        for(int i = 0; i < 3; i++) //a for loop
        {
            for(int j = 0; j < 3; j++) //a for loop
            {
                cout << board[i][j]; //print out the board
                if(j == 0) //if col is 0
                {
                    cout << " | "; //print out the board
                }
                if(j == 1) //if col is 1
                {
                    cout << " | "; //print out the board
                }
                if(j == 2) //if col is 2
                {
                    cout << "  " << i + 1 << endl; //print out the board
                }
            }
            if(i == 0) //if row is 0
            {
                cout << "----------" << endl; //print out the board
            }
            if(i == 1) //if row is 1
            {
                cout << "----------" << endl; //print out the board
            }
        }
        cout << endl; //turn to the next line
    }
   
    return true; //return true
}

void tictacto::player(int playerNum) //change player
{
    int row1; //initialize variable
    int col1; //initialize variable
    for( ; ; ) //a for loop
    {
        cout << "Enter a row: "; //print out the board
        if(cin >> row1) //if get the cin correctly
        {               
            break; //get out of the break
        }                 
        else //if do not get the cin correctly                 
        {
            cin.clear(); //clear the input
            cin.ignore(); //ignore the input       
            cout << "Invalid input, please enter again!" << endl; //ask the user to put again
            row1 = 0; //initialize variable          
        }      
    }

    for( ; ; ) //a for loop
    {
        cout << "Enter a col: ";
        if(cin >> col1 && col1 >= 1 && col1 <= 3) //if get the cin correctly
        {                     
            break; //get out of the break
        }                 
        else //if do not get the cin correctly                  
        {
            cin.clear(); //clear the input
            cin.ignore(); //ignore the input          
            cout << "Invalid input, please enter again!" << endl; //ask the user to put again
            col1 = 0; //initialize variable          
        }
          
    }
    
    while(board[row1 - 1][col1 - 1] != ' ') //if the grid is already has been placed
    {
        cout << "Invalid input, please enter again!" << endl; //ask the user to put again
        cout << "Enter a row: "; //ask for a row
        cin >> row1; //get the row
        cout << "Enter a col: "; //ask for a col
        cin >> col1; //get the col
    }
    if(playerNum == 1) //if is player 1
    {   
         board[row1 - 1][col1 - 1] = 'O'; //player 1's pattern is "O"
    }
    else{ //if is player 2
         board[row1 - 1][col1 - 1] = 'X'; //player 1's pattern is "X"
    }
}

void tictacto::winningcondition() //condition to win
{
    for(int i = 0; i < 3; i++) //a for loop
    {
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][1] == board[i][2] && board[i][0] != ' ') //condition to win 
        {
            if(board[i][0] == 'O') //player 1's winning condition
            {
                flag1 = true; //return true
            }
            else //player 2's winning condition
            {
                flag2 = true; //return true
            }
        }
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] == board[2][i] && board[0][i] != ' ') //condition to win
        {
            if(board[0][i] == 'O') //player 1's winning condition
            {
                flag1 = true; //return true
            }
            else //player 2's winning condition
            {
                flag2 = true; //return true
            }
        }
        if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] == board[2][0] && board[2][0] != ' ') //condition to win
        {
            if(board[1][1] == 'O') //player 1's winning condition
            {
                flag1 = true; //return true
            }
            else //player 2's winning condition
            {
                flag2 = true; //return true
            }
        }
        if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == board[2][2] && board[0][0] != ' ') //condition to win
        {
            if(board[1][1] == 'O') //player 1's winning condition
            {
                flag1 = true; //return true
            }
            else //player 2's winning condition
            {
                flag2 = true; //return true
            }
        }
    }
}
int tictacto:: changePlayer(int currentPlayer) //change the player
{
    if(currentPlayer == 1) //if is player1
    {
        currentPlayer = 2; //turn the player from 1 to 2
        return currentPlayer; //return current player
    }
    else{ //if is player2
        return 1; //return 1
    }
}

void tictacto::begin() //begin games
{
    int num = 0; //initialize variable
    bool flag = false; //set the flag to be false
    int currentPlayer = 1; //initialize variable
    while(num < 9 && flag1 == false && flag2 == false) //chenk if it is valid or not
    {
        if(flag == false) //if the flag is false
        {
            currentPlayer = changePlayer(2); //change player
            cout << "It's player"<< currentPlayer << "'s turn now!" << endl; //tell players that who's turn is it now
            player(1); //call the function
            flag = true; //return true
        }
        else //if the flag is true
        {
            currentPlayer = changePlayer(1); //change player
            cout << "It's player" <<currentPlayer<<"'s turn now!" << endl; //tell players that who's turn is it now
            player(2); //call the function
            flag = false; //return false
        }
        winningcondition(); //call the function
        Board(0); //call the function
        num = num + 1; //renew num
    }
}

void tictacto::run() //run the game
{
    Board(0); //call the function
    begin(); //call the function
    if(flag1 == true) //if flag 1 is true
    {
        cout << "player1 wins!" << endl; //tell players that player 1 wins the game
        flag1 = false; //return false
    }
    else if(flag2 == true) //if flag 2 is true
    {
        cout << "player2 wins!" << endl; //tell players that player 2 wins the game
        flag2 = false; //return false
    }
    else if(flag1 == flag2) //if two flags are equal
    {
        cout << "No one wins!" << endl; //tell players that no one wins the game
    }

}
