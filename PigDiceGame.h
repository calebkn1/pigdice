#ifndef PIGDICE_PIGDICEGAME_H
#define PIGDICE_PIGDICEGAME_H

// Caleb Knickerbocker

#include "Turn.h"

class PigDiceGame
{
protected:
    Turn m_myTurn;
    bool m_gameOver;
    int m_gameScore;

public:
    PigDiceGame();

    int getGameScore() const;

protected:
    void displayRules();
    void playGame();
};

#endif