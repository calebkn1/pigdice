#ifndef PIGDICE_PIGDICEGAME_H
#define PIGDICE_PIGDICEGAME_H

#include "Turn.h"

class PigDiceGame
{
private:
    Turn m_myTurn;
    bool m_gameOver;
    int m_gameScore;

public:
    PigDiceGame();
    int getGameScore() const;

private:
    void displayRules();
    void playGame();
};

#endif