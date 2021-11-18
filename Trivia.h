#ifndef TRIVIA_H
#define TRIVIA_H
#include <string>
using namespace std;
class Trivia{
	
	private:
    /**
    *@pre: none
    *@post: returns answers
    *@param: none
    *@throw: none
    */
	void generalKnowledgeTrivia();

    /**
    *@pre: none
    *@post: returns answers
    *@param: none
    *@throw: none
    */
	void computerScienceTrivia();

    /**
    *@pre: none
    *@post: returns answers
    *@param: none
    *@throw: none
    */
	void popCultureTrivia();

    /**
    *@pre: none
    *@post: initialize arrays
    *@param: none
    *@throw: none
    */
    void initializegeneralKnowledgeArray();

    /**
    *@pre: none
    *@post: initialize arrays
    *@param: none
    *@throw: none
    */
    void initializePopCultureArray();

    /**
    *@pre: none
    *@post: initialize arrays
    *@param: none
    *@throw: none
    */
    void initializeCompScienceArray();

	
	public:
	Trivia();
	void run();
    string generalKnowledgeArray[7]; //initialize string
    string generalKnowledgeAnsArray[7]; //initialize string
    string popCultureArray[7]; //initialize string
	string popCultureAnsArray[7]; //initialize string
    string compScienceAnsArray[7]; //initialize string

    string compScienceArray[7]; //initialize string

    /**
    *@pre: none
    *@post: check answers
    *@param: none
    *@throw: none
    */
    bool checkAns(int questionNum, string category, string answer);

    /**
    *@pre: none
    *@post: check who wins the game
    *@param: none
    *@throw: none
    */
	bool checkWin(int triviaPoints, int game, bool test);

    
};

#endif