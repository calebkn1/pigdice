#include <iostream>
#include "Turn.h"
#include "PigDiceGame.h" // Caleb Knickerbocker

// Default constructor
Turn::Turn()
{
    m_turnCount = 0;
    m_scoreThisTurn = 0;
    m_turnOver = false;
    m_choice = '\0';
}

// Sets the parent game
void Turn::setParentGame(PigDiceGame* parentGame)
{
    m_parentGame = parentGame;
}

// Handles a player's turn
void Turn::takeTurn(bool showTurnInfo)
{
    m_turnCount++;

    if(showTurnInfo)
    {
        std::cout<<"\n\nTurn "<<m_turnCount;
        std::cout<<" - Game Score: "<<m_parentGame->getGameScore();
    }

    while(!m_turnOver)
    {
        std::cout<<"\nRoll or Hold? (r/h): ";
        std::cin>>m_choice;

        if(m_choice=='r')
        {
            roll();
        }
        else if(m_choice=='h')
        {
            m_turnOver = true;
        }
        else
        {
            std::cout<<"Invalid choice!";
        }
    }

    std::cout<<"\nScore Banked This Turn: "<<m_scoreThisTurn<<std::endl;
}

// Returns the score for the turn
int Turn::getScoreThisTurn() const
{
    return m_scoreThisTurn;
}

// Resets the turn
void Turn::resetTurnOver()
{
    m_turnOver = false;
}

// Returns total turns played
int Turn::getTurnCount()
{
    return m_turnCount;
}

// Resets the turn score
void Turn::resetScoreThisTurn()
{
    m_scoreThisTurn=0;
}

// Rolls the die
void Turn::roll()
{
    m_myDie.rollDie();
    std::cout<<"Die: "<<m_myDie.getDieValue();

    if(m_myDie.getDieValue()==1)
    {
        std::cout<<"\nTurn over. No score.\n";
        m_scoreThisTurn=0;
        m_turnOver=true;
    }
    else
    {
        m_scoreThisTurn+=m_myDie.getDieValue();
        std::cout<<" - Running score this turn: "<<m_scoreThisTurn;
    }
}