#ifndef PIGDICE_TURN_H
#define PIGDICE_TURN_H

// Caleb Knickerbocker

#include "die.h"

class PigDiceGame;

class Turn
{
private:
    int m_turnCount;
    int m_scoreThisTurn;
    bool m_turnOver;
    char m_choice;
    Die m_myDie;
    PigDiceGame* m_parentGame=nullptr;

public:
    // Default constructor
    Turn();

    void setParentGame(PigDiceGame* parentGame);
    void takeTurn(bool showTurnInfo = true);
    int getScoreThisTurn() const;
    void resetTurnOver();
    int getTurnCount();
    void resetScoreThisTurn();

private:
    void roll();
};

#endif