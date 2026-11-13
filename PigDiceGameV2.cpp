#include "PigDiceGameV2.h"
#include <iostream> // Caleb Knickerbocker

// Constructor
PigDiceGameV2::PigDiceGameV2(std::string playerName)
{
    m_playerName=playerName;
}

// Returns the player's name
std::string PigDiceGameV2::getPlayerName() const
{
    return m_playerName;
}

// Displays multiplayer rules
void PigDiceGameV2::displayRules()
{
    std::cout<<"Let's Play PIG Dice!"<<std::endl;
    std::cout<<std::endl;

    std::cout<<"* See which player will reach 50 points in the fewest turns."<<std::endl;
    std::cout<<"* Turn ends when you hold or roll a 1."<<std::endl;
    std::cout<<"* If you roll a 1, you lose all points for the turn."<<std::endl;
    std::cout<<"* If you hold, you save all points for the turn."<<std::endl;
    std::cout<<std::endl;
}

// Plays one player's turn
void PigDiceGameV2::playGame()
{
    std::cout<<"\n"<<m_playerName;
    std::cout<<" (Score:"<<m_gameScore<<")";
    std::cout<<" - TURN "<<m_myTurn.getTurnCount()+1;

    m_myTurn.takeTurn(false);

    m_gameScore+=m_myTurn.getScoreThisTurn();

    m_myTurn.resetTurnOver();
    m_myTurn.resetScoreThisTurn();
}

// Resets the parent game pointer
void PigDiceGameV2::resetParentGame()
{
    m_myTurn.setParentGame(this);
}