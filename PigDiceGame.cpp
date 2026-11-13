#include "PigDiceGame.h"

#include <iostream>     // Caleb Knickerbocker
#include <ostream>

// Default constructor
PigDiceGame::PigDiceGame()
{
    m_gameOver=false;
    m_gameScore=0;
    m_myTurn.setParentGame(this);
}

// Returns the game score
int PigDiceGame::getGameScore() const
{
    return m_gameScore;
}

// Starts single-player mode
void PigDiceGame::playSinglePlayerGame()
{
    displayRules();
    playGame();
}

// Displays the game rules
void PigDiceGame::displayRules()
{
    std::cout << "Let's Play PIG Dice!" << std::endl;
    std::cout << std::endl;

    std::cout << "* See how many turns it takes you to get to 20 points." << std::endl;
    std::cout << "* Turn ends when you hold or roll a 1." << std::endl;
    std::cout << "* If you roll a 1, you lose all points for the turn." << std::endl;
    std::cout << "* If you hold, you bank all points for the turn to the game score." << std::endl;
}

// Runs the single-player game
void PigDiceGame::playGame()
{
    while(!m_gameOver)
    {
        m_myTurn.takeTurn();
        m_gameScore+=m_myTurn.getScoreThisTurn();

        if(m_gameScore>=20)
        {
            m_gameOver=true;
        }
        else
        {
            m_myTurn.resetTurnOver();
            m_myTurn.resetScoreThisTurn();
        }
    }

    std::cout<<"\nYou finished with a final score of ";
    std::cout<<m_gameScore;
    std::cout<<" in " <<m_myTurn.getTurnCount()<<" turns!";
    std::cout<<"\nThanks for playing PIG Dice!"<<std::endl;
}