#ifndef PIGDICE_MULTIPLAYER_H
#define PIGDICE_MULTIPLAYER_H

// Caleb Knickerbocker

#include "PigDiceGameV2.h"
#include <vector>

class MultiPlayer
{
private:
    std::vector<PigDiceGameV2> m_players;
    bool m_gameOver;

public:
    // Default constructor
    MultiPlayer();

    void mPlayGame();

private:
    void displayScoreBoard();
    void checkForWinner();
};

#endif