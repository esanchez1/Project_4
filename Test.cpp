#include "Test.h"
#include "hangman.h"
#include "tictacto.h"
#include "Trivia.h"
#include "Executive_Black_Jack.h"
#include "Player.h"
void Test:: run() //run the test
{
	cout << "\nRunning tests for Hangman...\n\n"; //print out the test for the game
	test1(); //test 1
	test2(); //test 2
    test3(); //test 3
	test4(); //test 4
	test5(); //test 5
    cout << "\nRunning tests for Trivia...\n\n"; //print out the test for the game
    test6(); //test 6
    test7(); //test 7
	test8(); //test 8
	test9(); //test 9
	test10(); //test 10
	test11(); //test 11

	cout << "\nRunning tests for Tic-Tac-Toe...\n\n"; //print out the test for the game
	test12(); //test 12
	test13(); //test 13
	test14(); //test 14
	cout <<"\n Running tests for Blackjack...\n\n"; //print out the test for the game
	test15(); //test 15
	test16(); //test 16
	test17(); //test 17
	test18(); //test 18
	test19(); //test 19
}

void Test:: test1()//test 1
{	
	hangman obj; //create a node
	
	cout<< "Test 1 : Guessing the wrong letter more than 5 times causes player to lose: "; //test 1
	if(obj.funcForWrongGuess(6)) //if passed
	{
		cout<< "PASSED\n"; //print out passed
	}	
	else{ //not passed
		cout<< "FAILED\n"; //print out failed
	}
	
}

void Test:: test2(){ //test 2
	hangman obj; //create a node

	cout<< "Test 2 : Guessing the wrong letter less than 5 times causes player does not cause player to lose: "; //test 2
	if(obj.funcForWrongGuess(3)) //not passed
	{
		cout<< "FAILED\n"; //print out failed
	}	
	else{ //if passed
		cout<< "PASSED\n"; //print out passed
	}


}
void Test:: test3() //test 3
{
	hangman obj; //create a node
	cout << "Test 3 : Words are randomly generated: "; //test 3
	string randomWord = obj.randomlyGenerateWord(); //initialize string
	if(randomWord.length() >0) //if passed
	{
		cout << "PASSED\n"; //print out passed
	}
	else{ //not passed
		cout << "FAILED\n"; //print out failed
	}

}
void Test:: test4() //test 4
{
	hangman obj; //create a node
	cout << "Test 4: Guessing with the correct input returns true: "; //test 4
	if(obj.charchecker('a') == true) //if passed
	{
		cout << "PASSED\n"; //print out passed
	}
	else{ //not passed
		cout << "FAILED\n"; //print out failed
	}
}
void Test:: test5() //test 5
{
	hangman obj; //create a node
	cout << "Test 5: Guessing with the wrong input returns false: "; //test 5
	if(obj.charchecker('A') == false) //if passed
	{
		cout << "PASSED\n"; //print out passed
	}
	else{ //not passed
		cout << "FAILED\n"; //print out failed
	}

}
void Test:: test6(){ //test 6
    Trivia testObj; //create a node
	cout<< "Test 6 : Giving the wrong answer to a question in the general knowledge trivia returns a false: "; //test 6
	if(testObj.checkAns(3, "General Knowledge", "kilobyte")== true) //not passed
	{
		cout<< "FAILED\n"; //print out failed
	}
	else{ //if passed
		cout<< "PASSED\n"; //print out passed
	}
}



void Test:: test7() //test 7
{
	Trivia testObj; //create a node
	cout<< "Test 7 : Answering 7 out of 7 questions right on any trivia, causes a player to win: "; //test 7
	if(testObj.checkWin(7, 1,1) && testObj.checkWin(7, 2,1 ) && testObj.checkWin(7, 3,1)) //if passed
	{
		cout << "PASSED\n"; //print out passed
	}
	else
	{ //not passed
		cout<< " FAILED\n"; //print out failed
	}
}
void Test:: test8() //test 8
{
	Trivia testObj; //create a node
	cout << "Test 8 : Answering less than 5 questions correct causes a player to lose: "; //test 8
	if(testObj.checkWin(4, 1,1) && testObj.checkWin(4, 2,1 ) && testObj.checkWin(4, 3,1)) //not passed
	{
		cout << "FAILED\n"; //print out failed
	}
	else //if passed
	{
		cout<< " PASSED\n"; //print out passed
	}
}
void Test::test9() //tset 9
{
	Trivia testObj; //create a node
	cout<< "Test 9 : Giving the Right answer to a question in the general knowledge trivia returns a true: "; //test 9
	if(testObj.checkAns(0, "General Knowledge", "cancer")== true) //if passed
	{
		cout<< "PASSED\n"; //print out passed
	}
	else{ //not passed
		cout<< "FAILED\n"; //print out failed
	}
	
}
void Test:: test10() //test 10
{
	Trivia testObj; //create a node
	cout<< "Test 10 : Giving the Right answer to a question in pop Culture trivia returns a true: ";// test 10
	if(testObj.checkAns(0, "Pop Culture", "smh")== true) //if passed
	{
		cout<< "PASSED\n"; //print out passed
	}
	else{ //not passed
		cout<< "FAILED\n"; //print out failed
	}

}
void Test:: test11() //test 11
{
	Trivia testObj; //create a node
	cout<< "Test 11 : Giving the Right answer to a question in Computer Science trivia returns a true: ";//test 11
	if(testObj.checkAns(0, "Computer Science", "kilobyte")== true) //if passed
	{
		cout<< "PASSED\n"; //print out passed
	}
	else{ //not passed
		cout<< "FAILED\n"; //print out failed
	}
}
void Test:: test12()
{
	tictacto obj; //create a node
	bool sameBoard= 0; //initialize the variable
	
	char testBoard[3][3]={{' ',' ', ' '}, 
                  {' ',' ', ' '}, 
                  {' ',' ', ' '}};; //initialize the board
	
	cout<< "Test 12: When game starts, board gets initialized to empty:"; //test 12
	for(int i = 0; i < 3; i++) //a for loop
	{
		for(int j= 0; j< 3; j++) //a for loop
		{
			if(testBoard[i][j]== obj.board[i][j]) //check if the test is passed or not
			{
				sameBoard = 1; //return 1
			}
			else{
				sameBoard = 0; //return 0
			}

		}

	}
	if(sameBoard== 1) //if the variable is 1
	{
		cout<< " PASSED\n"; //print out passed
	}
	else{ //not passed
		cout << "FAILED\n"; //print out failed
	}
}
void Test:: test13() //test 13
{
	tictacto obj; //create a node
	cout << "Test 13: After Player 1's turn ends, it is Player 2's turn: "; //tset 13
	if(obj.changePlayer(1)== 2) //if passed
	{
		cout << "PASSED\n"; //print out passed
	}
	else{ //not passed
		cout<<"FAILED\n"; //print out failed
	}
}
void Test:: test14() //tset 14
{
	tictacto obj; //create a node
	
	cout<< "Test 14: When there are three X's going horizontally, player 2 wins:"; //tset 14
	obj.board[0][2] = 'X'; //at row 0 and col 2, place an "x"
	obj.board[1][2] = 'X'; //at row 1 and col 2, place an "x"
	obj.board[2][2] = 'X'; //at row 2 and col 2, place an "x"
	obj.winningcondition(); //call the function
	if(obj.flag2 == true) //if passed
	{
		
		cout<< " PASSED\n"; //print out passed
	}
	else{ //not passed
		cout << "FAILED\n"; //print out failed
	}
}
// display stick figure
void Test:: test15() //test 15
{
	Player obj; //create a node
	obj.set_Coins(500); //call the function
	cout << "Test 15: setting coins to 500, initializes the coins to 500 : "; //test 15
	if(obj.return_coins() == 500) //if passed
	{
		cout<< "PASSED\n"; //print out passed
	}
	else{ //not passed
		cout << "FAILED\n"; //print out failed
	}
}
void Test:: test16() //test 16
{
	Player obj; //create a node
	obj.set_Coins(50); //call the function
	obj.coin_Change(40); //call the function
	cout << "Test 16: If player originally has 50 coins and then wins 40 more, the player has a total of 90 coins: "; //test 16
	if(obj.return_coins() == 90) //if passed
	{
		cout << "PASSED\n"; //print out passed
	}
	else{ //not passed
		cout<< "FAILED\n"; //print out failed
	}
}
void Test:: test17() //test 17
{
	Player obj; //create a node
	obj.set_Coins(500); //call the function
	obj.coin_Change(-600); //call the function
	cout << "Test 17: If player originally has 500 coins and then loses 600 coins, the player has a total of -100 coins: "; //test 17
	if(obj.return_coins() == -100) //if passed
	{
		cout << "PASSED\n"; //print out passed
	}
	else{ //not passed
		cout<< "FAILED\n"; //print out failed
	}
}
void Test:: test18() //test 18
{
	Player obj; //create a node
	cout << "Test 18: Drawing 50 returns the number 50: "; //test 18
	if(obj.draw(50) == 50) //if passed
	{
		cout << "PASSED\n"; //print out passed
	}
	else{ //not passed
		cout << "FAILED\n"; //print out failed
	}
}
void Test:: test19() //test 19
{
	Player obj; //create a node
	cout << "Test 19: Drawing 50 and then drawing 100 returns the addition of the two numbers (150): "; //test 19
	int total = obj.draw(50); //call the function
	total = obj.draw(100);
	if(total == 150) //if pas //call the functionsed
	{
		cout << "PASSED\n"; //print out passed
	}
	else{ //not passed
		cout << "FAILED\n"; //print out failed
	}
}
